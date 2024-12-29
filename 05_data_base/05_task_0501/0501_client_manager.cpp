#include <iostream>
#include <sstream>
#include "0501_client_manager.h"

Manager::Manager(const std::string& db_connection_string) : m_connection(db_connection_string) {}

void Manager::CreateTable() {
  pqxx::work txn(m_connection);
  txn.exec(R"(
    CREATE TABLE IF NOT EXISTS clients (
      id SERIAL PRIMARY KEY,
      name TEXT,
      family_name TEXT,
      email TEXT UNIQUE,
      phones TEXT[]
    )
  )");
  txn.commit();
  std::cout << "—труктура базы данных клиентов успешно создана!" << std::endl;
}

void Manager::AddClient(const Client& client) {
  pqxx::work txn(m_connection);

  std::string phones = "{";
  for (size_t i = 0; i < client.phones.size(); i++) {
    phones += client.phones[i];
    if (i != client.phones.size() - 1) {
      phones += ",";
    }
  }
  phones += "}";
        
  pqxx::result res = txn.exec_params(R"(
    INSERT INTO clients (name, family_name, email, phones)
    VALUES ($1, $2, $3, $4) RETURNING id)",
    client.name, client.family_name, client.email, phones);
  txn.commit();
}

void Manager::AddPhone(const std::string& email, const std::string& phone) {
  pqxx::work txn(m_connection);
  txn.exec_params(R"(
    UPDATE clients SET phones = array_append(phones, $1) 
    WHERE email = $2)", phone, email);
  txn.commit();
}

void Manager::DeletePhone(const std::string& email, const std::string& phone) {
  pqxx::work txn(m_connection);
  txn.exec_params(R"(
    UPDATE clients SET phones = array_remove(phones, $1) 
    WHERE email = $2)", phone, email);
  txn.commit();
}

void Manager::DeleteClient(const std::string& email) {
  pqxx::work txn(m_connection);
  txn.exec_params("DELETE FROM clients WHERE email = $1", email);
  txn.commit();
}

void Manager::UpdateClient(const std::string& email, const std::string& new_email, 
  const std::string& new_name, const std::string& new_family_name) {
  pqxx::work txn(m_connection);
  txn.exec_params(R"(
    UPDATE clients SET email = $1, name = $2, family_name = $3 
    WHERE email = $4)", new_email, new_name, new_family_name, email);
  txn.commit();
}

std::vector<Client> Manager::FindClients(const std::string& search_query) {
  std::vector<Client> results;
  pqxx::work txn(m_connection);
  pqxx::result res = txn.exec_params(R"(
    SELECT id, name, family_name, email, phones FROM clients
    WHERE email = $1 OR name = $1 OR family_name = $1)", search_query);
  txn.commit();

  for (const auto& row : res) {
    Client client;
    client.name = row["name"].as<std::string>();
    client.family_name = row["family_name"].as<std::string>();
    client.email = row["email"].as<std::string>();
    std::stringstream ss(row["phones"].as<std::string>());
    std::string phone;
    while (std::getline(ss, phone, ',')) {
      client.phones.push_back(phone);
    }
    results.push_back(client);
  }
  return results;
}

void ShowFoundClients(std::vector<Client> found_clients) {
  for (const auto& client : found_clients) {
    std::cout << client.name << " " << client.family_name << "\t" << client.email << "\t";
    std::string phone_str;
    std::string delete_chars = "{}\"'";
    for (const auto& phone : client.phones) {
      if (client.phones.back() == phone) {
        phone_str += phone;
      }
      else {
        phone_str += phone;
        phone_str += ", ";
      }
    }
    for (char c : delete_chars) {
      phone_str.erase(std::remove(phone_str.begin(), phone_str.end(), c), phone_str.end());
    }
    std::cout << phone_str << std::endl;
  }

  std::cout << std::endl;
}
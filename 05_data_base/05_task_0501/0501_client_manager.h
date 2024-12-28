#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <pqxx/pqxx>

#pragma execution_character_set("utf-8")

struct Client {
  std::string name;
  std::string family_name;
  std::string email;
  std::vector<std::string> phones;
};

class Manager {
  private:
    pqxx::connection connection;

  public:
    Manager(const std::string& db_connection_string);

    void CreateTable();
    void AddClient(const Client& client);
    void AddPhone(const std::string& email, const std::string& phone);
    void DeletePhone(const std::string& email, const std::string& phone);
    void DeleteClient(const std::string& email);
    void UpdateClient(const std::string& email, const std::string& new_email, 
                      const std::string& new_first_name, const std::string& new_last_name);
    std::vector<Client> FindClients(const std::string& search_query);

};

void ShowFoundClients(std::vector<Client> found_clients);
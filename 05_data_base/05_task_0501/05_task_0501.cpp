#include <iostream>
#include <Windows.h>
#include "0501_client_manager.h"

int main() {
  SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);

  std::string db_connection_string = 
    "host=localhost "
    "port=5432 " 
    "dbname=05_task_0501 " 
    "user=postgres " 
    "password=03122008";

  try {
    Manager manager(db_connection_string);
    manager.CreateTable();
    
    Client client_1 = { "����", "������", "ivan.ivanov@gmail.com", {"+7 (901) 111-22-33"} };
    manager.AddClient(client_1);
    std::cout << "+ ������ 1  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));
    
    manager.AddPhone("ivan.ivanov@gmail.com", "+7 (111) 111-11-11");
    std::cout << "+ ���. ������� 1  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));

    manager.DeletePhone("ivan.ivanov@gmail.com", "+7 (111) 111-11-11");
    std::cout << "- ���. ������� 1  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));

    manager.DeletePhone("ivan.ivanov@gmail.com", "+7 (901) 111-22-33");
    std::cout << "- ���. ������� 1  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));

    manager.AddPhone("ivan.ivanov@gmail.com", "+7 (123) 456-78-90");
    std::cout << "+ ���. ������� 1  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));

    manager.UpdateClient("ivan.ivanov@gmail.com", "ivanoff@gmail.com", "����", "��������");
    std::cout << "<-> �������� ������� 1  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));
    
    Client client_2 = { "����", "�������", "sergeev@gmail.com", {"+7 (903) 444-55-66"} };
    manager.AddClient(client_2);
    std::cout << "+ ������ 2  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));


    manager.DeleteClient("sergeev@gmail.com");
    std::cout << "- ������ 2  " << std::endl;
    ShowFoundClients(manager.FindClients("����"));
  }
  catch (const pqxx::broken_connection& e) {
    system("chcp 1251");
    system("cls");
    std::cerr << "Connection Error: " << e.what() << std::endl;
  }
  catch (const pqxx::sql_error& e) {
    std::cerr << "SQL Error: " << e.what() << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
};
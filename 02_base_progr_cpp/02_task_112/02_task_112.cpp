#include <iostream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#include "02_task_112_dll.h"

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  
  std::string name;

  Greeter stringName;

  std::cout << "¬ведите им€: ";

  std::cin >> name;

  std::cout << stringName.greet(name);

  return 0;
}

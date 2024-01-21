#include <iostream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  SetConsoleCP(1251);

  SetConsoleOutputCP(1251);
  
  std::string stringName;

  std::cout << "Введите имя: ";

  std::cin >> stringName;

  std::cout << "Здравствуйте, " << stringName << "!";

  return 0;
}

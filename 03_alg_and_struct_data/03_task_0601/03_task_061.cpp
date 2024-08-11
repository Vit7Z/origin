#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>

//-------------------------------------------------------------------------------------
int simple_string_hash(std::string stringForHash_)
{
  int hashString = 0;
  for (int i = 0; i < stringForHash_.length(); i++) {
    hashString = (int)stringForHash_[i] + hashString;
  }
  return hashString;
}

int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  std::string stringForHash = "begin";

  do {
    std::cout << "Введите строку: ";
    std::cin >> stringForHash;
    std::cout << "Наивный хэш строки " << stringForHash << " = " << simple_string_hash(stringForHash);
    std::cout << "\n";
  } while (stringForHash != "exit");

  return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>

//-------------------------------------------------------------------------------------
int CalculateHash(std::string stringForHash_, int p_, int n_)
{
  uint64_t sum = 0;
  uint64_t tmp = 0;
  int hashString = 0;

  for (int i = 0; i < stringForHash_.length(); i++) {
    tmp = (int)stringForHash_[i] * pow(p_, i);
    sum += tmp;
    hashString = (int)(sum % n_);
  }
  return hashString;
}

//
int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  std::string stringForHash = "begin";
  int p{ 1 };
  int n{ 1 };

  std::cout << "Введите p: ";
  std::cin >> p;

  std::cout << "Введите n: ";
  std::cin >> n;

  do {
    std::cout << "Введите строку: ";
    std::cin >> stringForHash;

    std::cout << "Хэш строки " << stringForHash << " = " << CalculateHash(stringForHash, p, n);
    std::cout << "\n";
  } while (stringForHash != "exit");

  return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#define SUB(a, b) ((a) - (b))

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int a = 6;

  int b = 5;

  int c = 2;

  std::cout << SUB(a, b) << std::endl;

  std::cout << SUB(a, b) * c << std::endl;

  std::cout << SUB(a, b + c) * c << std::endl;

  return 0;
}
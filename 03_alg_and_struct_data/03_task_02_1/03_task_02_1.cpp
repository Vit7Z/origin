#include <iostream>
#include <clocale>
#include <locale.h>
#include <windows.h>

unsigned long int calculateFibonacciNum(int i)
{
  if (i <= 1) {
    return i;
  }

  return calculateFibonacciNum(i - 1) + calculateFibonacciNum(i - 2);
}

int main(int argc, char** argv)

{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int itemNumber = 0;

  std::cout << "Введите число: ";

  std::cin >> itemNumber;

  std::cout << std::endl;

  std::cout << "Числа Фибоначчи:";

  for (int i = 0; i < itemNumber; i++) {
    std::cout << " " << calculateFibonacciNum(i);
  }

  std::cout << std::endl;

	return 0;
}

#include <iostream>

unsigned long int FibonacciNumber(int i)
{
  if (i <= 1)
    {
      return i;
    }

  return FibonacciNumber(i - 1) + FibonacciNumber(i - 2);
}

int main(int argc, char** argv)

{
  int ItemNumber = 0;

  std::cout << "Введите число: ";

  std::cin >> ItemNumber;

  std::cout << std::endl;

  std::cout << "Числа Фибоначчи:";

  for (int i = 0; i < ItemNumber; i++)
    {
      std::cout << " " << FibonacciNumber(i);
    }

  std::cout << std::endl;

	return 0;
}

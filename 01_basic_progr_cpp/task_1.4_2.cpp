#include <iostream>
#include <string>
#include <cmath>

int main() {

  long Sum = 0, Number = 0, Rem = 0;

  std::cout << "Введите целое число:" << " ";

  std::cin >> Number;

  Number = abs (Number);

   while (Number > 0)
  {
    Rem = Number % 10;

    Sum += Rem;

    Number /= 10;
  }

  std::cout << "Сумма цифр:" << " ";

  std::cout << Sum << std::endl;

}

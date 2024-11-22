#include <iostream>
#include <string>

int main() {

  int Sum = 0, Number = 1;

  while (0 != Number)
  {
    std::cout << "¬ведите целое число или число '0', чтобы закончить:\n";

    std::cin >> Number;

    Sum += Number;
}

  std::cout << "—умма: " << Sum;

}

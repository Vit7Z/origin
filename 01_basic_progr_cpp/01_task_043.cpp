#include <iostream>
#include <string>

int main() {

  long Number = 0;

  unsigned short i = 1;

  std::cout << "¬ведите целое число:" << " ";

  std::cin >> Number;

  std::cout << std::endl;

  while(i < 11)
    {
      std::cout << Number << " x " << i << " = " << Number * i << std::endl;

      i++;
    }
}

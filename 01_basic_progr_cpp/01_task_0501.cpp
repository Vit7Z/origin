#include <iostream>
#include <string>

int main() {

  int ArrInt[10] {-33, 66, 55, 44, 33, -11, 12, 1978, -77, 56789};

  unsigned short i;

  for (i = 0; i < 9 ;i++)
    {
      std::cout << ArrInt[i] << ", ";

    }

  std::cout << ArrInt[10];
}

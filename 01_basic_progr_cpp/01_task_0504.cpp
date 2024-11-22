#include <iostream>
#include <string>

int main() {

  int ArrInt [10] {-33, 66, 789356, 44, 33, -11, 12, 1978, -77, -67655};

  int Tmp = 0;

  unsigned short i;

  std::cout << "Массив до сортировки:" << " ";

  for (i = 0; i < 10 ;i++)
    {
      std::cout << ArrInt[i] << " ";
    }

  for (int i = 0; i < 10; i++) {

    for (int j = 0; j < 9; j++) {

      if (ArrInt[j] > ArrInt[j + 1])
        {
          Tmp = ArrInt[j];

          ArrInt[j] = ArrInt[j + 1];

          ArrInt[j + 1] = Tmp;
        }
    }
  }

  std::cout << std::endl;

    std::cout << "Массив после сортировки:" << " ";

  for (i = 0; i < 10 ;i++)
    {
      std::cout << ArrInt[i] << " ";
    }

  std::cout << std::endl;
}

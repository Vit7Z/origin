#include <iostream>
#include <string>

int main() {

  int ArrInt[10] {-33, 66, 789356, 44, 33, -11, 12, 1978, -77, -67655};

  int MinOfArrInt = 0;

  int MaxOfArrInt = 0;

  unsigned short i;

  std::cout << "������:" << " ";

  for (i = 0; i < 10 ;i++)
    {
      std::cout << ArrInt[i] << " ";

      MinOfArrInt = MinOfArrInt > ArrInt[i]
        ? MinOfArrInt = ArrInt[i]
        : MinOfArrInt;

      MaxOfArrInt = MaxOfArrInt < ArrInt[i]
        ? MaxOfArrInt = ArrInt[i]
        : MaxOfArrInt;
    }

  std::cout << std::endl;

  std::cout << "����������� �������: " << MinOfArrInt << std::endl;

  std::cout << "������������ �������: " << MaxOfArrInt << std::endl;
}

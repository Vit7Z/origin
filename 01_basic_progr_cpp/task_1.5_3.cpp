#include <iostream>
#include <string>

int main() {

  unsigned short size_i = 3;

  unsigned short size_j = 6;

  unsigned short i, j;

  unsigned short I_Of_Min = 0;

  unsigned short J_Of_Min = 0;

  unsigned short I_Of_Max = 0;

  unsigned short J_Of_Max = 0;

  int ArrInt[size_i] [size_j]
  {
    {-33, 66, 789356, 44, 33, -11},
    {-333, 766, 7893, 4410, 332, 1100},
    {22, 166, 0, 4544, 133, -911},
  };

  int MinOfArrInt = 0;

  int MaxOfArrInt = 0;

  std::cout << "Массив:" << std::endl;

  for (i = 0; i < size_i ;i++)
  {
    for (j = 0; j < size_j ;j++)
    {
      std::cout << ArrInt[i] [j] << "\t";

      if (MinOfArrInt > ArrInt[i] [j])
      {
        MinOfArrInt = ArrInt[i] [j];

        I_Of_Min = i;

        J_Of_Min = j;
      }

      if (MaxOfArrInt < ArrInt[i] [j])
      {
        MaxOfArrInt = ArrInt[i] [j];

        I_Of_Max = i;

        J_Of_Max = j;
      }
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  std::cout << "Минимальный элемент: " << MinOfArrInt << " " << "[" << I_Of_Min << "]" << "[" << J_Of_Min << "]" << std::endl;

  std::cout << "Максимальный элемент: " << MaxOfArrInt << " " << "[" << I_Of_Max << "]" << "[" << J_Of_Max << "]" << std::endl;

}

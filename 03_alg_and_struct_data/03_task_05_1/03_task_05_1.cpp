#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>

//-------------------------------------------------------------------------------------
void PrintArray(int* arr_, int size_arr_)
{
  std::cout << "Исходный массив: ";

  for (int i = 0; i < size_arr_; i++) {
    std::cout << arr_[i] << "\t";
  }
}

//-------------------------------------------------------------------------------------
void PrintArrayFromPyramid(int* arr_, int size_arr_) {
  std::cout << "\n";
  std::cout << "Џирамида:" << "\n";

  std::cout << "0 root " << arr_[0] << "\n";

  int i = 1;

  for (int k = 1; k <= (int)(std::log2(size_arr_)); k++) {

    int reptitions = pow(2, k);

    for (int j = 1; j <= reptitions && i < size_arr_; j++, i++) {
      int indexParent = (i - 1) / 2;

      if (i % 2 != 0) {
        std::cout << k << " " << "left (" << arr_[indexParent] << ") " << arr_[i] << "\n";
        } else {
      std::cout << k << " " << "right (" << arr_[indexParent] << ") " << arr_[i] << "\n";
      }
    }//for
  }//for
}

int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  //-------------------------------------------------------------------------------------
  int arrayInt_1[]{ 1, 3, 6, 5, 9, 8};
  int sizeArray = sizeof(arrayInt_1) / sizeof(arrayInt_1[0]);

  PrintArray(arrayInt_1, sizeArray);
  PrintArrayFromPyramid(arrayInt_1, sizeArray);

  std::cout << "----------------------" << "\n";

  //-------------------------------------------------------------------------------------
  int arrayInt_2[]{ 94, 67, 18, 44, 55, 12, 6, 42 };
  sizeArray = sizeof(arrayInt_2) / sizeof(arrayInt_2[0]);

  PrintArray(arrayInt_2, sizeArray);
  PrintArrayFromPyramid(arrayInt_2, sizeArray);

  std::cout << "----------------------" << "\n";

  //-------------------------------------------------------------------------------------
  int arrayInt_3[]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
  sizeArray = sizeof(arrayInt_3) / sizeof(arrayInt_3[0]);

  PrintArray(arrayInt_3, sizeArray);
  PrintArrayFromPyramid(arrayInt_3, sizeArray);

  std::cout << "----------------------" << "\n";

  return 0;
}
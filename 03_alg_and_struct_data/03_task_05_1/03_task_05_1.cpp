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
struct Node
{
  int number;
  int level;
  char side[6];
};

//-------------------------------------------------------------------------------------
void PrintArrayFromPyramid(int* arr_, int size_arr_) {
  std::cout << "\n";
  std::cout << "Пирамида:" << "\n";

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
  int arrayInt_1[]{ 1, 3, 6, 5, 9, 8 };
  int sizeArray = sizeof(arrayInt_1) / sizeof(arrayInt_1[0]);

  Node* arrayNode_1{ new Node[sizeArray] {} };

  PrintArray(arrayInt_1, sizeArray);

  PrintArrayFromPyramid(arrayInt_1, sizeArray);

  


  return 0;
}
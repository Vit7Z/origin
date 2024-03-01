#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>

void count_sort(int* arr, int sizeArr) {
  int min = 10;
  int max = 24;
	
  int* tempArr{ new int[max + 1 - min] {0} };

	for (int i = 0; i < sizeArr; i++) {
		tempArr[arr[i] - min] = tempArr[arr[i] - min] + 1;
	}

	int i = 0;

	for (int j = min; j < max + 1; j++) {
		while (tempArr[j - min] != 0) {
			arr[i] = j;
			tempArr[j - min]--;
			i++;
		}
	}//for
	
	delete [] tempArr;
}

/////////////////////////////////////////////////////////////////////
void printArr(int* arr, int sizeArr) {
  for (int i = 0; i < sizeArr; i++) {
    std::cout << arr[i] << "  ";
  }//for

  std::cout << "\n";
}

int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  //-------------------------------------------------------------------------------------
  int arrayInt_1[]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 
    17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
  
	int sizeArrInt = sizeof(arrayInt_1) / sizeof(arrayInt_1[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_1, sizeArrInt);
  count_sort(arrayInt_1, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_1, sizeArrInt);

  //-------------------------------------------------------------------------------------
  int arrayInt_2[]{ 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 
    18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };

  sizeArrInt = sizeof(arrayInt_2) / sizeof(arrayInt_2[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_2, sizeArrInt);
  count_sort(arrayInt_2, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_2, sizeArrInt);

  //-------------------------------------------------------------------------------------
  int arrayInt_3[]{ 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 
    14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };

  sizeArrInt = sizeof(arrayInt_3) / sizeof(arrayInt_3[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_3, sizeArrInt);
  count_sort(arrayInt_3, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_3, sizeArrInt);

  return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

void quick_sort(int* arr, int sizeArr) {
  int i = 0;
  int j = sizeArr - 1;
  int midArr = arr[sizeArr / 2];

  do {
    while (arr[i] < midArr) {
      i++;
    }

    while (arr[j] > midArr) {
      j--;
    }

    if (i <= j) {
      int tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0) {
    quick_sort(arr, j + 1);
  }

  if (i < sizeArr) {
    quick_sort(&arr[i], sizeArr - i);
  }
}

//-----------------------------------------------------------------------------
void printArr(int* arr, int sizeArr) {
  for (int i = 0; i < sizeArr; i++) {
    std::cout << arr[i] << "  ";
  }//for

  std::cout << "\n";
}

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  //-----------------------------------------------------------------------------
  int arrayInt_1[] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
  int sizeArrInt = sizeof(arrayInt_1) / sizeof(arrayInt_1[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_1, sizeArrInt);
  quick_sort(arrayInt_1, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_1, sizeArrInt);

  //-----------------------------------------------------------------------------
  int arrayInt_2[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
  sizeArrInt = sizeof(arrayInt_2) / sizeof(arrayInt_2[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_2, sizeArrInt);
  quick_sort(arrayInt_2, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_2, sizeArrInt);

  //-----------------------------------------------------------------------------
  int arrayInt_3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
  sizeArrInt = sizeof(arrayInt_3) / sizeof(arrayInt_3[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_3, sizeArrInt);
  quick_sort(arrayInt_3, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_3, sizeArrInt);
  return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>

void merge_sort(int* arr, int sizeArr)
{
  int step = 1;  

  int* tempArr = (int*)malloc(sizeArr * sizeof(int));

  while (step < sizeArr) {
    int indexTempArr = 0;

    int lBorder = 0;

    int middleSegment = lBorder + step;

    int rBorder = lBorder + step * 2;

    do {
      if (middleSegment >= sizeArr) {
        middleSegment = sizeArr;
      } 
     
      if (rBorder >= sizeArr) {
        rBorder = sizeArr;
      }

      int i1 = lBorder;

      int i2 = middleSegment;

      for (; i1 < middleSegment && i2 < rBorder;) {

        if (arr[i1] < arr[i2]) {
          tempArr[indexTempArr++] = arr[i1++];

        } else { 
          tempArr[indexTempArr++] = arr[i2++];
        }
      }//for

      while (i1 < middleSegment) {
        tempArr[indexTempArr++] = arr[i1++];
      }

      while (i2 < rBorder) {
        tempArr[indexTempArr++] = arr[i2++];
      }

      lBorder += step * 2;
      middleSegment += step * 2;
      rBorder += step * 2;
    } 

    while (lBorder < sizeArr);

    for (int i = 0; i < sizeArr; i++) {
      arr[i] = tempArr[i];
    }

    step *= 2;
  }
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
  int arrayInt_1[] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
  int sizeArrInt = sizeof(arrayInt_1) / sizeof(arrayInt_1[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_1, sizeArrInt);
  merge_sort(arrayInt_1, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_1, sizeArrInt);

  //-------------------------------------------------------------------------------------
  int arrayInt_2[]{ 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
  sizeArrInt = sizeof(arrayInt_2) / sizeof(arrayInt_2[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_2, sizeArrInt);
  merge_sort(arrayInt_2, sizeArrInt);
  printArr(arrayInt_2, sizeArrInt);

  //-------------------------------------------------------------------------------------
  int arrayInt_3[]{ 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
  sizeArrInt = sizeof(arrayInt_3) / sizeof(arrayInt_3[0]);
  std::cout << "Исходный массив: ";
  printArr(arrayInt_3, sizeArrInt);
  merge_sort(arrayInt_3, sizeArrInt);
  std::cout << "Отсортированный массив: ";
  printArr(arrayInt_3, sizeArrInt);

  return 0;
}
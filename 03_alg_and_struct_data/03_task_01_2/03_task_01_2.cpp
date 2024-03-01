#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

int findBinarySearch(int arr[], int leftArr, int rightArr, int key) {

  int middleArr = 0;

  while (1) {
    middleArr = (leftArr + rightArr) / 2;

    if (key < arr[middleArr]) {
      rightArr = middleArr - 1;

    } else if (key > arr[middleArr]) {
      leftArr = middleArr + 1;

    } else {
      return middleArr;
    }

    if (leftArr > rightArr) {
      return -1;
    }
  }//while
}//func

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int keyNumber = 0;

  int indexKey = 0;

  int numberElementsLarger = 0;

  int indexStart = 0;

  const int indexEnd = 9;

  int arrayOfInt[] {14, 16, 19, 32, 32, 32, 56, 69, 72};

  std::cout << "Введите точку отсчёта: ";

  std::cin >> keyNumber;

  if (keyNumber < arrayOfInt[indexStart]) {
    numberElementsLarger = 9;
  }
  else if (keyNumber > arrayOfInt[indexEnd-1]) {
    numberElementsLarger = 0;
  }
  else {
    indexKey = findBinarySearch(arrayOfInt, indexStart, indexEnd, keyNumber);

    for (int i = indexKey; i < indexEnd; i++) {
      if (arrayOfInt[i] > keyNumber) {
        numberElementsLarger++;
      }
    }
  }//if 

  std::cout << "Количество элементов в массиве больших, чем " << keyNumber << ": " << numberElementsLarger << "\n";

  return 0;
}

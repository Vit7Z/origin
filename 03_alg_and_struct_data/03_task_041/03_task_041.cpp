#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>

//---------------------------------------------------------------------------------------
void checkSizeArr(int actualSizeArr_, int& logicSizeArr_) {
  while (actualSizeArr_ < logicSizeArr_) {
    std::cout << "ќшибка! Ћогический размер массива не может превышать фактический!" << "\n";
    std::cout << "¬ведите логический размер массива: ";
    std::cin >> logicSizeArr_;
  }//while
}

//---------------------------------------------------------------------------------------
void getArr(int* arr, int sizeArr) {
  for (int i = 0; i < sizeArr; i++) {
    std::cout << "¬ведите arr[" << i << "]: ";

    std::cin >> arr[i];
  }//for
}

//---------------------------------------------------------------------------------------
void printArr(int* arr, int actualSizeArr, int logicSizeArr) {
  std::cout << "ƒинамический массив: ";

  for (int i = 0; i < actualSizeArr; i++) {
    if (i < logicSizeArr) {
      std::cout << arr[i] << "  ";
    }
    else {
      std::cout << "_" << "  ";
    }
  }//for

  std::cout << "\n";
}

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
	
  int actualSizeArr = 0;
  int logicSizeArr = 0;

  //---------------------------------------------------------------------------------------
  std::cout << "¬ведите фактичеcкий размер массива: ";
  std::cin >> actualSizeArr;
  std::cout << "¬ведите логический размер массива: ";
  std::cin >> logicSizeArr;

  //---------------------------------------------------------------------------------------
  checkSizeArr (actualSizeArr, logicSizeArr);
  int* arrInt{ new int[actualSizeArr] {0} };
  getArr(arrInt, logicSizeArr);
  printArr(arrInt, actualSizeArr, logicSizeArr);
	delete [] arrInt;

  return 0;
}
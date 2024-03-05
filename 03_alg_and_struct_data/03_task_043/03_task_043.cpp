#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

//---------------------------------------------------------------------------
void checkSizeArr(int actualSizeArr_, int& logicSizeArr_) {
  while (actualSizeArr_ < logicSizeArr_) {
    std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << "\n";
    std::cout << "Введите логический размер массива: ";
    std::cin >> logicSizeArr_;
  }//while
}

//---------------------------------------------------------------------------
void getArr(int* arr, int sizeArr) {
  for (int i = 0; i < sizeArr; i++) {
    std::cout << "Введите arr[" << i << "]: ";
    std::cin >> arr[i];
  }//for
}

//---------------------------------------------------------------------------
void remove_dynamic_array_head(int* arr, int& actualSizeArr_, int& logicSizeArr_) {
  for (int i = 0; i < logicSizeArr_; i++) {
    arr[i] = arr[i + 1];
  }

  arr[logicSizeArr_] = 0;

  if (logicSizeArr_ <= (actualSizeArr_ / 3)) {
    actualSizeArr_ /= 3;
    int* arrNew{ new int[actualSizeArr_] {*arr} };
    arr = arrNew;
    delete[] arrNew;
  }//if
}
  
//---------------------------------------------------------------------------
void printArr(int* arr, int actualSizeArr, int logicSizeArr) {
  //std::cout << "Динамический массив: ";

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
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  int actualSizeArr = 0;
  int logicSizeArr = 0;

  //---------------------------------------------------------------------------
  std::cout << "Введите фактичеcкий размер массива: ";
  std::cin >> actualSizeArr;
  std::cout << "Введите логический размер массива: ";
  std::cin >> logicSizeArr;

  //---------------------------------------------------------------------------
  checkSizeArr (actualSizeArr, logicSizeArr);
  int* arrInt{ new int[actualSizeArr] {0} };

  getArr(arrInt, logicSizeArr);
  std::cout << "Динамический массив: ";
  printArr(arrInt, actualSizeArr, logicSizeArr);

  std::string keyAct = "да";

  //---------------------------------------------------------------------------
  while (keyAct == "да") {
    std::cout << "Удалить первый элемент? ";
    std::cin >> keyAct;

    if (keyAct == "нет") {
      std::cout << "Спасибо! Ваш массив: ";
      printArr(arrInt, actualSizeArr, logicSizeArr);
      logicSizeArr = -3;
    }//if

    logicSizeArr--;

    if (logicSizeArr > 0) {
      remove_dynamic_array_head(arrInt, actualSizeArr, logicSizeArr);
      std::cout << "Динамический массив: ";
      printArr(arrInt, actualSizeArr, logicSizeArr);
    }//if

    if (logicSizeArr == -1) {
      std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!" << "\n";
      keyAct = "нет";
    }//if

    if (logicSizeArr == 0) {
      std::cout << "Динамический массив: ";
      printArr(arrInt, actualSizeArr, logicSizeArr);
    }//if
  }//while

	delete [] arrInt;

  return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>

//---------------------------------------------------------------------------
void checkSizeArr(int actualSizeArr_, int& logicSizeArr_) {
  while (actualSizeArr_ < logicSizeArr_) {
    std::cout << "������! ���������� ������ ������� �� ����� ��������� �����������!" << "\n";

    std::cout << "������� ���������� ������ �������: ";

    std::cin >> logicSizeArr_;
  }//while
}

//---------------------------------------------------------------------------
void getArr(int* arr, int sizeArr) {
  for (int i = 0; i < sizeArr; i++) {
    std::cout << "������� arr[" << i << "]: ";

    std::cin >> arr[i];
  }//for
}

//---------------------------------------------------------------------------
void append_to_dynamic_array(int* arr, int& actualSizeArr_, int& logicSizeArr_, int intAdd_) {
  logicSizeArr_++;

  arr[logicSizeArr_ - 1] = intAdd_;

  if (logicSizeArr_ == actualSizeArr_) {
    actualSizeArr_ *= 2;
    int* arrNew{ new int[actualSizeArr_] {*arr} };
    arr = arrNew;
    delete[] arrNew;
  }
}
  
//---------------------------------------------------------------------------
void printArr(int* arr, int actualSizeArr, int logicSizeArr) {
  //std::cout << "������������ ������: ";

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

  //---------------------------------------------------------------------------
  std::cout << "������� �������c��� ������ �������: ";
  std::cin >> actualSizeArr;
  std::cout << "������� ���������� ������ �������: ";
  std::cin >> logicSizeArr;

  //---------------------------------------------------------------------------
  checkSizeArr (actualSizeArr, logicSizeArr);
  int* arrInt{ new int[actualSizeArr] {0} };

  getArr(arrInt, logicSizeArr);
  std::cout << "������������ ������: ";
  printArr(arrInt, actualSizeArr, logicSizeArr);

  //---------------------------------------------------------------------------
  int intAdd = 100;

  while (intAdd != 0) {
    std::cout << "������� ������� ��� ����������: ";
    std::cin >> intAdd;
    if (intAdd != 0) {
      append_to_dynamic_array(arrInt, actualSizeArr, logicSizeArr, intAdd);
      std::cout << "������������ ������: ";
      printArr(arrInt, actualSizeArr, logicSizeArr);
    }
  }//while

  std::cout << "�������! ��� ������: ";
  printArr(arrInt, actualSizeArr, logicSizeArr);
	
	delete [] arrInt;

  return 0;
}
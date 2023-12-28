#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

void ReverseOfArray (std::string* Arr, int i)
{
  for (int j = 0; j < i / 2 ; j++)
    {
      std::string buf = Arr[j];

      Arr[j] = Arr[i-1-j];

      Arr[i-1-j] = buf;
    }

  std::cout << std::endl;
}

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  //int StringFromFile;

  static int i_OfArray, j_OfArray;

  std::ifstream OpenFile_1 ("in_1_12_4.txt");

  OpenFile_1 >> i_OfArray;

  OpenFile_1 >> j_OfArray;

  std::cout << "Строк в массиве: " << i_OfArray << "   " << "Столбцов в массиве: " << j_OfArray << std::endl;

  ///////----------------------------------------------------------------------
  int** arrOfStr = new int* [i_OfArray];

  for (int i = 0; i < i_OfArray; i++)
  {
    arrOfStr[i] = new int[j_OfArray];
  }

  ///////----------------------------------------------------------------------
  std::cout << "Исходный массив:" << std::endl;

  for (int i = 0; i < i_OfArray; i++)
    {
      for (int j = 0; j < j_OfArray; j++)
      {
        OpenFile_1 >> arrOfStr[i][j];

        std::cout << arrOfStr[i][j] << "\t";
      }

      std::cout << std::endl;
    }//for

  OpenFile_1.close();

  ///////----------------------------------------------------------------------
  std::cout << "Перевернутый массив:" << std::endl;

  for (int i = 0; i < i_OfArray; i++)
    {
      for (int j = j_OfArray -1 ; j >= 0; j--)
      {
        std::cout << arrOfStr[i][j] << "\t";
      }

      std::cout << std::endl;
    }//for

  ///////----------------------------------------------------------------------
  for(int i = 0; i < i_OfArray; i++)
    {
      delete [] arrOfStr[i];
    }

  delete [] arrOfStr;

	return 0;
}

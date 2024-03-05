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

  std::string StringFromFile;

  unsigned short sizeOfArray = 0;

  std::cout << "¬ведите размер массива: ";

  std::cin >> sizeOfArray;

  std::string* arrOfStr = new std::string [sizeOfArray];

  for (int counter = 0; counter < sizeOfArray; counter++)
    {
      std::cout << "arr[" << counter << "] = ";

      std::cin >> arrOfStr[counter];
    }

  ReverseOfArray (arrOfStr, sizeOfArray);

  std::ofstream openFileToWrite ("out_1_12_3.txt");

  openFileToWrite << sizeOfArray << std::endl;;

  for (int counter = 0; counter < sizeOfArray; counter++)
    {
      openFileToWrite << arrOfStr[counter] << "  ";
    }

  openFileToWrite.close();

  delete [] arrOfStr;

	return 0;
}

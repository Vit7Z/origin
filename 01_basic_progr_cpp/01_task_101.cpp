#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>

int main(int argc, char** argv)
{
  setlocale(LC_ALL, "rus");

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

  std::cout << "¬ведЄнный массив:";

  for (int counter = 0; counter < sizeOfArray; counter++)
    {
      std::cout << " " << arrOfStr[counter];
    }

  std::cout << std::endl;

  delete [] arrOfStr;

	return 0;
}

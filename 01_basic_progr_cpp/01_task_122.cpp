#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

void PrintOfArray (std::string* Arr, int i_)
{
  for (int i = 0; i < i_ ;i++)
    {
      std::cout << Arr[i] << "\t";
    }
}

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

  int sizeOfArray = 1;

  std::ifstream OpenFile_1 ("in_1_12_2.txt");

  ///////-------COUNTING THE NUMBER OF LINES IN A FILE-------////////////////

  if(OpenFile_1.is_open())
  {
    while(!(OpenFile_1 >> StringFromFile).eof())
      {
        sizeOfArray++;
      }
  }
  else
  {
    std::cout << "Не получилось открыть файл!" << std::endl;
  }

  ///////-------ALLOCATION OF MEMORY FOR AN ARRAY-------////////////////

  std::string* arrOfStr = new std::string [sizeOfArray];


  OpenFile_1.close();

  ///////-------READING A FILE AND FILLING IN AN ARRAY-------////////////////

  std::ifstream OpenFile_2 ("in_1_12_2.txt");

  for (int counter = 0; counter < sizeOfArray; counter++)
    {
      OpenFile_2 >> StringFromFile;

      arrOfStr[counter] = StringFromFile;
    }

  OpenFile_2.close();

  std::cout << "Кол. элементов массива: " << sizeOfArray << std::endl;

  ///////-------DISPLAYING AN ARRAY ON THE SCREEN-------////////////////

  std::cout << "Исходный массив: " << "\t";

  PrintOfArray (arrOfStr, sizeOfArray);

  ///////-------INVERTING OF ARRAY-------////////////////

  ReverseOfArray (arrOfStr, sizeOfArray);

  ///////-------DISPLAYING AN INVERTED ARRAY-------////////////////

  std::cout << "Перевернутый массив: " << "\t";

  PrintOfArray (arrOfStr, sizeOfArray);

  std::cout << std::endl;

  delete [] arrOfStr;

	return 0;
}

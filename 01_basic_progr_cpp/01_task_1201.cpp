#include <iostream>
#include <fstream>
#include <locale.h>

int main(int argc, char** argv)
{
  setlocale(0, "Russian");

  std::string StringFromFile;

  std::ifstream OpenFile ("in_1_12_1.txt");

  if(OpenFile.is_open())
  {
    while(!(OpenFile >> StringFromFile).eof())
      {
        std::cout << StringFromFile << std::endl;
      }
  }
  else
  {
    std::cout << "Не получилось открыть файл!" << std::endl;
  }

  OpenFile.close();

	return 0;
}

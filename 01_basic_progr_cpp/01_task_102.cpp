#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>

double* create_array (unsigned short sizeOfArray)
{
  return new double [sizeOfArray] ();
}

int main(int argc, char** argv)
{
  setlocale(LC_ALL, "rus");

  unsigned short sizeOfArray = 0;

  std::cout << "������� ������ �������: ";

  std::cin >> sizeOfArray;

  double* arrOfDouble = create_array (sizeOfArray);


  std::cout << "�������� ������:";

  for (int counter = 0; counter < sizeOfArray; counter++)
    {
      std::cout << " " << arrOfDouble[counter];
    }

  std::cout << std::endl;

  delete [] arrOfDouble;

	return 0;
}

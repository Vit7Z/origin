#include <iostream>
#include <string>
#include <locale.h>

void PrintOfArray (int* Arr, int i_)
{
  for (int i = 0; i < i_ ;i++)
    {
      std::cout << Arr[i] << "\t";
    }
}

void ReverseOfArray (int* Arr, int i)
{
  for (int j = 0; j < i / 2 ; j++)
    {
      int buf = Arr[j];

      Arr[j] = Arr[i-1-j];

      Arr[i-1-j] = buf;
    }

  std::cout << std::endl;
}

int main()
{
  setlocale(0, "Russian");

  int SizeArr = 0;

  //массив с четным кол. элементов
  int ArrayInt_1 [] {-11, 22, -33, 44, -55, 66, -77, 88, -99, 12};

  SizeArr = sizeof(ArrayInt_1)/sizeof(ArrayInt_1[0]);

  std::cout << "Before reverse: ";

  PrintOfArray (ArrayInt_1, SizeArr);

  ReverseOfArray (ArrayInt_1, SizeArr);

  std::cout << "After reverse: " << "\t";

  PrintOfArray (ArrayInt_1, SizeArr);

  std::cout << std::endl << std::endl;

  //массив с нечетным кол. элементов
  int ArrayInt_2 [] {111, -222, 333, -444, 555};

  SizeArr = sizeof(ArrayInt_2)/sizeof(ArrayInt_2[0]);

  std::cout << "Before reverse: ";

  PrintOfArray (ArrayInt_2, SizeArr);

  ReverseOfArray (ArrayInt_2, SizeArr);

  std::cout << "After reverse: " << "\t";

  PrintOfArray (ArrayInt_2, SizeArr);

  std::cout << std::endl;
}

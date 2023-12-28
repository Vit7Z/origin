#include <iostream>
#include <string>

void PrintOfArray (int* Arr, int SizeArr_)
{
  for (int i = 0; i < SizeArr_ ;i++)
    {
      std::cout << Arr[i] << "\t";
    }

  std::cout << std::endl;
}

int main() {

  int SizeArr = 0;

  int ArrayInt_1 [] {-11, 22, -33, 44, -55, 66, -77, 88, -99, 12};

  SizeArr = sizeof(ArrayInt_1)/sizeof(ArrayInt_1[0]);

  PrintOfArray (ArrayInt_1, SizeArr);

  int ArrayInt_2 [] {111, -222, 333, -444, 555, -666};

  SizeArr = sizeof(ArrayInt_2)/sizeof(ArrayInt_2[0]);

  PrintOfArray (ArrayInt_2, SizeArr);

  int ArrayInt_3 [] {-9999, 8888, -7777, 6666, -5555, 4444, -3333, 2222, -1111, 9988, -7766, 5544, -3322, 1100, -9898, 77676};

  SizeArr = sizeof(ArrayInt_3)/sizeof(ArrayInt_3[0]);

  PrintOfArray (ArrayInt_3, SizeArr);
}

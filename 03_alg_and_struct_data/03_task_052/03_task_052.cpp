#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>

//-------------------------------------------------------------------------------------
void PrintArray(int* arr_, int size_arr_)
{
  std::cout << "Исходный массив: ";
  for (int i = 0; i < size_arr_; i++) {
    std::cout << arr_[i] << "\t";
  }
  std::cout << "\n" << "\n";
}

//-------------------------------------------------------------------------------------
void PrintArrayFromPyramid(int* arr_, int size_arr_) 
{
  std::cout << "Пирамида:" << "\n";
  std::cout << "0 root " << arr_[0] << "\n";

  int i = 1;

  for (int k = 1; k <= (int)(std::log2(size_arr_)); k++) {

    int reptitions = pow(2, k);

    for (int j = 1; j <= reptitions && i < size_arr_; j++, i++) {
      int indexParent = (i - 1) / 2;

      if (i % 2 != 0) {
        std::cout << k << " " << "left (" << arr_[indexParent] << ") " << arr_[i] << "\n";
      }
      else {
        std::cout << k << " " << "right (" << arr_[indexParent] << ") " << arr_[i] << "\n";
      }
    }//for
  }//for
  std::cout << "\n";
}

int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  std::string key = "y";
  std::string side = "root";

  int currentIndex = 0;
  int currentLevel = 0;
  int oldIndex = 0;

  //-------------------------------------------------------------------------------------
  //int arrayInt_1[]{ 1, 3, 6, 5, 9, 8 };
  
  int arrayInt_1[]{ 94, 67, 18, 44, 55, 12, 6, 42 };

  //int arrayInt_1[]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };

  int sizeArray = sizeof(arrayInt_1) / sizeof(arrayInt_1[0]);

  PrintArray(arrayInt_1, sizeArray);
  PrintArrayFromPyramid(arrayInt_1, sizeArray);

  std::cout << "Вы находитесь здесь: 0 root (1)" << "\n";

  //-------------------------------------------------------------------------------------
  while (key != "exit") {
    std::cout << "Введите команду: "; 
    std::cin >> key;

    if (key == "up") {
      if (currentLevel == 0) {
        std::cout << "Ошибка! Отсутствует родитель." << "\n";
      }
      else {
        currentIndex = (oldIndex - 1) / 2;
      }
    }

    if (key == "left") {
      currentIndex = (oldIndex * 2) + 1;
      if (currentIndex > sizeArray - 1) {
         std::cout << "Ошибка! Отсутствует левый потомок." << "\n";
         currentIndex = (currentIndex - 1) / 2;
      }
    }

    if (key == "right") {
      currentIndex = (oldIndex * 2) + 2;
      if (currentIndex > sizeArray - 1) {
        std::cout << "Ошибка! Отсутствует правый потомок." << "\n";
        currentIndex = (currentIndex - 2) / 2;
      }
    }

    oldIndex = (currentIndex - 1) / 2;
    currentLevel = (int)(std::log2(currentIndex + 1));

    if (currentLevel != 0) {
      if (currentIndex % 2 == 0) {
          side = "right";
      }
      else {
        side = "left";
      }
    }

    if (key != "exit") {
      if (currentLevel != 0) {
        std::cout << "Вы находитесь здесь: " << currentLevel << " " << side << " (" << arrayInt_1[oldIndex] <<
          ") " << arrayInt_1[currentIndex] << "\n";
      }

      if (currentLevel == 0) {
        std::cout << "Вы находитесь здесь: 0 root (1)" << "\n";
      }
    }

    oldIndex = currentIndex;
  }//while
 
  return 0;
}
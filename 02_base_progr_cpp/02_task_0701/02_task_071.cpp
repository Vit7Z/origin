#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#define MODE 1

int add_num () {
  int num_1, num_2;

  std::cout << "Введите число 1: ";
  std::cin >> num_1;

  std::cout << "Введите число 2: ";
  std::cin >> num_2;

  return num_1 + num_2;
}//func

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  #if !defined MODE
  #error Необходмо определить константу MODE
  #endif

  #if (MODE != 1) && (MODE != 0)
    std::cout << "Неизвестный режим. Завершение работы." << std::endl;
  #endif

  #if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;
  #endif

  #if MODE == 1
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Результат сложения: " << add_num() << std::endl;
  #endif

  return 0;
}
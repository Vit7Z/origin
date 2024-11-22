#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>
#include "counter.h"

int main(int argc, char** argv) {

  setlocale(0, "Rus");

  SetConsoleCP(1251);

  SetConsoleOutputCP(1251);

  std::string value1;

  int initValue = 1;

  ///////------------------------------------------------
  std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет:" << "\t";

  std::cin >> value1;

  if (value1 == "да") {

    std::cout << "Введите начальное значение счётчика:" << "\t";

    std::cin >> initValue;
  }

  Counter tmpNum = Counter(initValue);

  ///////------------------------------------------------
  enum class listAct {plus = '+', minus = '-', get = '=', ending = 'х'};

  char act = '0';

  ///////------------------------------------------------
  while (act != 'х') {

    std::cout << "Введите команду ('+', '-', '=' или 'x'):" << "\t";

    std::cin >> act;

    listAct currentAct = static_cast<listAct>(act);

    switch (currentAct) {
      case listAct::plus:
        tmpNum.increase();
        break;

      case listAct::minus:
        tmpNum.decrease();
        break;

      case listAct::get:
        std::cout << tmpNum.get_num() << "\n";
        break;

      case listAct::ending:
        std::cout << "До свидания!\n";
        break;
    }//switch
  }//while

  return 0;
}

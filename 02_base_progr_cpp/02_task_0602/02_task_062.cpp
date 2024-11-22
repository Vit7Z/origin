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
  std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���:" << "\t";

  std::cin >> value1;

  if (value1 == "��") {

    std::cout << "������� ��������� �������� ��������:" << "\t";

    std::cin >> initValue;
  }

  Counter tmpNum = Counter(initValue);

  ///////------------------------------------------------
  enum class listAct {plus = '+', minus = '-', get = '=', ending = '�'};

  char act = '0';

  ///////------------------------------------------------
  while (act != '�') {

    std::cout << "������� ������� ('+', '-', '=' ��� 'x'):" << "\t";

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
        std::cout << "�� ��������!\n";
        break;
    }//switch
  }//while

  return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#include "02_task_06_1.h"

int main(int argc, char** argv) {

  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  double value1 = 1;

  double value2 = 1;

  ///////------------------------------------------------
  std::cout << "������� ������ �����: " << "\t";

  std::cin >> value1;

  std::cout << "������� ������ �����:" << "\t";

  std::cin >> value2;

  checkZeroNum_2(value2);

  ///////------------------------------------------------
  enum class listAct {�������� = 1, ���������, ���������, �������, ����������_�_�������};

  int keyAct = 1;
 
  std::cout << "�������� �������� (1-��������, 2-���������, 3-���������, 4-�������, 5-���������� � �������): " << "\t";
  
  std::cin >> keyAct;

  listAct currentAct = static_cast<listAct>(keyAct);

  ///////------------------------------------------------
  switch (currentAct) {

  case listAct::��������:
    std::cout << value1 << " + " << value2 << " = " << add(value1, value2) << "\n";
    break;

  case listAct::���������:
    std::cout << value1 << " - " << value2 << " = " << subtract_1_2(value1, value2) << "\n";
    break;

  case listAct::���������:
    std::cout << value1 << " * " << value2 << " = " << multiply(value1, value2) << "\n";
    break;

  case listAct::�������:
    std::cout << value1 << " / " << value2 << " = " << divide_1_2(value1, value2) << "\n";
    break;

  case listAct::����������_�_������� :
    std::cout << value1 << " � ������� " << value2 << " = " << raiseToDegree(value1, value2) << "\n";
    break;

  default:
    std::cout << "������������ ����� ��������!\n";

  }//switch

  return 0;
}

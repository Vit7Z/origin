#include <iostream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

//#include "ground_vehicle.h"

//-------------------------------------------------------------------
unsigned short getTypeOfRace (unsigned short &typeOfRace_) {
  while (typeOfRace_ < 1 || typeOfRace_ > 3) {
    std::cout << "�� ������� ������������ �����! :-(" << "\n";
    std::cout << "��������� ���� (1, 2 ��� 3): ";
    std::cin >> typeOfRace_;
  }
  return typeOfRace_;
}


int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  //---------------------------------------------------------------------------
  unsigned short typeOfRace{ 6 };
  std::cout << "����� ���������� � �������� ����������!" << "\n";
  std::cout << "1. ����� ��� ��������� ����������" << "\n";
  std::cout << "2. ����� ��� ���������� ����������" << "\n";
  std::cout << "3. ����� ��� ��������� � ���������� ����������" << "\n";
  std::cout << "�������� ��� �����: ";
  std::cin >> typeOfRace;
  
  getTypeOfRace(typeOfRace);
  
  

  return 0;
}

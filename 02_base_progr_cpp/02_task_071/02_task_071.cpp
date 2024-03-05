#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#define MODE 1

int add_num () {
  int num_1, num_2;

  std::cout << "������� ����� 1: ";
  std::cin >> num_1;

  std::cout << "������� ����� 2: ";
  std::cin >> num_2;

  return num_1 + num_2;
}//func

int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  #if !defined MODE
  #error ��������� ���������� ��������� MODE
  #endif

  #if (MODE != 1) && (MODE != 0)
    std::cout << "����������� �����. ���������� ������." << std::endl;
  #endif

  #if MODE == 0
    std::cout << "������� � ������ ����������" << std::endl;
  #endif

  #if MODE == 1
    std::cout << "������� � ������ ������" << std::endl;
    std::cout << "��������� ��������: " << add_num() << std::endl;
  #endif

  return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>


int main(int argc, char** argv)
{
    setlocale(0, "Rus");

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    enum class listMonths {������ = 1, �������, ����, ������, ���, ����, ����, ������, ��������, �������, ������, �������};

    int digitMonth = 1;

    while (digitMonth != 0) {

      std::cout << "������� ����� ������: " << "\t";

      std::cin >> digitMonth;

      listMonths currentMonth = static_cast<listMonths>(digitMonth);

      switch (currentMonth) {

        case listMonths::������:
          std::cout << "������\n\n";
          break;

        case listMonths::�������:
          std::cout << "�������\n\n";
          break;

        case listMonths::����:
          std::cout << "����\n\n";
          break;

        case listMonths::������:
          std::cout << "������\n\n";
          break;

        case listMonths::���:
          std::cout << "���\n\n";
          break;

        case listMonths::����:
          std::cout << "����\n\n";
          break;

        case listMonths::����:
          std::cout << "����\n\n";
          break;

        case listMonths::������:
          std::cout << "������\n\n";
          break;

        case listMonths::��������:
          std::cout << "��������\n\n";
          break;

        case listMonths::�������:
          std::cout << "�������\n\n";
          break;

        case listMonths::������:
          std::cout << "������\n\n";
          break;

        case listMonths::�������:
          std::cout << "�������\n\n";
          break;

        case 0:
          std::cout << "�� ��������.\n\n";
          break;

       default:
         std::cout << "������������ ����� ������!\n\n";

      }//switch

    }//while

    return 0;
}

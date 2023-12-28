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

    enum class listMonths {Январь = 1, Февраль, Март, Апрель, Май, Июнь, Июль, Август, Сентябрь, Октябрь, Ноябрь, Декабрь};

    int digitMonth = 1;

    while (digitMonth != 0) {

      std::cout << "Введите номер месяца: " << "\t";

      std::cin >> digitMonth;

      listMonths currentMonth = static_cast<listMonths>(digitMonth);

      switch (currentMonth) {

        case listMonths::Январь:
          std::cout << "Январь\n\n";
          break;

        case listMonths::Февраль:
          std::cout << "Февраль\n\n";
          break;

        case listMonths::Март:
          std::cout << "Март\n\n";
          break;

        case listMonths::Апрель:
          std::cout << "Апрель\n\n";
          break;

        case listMonths::Май:
          std::cout << "Май\n\n";
          break;

        case listMonths::Июнь:
          std::cout << "Июнь\n\n";
          break;

        case listMonths::Июль:
          std::cout << "Июль\n\n";
          break;

        case listMonths::Август:
          std::cout << "Август\n\n";
          break;

        case listMonths::Сентябрь:
          std::cout << "Сентябрь\n\n";
          break;

        case listMonths::Октябрь:
          std::cout << "Октябрь\n\n";
          break;

        case listMonths::Ноябрь:
          std::cout << "Ноябрь\n\n";
          break;

        case listMonths::Декабрь:
          std::cout << "Декабрь\n\n";
          break;

        case 0:
          std::cout << "До свидания.\n\n";
          break;

       default:
         std::cout << "Неправильный номер месяца!\n\n";

      }//switch

    }//while

    return 0;
}

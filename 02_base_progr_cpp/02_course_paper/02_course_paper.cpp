#include <iostream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

//#include "ground_vehicle.h"

//-------------------------------------------------------------------
unsigned short getTypeOfRace (unsigned short &typeOfRace_) {
  while (typeOfRace_ < 1 || typeOfRace_ > 3) {
    std::cout << "Вы сделали неправильный выбор! :-(" << "\n";
    std::cout << "Повторите ввод (1, 2 или 3): ";
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
  std::cout << "Добро пожаловать в гоночный стимулятор!" << "\n";
  std::cout << "1. Гонка для наземного транспорта" << "\n";
  std::cout << "2. Гонка для воздушного транспорта" << "\n";
  std::cout << "3. Гонка для наземного и воздушного транспорта" << "\n";
  std::cout << "Выберите тип гонки: ";
  std::cin >> typeOfRace;
  
  getTypeOfRace(typeOfRace);
  
  

  return 0;
}

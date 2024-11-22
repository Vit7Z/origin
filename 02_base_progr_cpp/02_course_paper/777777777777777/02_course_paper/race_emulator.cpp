#include <iostream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#include "races_lib/races_lib.h"
#include "races_members_lib/races_members_lib.h"

//#include "ground_vehicle.h"

//-------------------------------------------------------------------
unsigned short getTypeOfRace () {
	std::cout << "Добро пожаловать в гоночный стимулятор!" << "\n";
  std::cout << "1. Гонка для наземного транспорта" << "\n";
  std::cout << "2. Гонка для воздушного транспорта" << "\n";
  std::cout << "3. Гонка для наземного и воздушного транспорта" << "\n";
  std::cout << "Выберите тип гонки: ";

  unsigned short m_type_of_race{ 6 };
  std::cin >> m_type_of_race;
	
  while (m_type_of_race < 1 || m_type_of_race > 3) {
    std::cout << "Вы сделали неправильный выбор! :-(" << "\n";
    std::cout << "Повторите ввод (1, 2 или 3): ";
    std::cin >> m_type_of_race;
  }
  return m_type_of_race;
}


int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  //---------------------------------------------------------------------------
  unsigned short type_of_race{ 6 };
  //type_of_race = getTypeOfRace();
  //std::cout << "type_of_race " << type_of_race;


  type_of_race = 1;


  int a = 5;
  int b = 10;


  std::cout << "a = " << a << ", b = " << b << std::endl;

  races::RacesAir pp1;

  races_members::RaceBoots pp_1;


  std::cout << "pp1 = " << pp_1.getName() << std::endl;

  return 0;
}

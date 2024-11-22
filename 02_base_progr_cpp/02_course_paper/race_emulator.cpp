#include <iostream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#include "racers_dll/racers_dll.h"
//#include "races_members_lib/races_members_lib.h"

using namespace racers_dll;

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

  unsigned int distance{ 1022 };


  RacerCamel racer_1;
  RacerBoots racer_2;
  RacerCamelFast racer_3;

  std::cout << "Name = " << racer_1.getName() <<"  Time = " << racer_1.getTime(distance) << std::endl;
  std::cout << "Name = " << racer_2.getName() << "  Time = " << racer_2.getTime(distance) << std::endl;
  std::cout << "Name = " << racer_3.getName() << "  Time = " << racer_3.getTime(distance) << std::endl;


 

  return 0;
}

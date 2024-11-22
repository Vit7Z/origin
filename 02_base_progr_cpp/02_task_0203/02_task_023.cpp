#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

struct adressOfPerson
  {
    std::string city;
    std::string street;     
    unsigned int numberBuilding;
    unsigned short apartmentNumber;
    unsigned int poctcode;
  };

void printAdressOfPerson(adressOfPerson* adressOfPerson_) {

  std::cout << "Город: " << adressOfPerson_->city << "\n";
  std::cout << "Улица: " << adressOfPerson_->street << "\n";
  std::cout << "Номер дома: " << adressOfPerson_->numberBuilding << "\n";
  std::cout << "Номер квартиры: " << adressOfPerson_->apartmentNumber << "\n";
  std::cout << "Индекс: "<< adressOfPerson_->poctcode << "\n";
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
    setlocale(0, "Rus");

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    adressOfPerson adress_1 {"Иркутск", "Карла Маркса", 43, 99, 664003};

    adressOfPerson adress_2 {"Оренбург", "50 лет ВЛКСМ", 34, 179, 460045};

    printAdressOfPerson(&adress_1);

    printAdressOfPerson(&adress_2);

    return 0;
}

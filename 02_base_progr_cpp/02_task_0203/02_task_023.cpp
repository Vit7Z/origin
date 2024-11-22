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

  std::cout << "�����: " << adressOfPerson_->city << "\n";
  std::cout << "�����: " << adressOfPerson_->street << "\n";
  std::cout << "����� ����: " << adressOfPerson_->numberBuilding << "\n";
  std::cout << "����� ��������: " << adressOfPerson_->apartmentNumber << "\n";
  std::cout << "������: "<< adressOfPerson_->poctcode << "\n";
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
    setlocale(0, "Rus");

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    adressOfPerson adress_1 {"�������", "����� ������", 43, 99, 664003};

    adressOfPerson adress_2 {"��������", "50 ��� �����", 34, 179, 460045};

    printAdressOfPerson(&adress_1);

    printAdressOfPerson(&adress_2);

    return 0;
}

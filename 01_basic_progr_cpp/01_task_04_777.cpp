#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

class adressOfPerson
{
public:
  adressOfPerson () {}

  std::string get_output_address() {
    return city + ", " + street + ", " + numberBuilding + ", " + apartmentNumber;
  }

  void setCity(std::string city_) {
    city = city_;
  }

  void setStreet(std::string street_) {
    street = street_;
  }

  void setNumberBuilding(std::string numberBuilding_) {
    numberBuilding = numberBuilding_;
  }

  void setApartmentNumber(std::string apartmentNumber_) {
    apartmentNumber = apartmentNumber_;
  }

  std::string getCity() {
    return city;
  }

  std::string getStreet() {
    return street;
  }


private:
  std::string city;
  std::string street;
  std::string numberBuilding;
  std::string apartmentNumber;
};

int main(int argc, char** argv)
{
    setlocale(0, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string stringFromFile;

    int sizeOfArray = 0;

    std::ifstream readFromFile("in.txt");

    if (!readFromFile.is_open()) {
      std::cout << "Не получилось открыть файл!" << std::endl; 
    }

    getline(readFromFile, stringFromFile);
 
    sizeOfArray = std::stoi(stringFromFile);

    adressOfPerson* listOfAdresses = new adressOfPerson[sizeOfArray];

    ///////--------------------------------------------------------------------
    for (int i = 0; i < sizeOfArray; i++) {
      getline(readFromFile, stringFromFile);
      listOfAdresses[i].setCity(stringFromFile);

      getline(readFromFile, stringFromFile);
      listOfAdresses[i].setStreet(stringFromFile);

      getline(readFromFile, stringFromFile);
      listOfAdresses[i].setNumberBuilding(stringFromFile);

      getline(readFromFile, stringFromFile);
      listOfAdresses[i].setApartmentNumber(stringFromFile);
    }

    readFromFile.close();

    std::ofstream writeToFile("out.txt");

    /////////--------------------------------------------------------------------

    writeToFile << sizeOfArray;

    ///////--------------------------------------------------------------------
    for (int i = 0; i < sizeOfArray; i++) {
      writeToFile << "\n";
      writeToFile << listOfAdresses[i].get_output_address();
    }

    writeToFile.close();

    delete[] listOfAdresses;

    return 0;
}

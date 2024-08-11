#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

///////-------------------------------------------------------------------------
std::string GetDataVertex(std::string& m_string) {
  std::string dataVertex{"0"};
  std::string stringTemp{"Нет"};

  for (unsigned i = 0; i < m_string.length(); i++) {
    if (m_string[i] == '1') {
      if (stringTemp == "Нет") {
        stringTemp = std::to_string((i/2) + 1);
      }
      else {
        stringTemp = stringTemp + " " + std::to_string((i / 2) + 1);
      }
  }
}
  dataVertex = stringTemp;

  return dataVertex;
}


int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  std::string stringTemp ("0");
  unsigned arraySize (0);
  std::ifstream readFromFile("input.txt");

  if (!readFromFile.is_open()) {
    std::cout << "Не получилось открыть файл!" << std::endl;
  }

  getline(readFromFile, stringTemp);
  arraySize = std::stoi(stringTemp);

  std::string* adjacencyArray = new std::string [arraySize];

  ///////--------------------------------------------------------------------
  for (unsigned i = 0; i < arraySize; i++) {
    getline(readFromFile, stringTemp);
    adjacencyArray[i] = std::to_string(i + 1) + ": " + GetDataVertex(stringTemp);
  }

  readFromFile.close();

  std::cout << "Текстовый вид орграфа:" << "\n";

  ///////--------------------------------------------------------------------
  for (unsigned i = 0; i < arraySize; i++) {
    std::cout << adjacencyArray[i] << "\n";
  }

  delete[] adjacencyArray;

  return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#include "02_task_06_1.h"

int main(int argc, char** argv) {

  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  double value1 = 1;

  double value2 = 1;

  ///////------------------------------------------------
  std::cout << "Введите первое число: " << "\t";

  std::cin >> value1;

  std::cout << "Введите второе число:" << "\t";

  std::cin >> value2;

  checkZeroNum_2(value2);

  ///////------------------------------------------------
  enum class listAct {сложение = 1, вычитание, умножение, деление, возведение_в_степень};

  int keyAct = 1;
 
  std::cout << "Выберите операцию (1-сложение, 2-вычитание, 3-умножение, 4-деление, 5-возведение в степень): " << "\t";
  
  std::cin >> keyAct;

  listAct currentAct = static_cast<listAct>(keyAct);

  ///////------------------------------------------------
  switch (currentAct) {

  case listAct::сложение:
    std::cout << value1 << " + " << value2 << " = " << add(value1, value2) << "\n";
    break;

  case listAct::вычитание:
    std::cout << value1 << " - " << value2 << " = " << subtract_1_2(value1, value2) << "\n";
    break;

  case listAct::умножение:
    std::cout << value1 << " * " << value2 << " = " << multiply(value1, value2) << "\n";
    break;

  case listAct::деление:
    std::cout << value1 << " / " << value2 << " = " << divide_1_2(value1, value2) << "\n";
    break;

  case listAct::возведение_в_степень :
    std::cout << value1 << " в степени " << value2 << " = " << raiseToDegree(value1, value2) << "\n";
    break;

  default:
    std::cout << "Неправильный выбор операции!\n";

  }//switch

  return 0;
}

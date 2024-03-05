#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

class Calculator {
 public:
   Calculator() {
     num1 = 1;
     num2 = 1;
   }

   ~Calculator() {}

   double add() {
     return num1 + num2;
   }

   double multiply() {
     return num1 * num2;
   }

   double subtract_1_2() {
     return num1 - num2;
   }

   double subtract_2_1() {
     return num2 - num1;
   }

   double divide_1_2() {
     return num1 / num2;
   }

   double divide_2_1() {
     return num2 / num1;
   }

  bool set_num1(double num_) {
    if (num_ == 0) {
      return 0;
    }
    else {
      num1 = num_;
      return 1;
    }
  }//set_num1

  double get_num1() {
    return num1;
  }

  double get_num2() {
    return num2;
  }

  bool set_num2(double num_) {
    if (num_ == 0) {
      return 0;
    }
    else {
      num2 = num_;
      return 1;
    }
  }//set_num2

 private:
   double num1, num2;
  }; //end of class


int main(int argc, char** argv) {

  setlocale(0, "Rus");

  SetConsoleCP(1251);

  SetConsoleOutputCP(1251);

  double value1, value2;

  Calculator tmpNumber;

  ///////------------------------------------------------
  std::cout << "Введите num1: " << "\t";

  std::cin >> value1;

  while (!tmpNumber.set_num1(value1)) {

    std::cout << "Неверный ввод!" << "\n";

    std::cout << "Введите num1: " << "\t";

    std::cin >> value1;

    tmpNumber.set_num1(value1);
  }

  ///////------------------------------------------------
  std::cout << "Введите num2: " << "\t";

  std::cin >> value2;

  while (!tmpNumber.set_num2(value2)) {

    std::cout << "Неверный ввод!" << "\n";

    std::cout << "Введите num2: " << "\t";

    std::cin >> value2;

    tmpNumber.set_num2(value2);
  }

  ///////------------------------------------------------
  std::cout << "num1 + num2 = " << tmpNumber.add() << "\n";

  std::cout << "num1 - num2 = " << tmpNumber.subtract_1_2() << "\n";

  std::cout << "num2 - num1 = " << tmpNumber.subtract_2_1() << "\n";

  std::cout << "num1 * num2 = " << tmpNumber.multiply() << "\n";

  std::cout << "num1 / num2 = " << tmpNumber.divide_1_2() << "\n";

  std::cout << "num2 / num1 = " << tmpNumber.divide_2_1() << "\n";

  return 0;
}

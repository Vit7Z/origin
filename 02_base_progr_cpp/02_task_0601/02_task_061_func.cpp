#include <iostream>
#include <cmath>

#include "02_task_06_1.h"

/////////////////////////////////////////////////////////////////////
double checkZeroNum_2(double& num) {
  while (num == 0) {
    std::cout << "Неверный ввод второго числа!" << "\n";
    std::cout << "Второе число не должно равняться \"0\"." << "\n";
    std::cout << "Введите второе число:" << "\t";

    std::cin >> num;
  }

  return num;
}

/////////////////////////////////////////////////////////////////////
double add(double num1, double num2) {
  return num1 + num2;
}

/////////////////////////////////////////////////////////////////////
double multiply(double num1, double num2) {
  return num1 * num2;
}

/////////////////////////////////////////////////////////////////////
double subtract_1_2(double num1, double num2) {
  return num1 - num2;
}

/////////////////////////////////////////////////////////////////////
double divide_1_2(double num1, double num2) {
  return num1 / num2;
}

/////////////////////////////////////////////////////////////////////
double raiseToDegree(double num1, double num2) {
  if (num2 == 0) {
    return 1;

  } else {
    return pow(num1, num2);
  }//if
}
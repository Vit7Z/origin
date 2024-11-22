#include <iostream>
#include "figure.h"

void print_info(Figure* figure) {
  figure->printData();
  std::cout << std::endl;
}
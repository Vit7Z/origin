#include <iostream>
#include "figure.h"

Figure::Figure() :Figure("������") {};

Figure::Figure(std::string name_) {
  name = name_;
}

void Figure::printData() {
  std::cout << name << ":" << std::endl;
}
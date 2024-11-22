#include <iostream>
#include "quadrilateral.h"

Quadrilateral::Quadrilateral(unsigned short side_a_, unsigned short side_b_,
  unsigned short side_c_, unsigned short side_d_,
  unsigned short angle_A_, unsigned short angle_B_,
  unsigned short angle_C_, unsigned short angle_D_)
  :Figure() {

  name = "Четырехугольник";
  side_a = side_a_;
  side_b = side_b_;
  side_c = side_c_;
  side_d = side_d_;
  angle_A = angle_A_;
  angle_B = angle_B_;
  angle_C = angle_C_;
  angle_D = angle_D_;
}

void Quadrilateral::printData() {
  std::cout << name << ": " << std::endl;
  std::cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << " d=" << side_d << std::endl;
  std::cout << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << " D=" << angle_D << std::endl;
};
#include <iostream>
#include "scalene_triangle.h"

ScaleneTriangle::ScaleneTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
  unsigned short angle_A_, unsigned short angle_B_, unsigned short angle_C_) :Figure() {

  name = "Треугольник";
  side_a = side_a_;
  side_b = side_b_;
  side_c = side_c_;

  angle_A = angle_A_;
  angle_B = angle_B_;
  angle_C = angle_C_;
}

void ScaleneTriangle::printData() {
  std::cout << name << ": " << std::endl;
  std::cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << std::endl;
  std::cout << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << std::endl;
}
#include "equilateral_triangle.h"

EquilateralTriangle::EquilateralTriangle(unsigned short side_a_)
  :ScaleneTriangle(side_a_, side_b, side_c, angle_A, angle_B, angle_C) {
  name = "Равносторонний треугольник";

  side_a = side_b = side_c = side_a_;
  angle_A = angle_B = angle_C = 60;
};//class
#include <iostream>
#include "right_angled_triangle.h"

RightAngledTriangle::RightAngledTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
  unsigned short angle_A_, unsigned short angle_B_)
  :ScaleneTriangle (side_a_, side_b_, side_c_, angle_A_, angle_B_, angle_C) {
  name = "Прямоугольный треугольник";

  angle_C = 90;
};//class
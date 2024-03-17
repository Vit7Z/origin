#include "isosceles_triangle.h"

IsoscelesTriangle::IsoscelesTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short angle_B_) 
  :ScaleneTriangle(side_a_, side_b_, side_c, angle_A, angle_B_, angle_C) {
  name = "Равнобедренный треугольник";

  side_a = side_c = side_a_;
  side_b = side_b_;
  angle_A = angle_C = 60;
  angle_B = angle_B_;
};//class
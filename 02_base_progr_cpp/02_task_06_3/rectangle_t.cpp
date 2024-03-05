#include "rectangle_t.h"

RectangleT::RectangleT(unsigned short side_a_, unsigned short side_b_)
  :Quadrilateral(side_a_, side_b_, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
  name = "Прямоугольник";

  side_a = side_c = side_a_;
  side_b = side_d = side_b_;
  angle_A = angle_B = angle_C = angle_D = 90;
};//class
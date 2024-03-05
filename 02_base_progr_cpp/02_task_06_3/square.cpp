#include "square.h"

Square::Square(unsigned short side_a_)
  :Quadrilateral(side_a_, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
  name = " вадрат";

  side_a = side_c = side_b = side_d =  side_a_;
  angle_A = angle_B = angle_C = angle_D = 90;
};//class
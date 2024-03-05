#include "parallelogram.h"

Parallelogram::Parallelogram(unsigned short side_a_, unsigned short side_b_,
  unsigned short angle_A_, unsigned short angle_B_) 
  :Quadrilateral(side_a_, side_b_, side_c, side_d, angle_A_, angle_B_, angle_C, angle_D) {
  name = "ֿאנאככוכמדנאלל";

  side_a = side_c = side_a_;
  side_b = side_d = side_b_;
  angle_A = angle_C = angle_A_;
  angle_B = angle_D = angle_B_;
};//class
#include "rhomb.h"

Rhomb::Rhomb(unsigned short side_a_, unsigned short angle_A_, unsigned short angle_B_)
  :Quadrilateral(side_a_, side_b, side_c, side_d, angle_A_, angle_B_, angle_C, angle_D) {
  name = "Ромб";

  side_a = side_c = side_b = side_d = side_a_;
  angle_A = angle_C = angle_A_;
  angle_B = angle_D = angle_B_;
};//class
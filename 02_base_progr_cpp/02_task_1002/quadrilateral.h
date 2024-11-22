#pragma once
#include "figure.h"

class Quadrilateral: public Figure
{
protected:
  unsigned short side_a, side_b, side_c, side_d;
  unsigned short angle_A, angle_B, angle_C, angle_D;

public:
  Quadrilateral(unsigned short side_a_, unsigned short side_b_,
    unsigned short side_c_, unsigned short side_d_,
    unsigned short angle_A_, unsigned short angle_B_,
    unsigned short angle_C_, unsigned short angle_D_);

  ~Quadrilateral() {};

  void printData();
};//class
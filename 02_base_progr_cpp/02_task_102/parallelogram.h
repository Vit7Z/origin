#pragma once
#include "quadrilateral.h"

class Parallelogram :public Quadrilateral
{
public:
  Parallelogram(unsigned short side_a_, unsigned short side_b_,
  unsigned short angle_A_, unsigned short angle_B_);

  ~Parallelogram() {};
};//class
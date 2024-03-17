#pragma once
#include "quadrilateral.h"

class Rhomb :public Quadrilateral
{
public:
  Rhomb(unsigned short side_a_, unsigned short angle_A_, unsigned short angle_B_);

  ~Rhomb() {};
};//class
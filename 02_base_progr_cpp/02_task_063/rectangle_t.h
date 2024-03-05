#pragma once
#include "quadrilateral.h"

class RectangleT:public Quadrilateral
{
public:
  RectangleT(unsigned short side_a_, unsigned short side_b_);

  ~RectangleT() {};
};//class
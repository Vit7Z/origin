#pragma once
#include "quadrilateral.h"

class Square:public Quadrilateral
{
public:
  Square(unsigned short side_a_);

  ~Square() {};
};//class
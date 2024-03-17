#pragma once
#include "scalene_triangle.h"

class IsoscelesTriangle :public ScaleneTriangle
{
public:
  IsoscelesTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short angle_B_);

  ~IsoscelesTriangle() {};
};//class
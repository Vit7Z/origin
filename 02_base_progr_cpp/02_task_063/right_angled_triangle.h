#pragma once
#include "scalene_triangle.h"

class RightAngledTriangle :public ScaleneTriangle
{
public:
  RightAngledTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
  unsigned short angle_A_, unsigned short angle_B_);

  ~RightAngledTriangle() {};
};//class
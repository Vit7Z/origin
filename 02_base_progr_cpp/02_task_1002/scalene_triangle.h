#pragma once
#include "figure.h"

class ScaleneTriangle :public Figure
{
  protected:
    unsigned short side_a, side_b, side_c;
    unsigned short angle_A, angle_B, angle_C;

  public:
    ScaleneTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
    unsigned short angle_A_, unsigned short angle_B_, unsigned short angle_C_);

    ~ScaleneTriangle() {};

    void printData();
};//class
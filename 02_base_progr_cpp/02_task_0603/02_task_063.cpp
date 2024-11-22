#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

#include "equilateral_triangle.h"
#include "figure.h"
#include "isosceles_triangle.h"
#include "parallelogram.h"
#include "print_info.h"
#include "quadrilateral.h"
#include "rectangle_t.h"
#include "rhomb.h"
#include "right_angled_triangle.h"
#include "scalene_triangle.h"
#include "square.h"

//-----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  ScaleneTriangle scTriangle(44, 55, 66, 50, 50, 50);

  RightAngledTriangle raTriangle(10, 20, 30, 50, 60);

  EquilateralTriangle eqTriangle(15);

  IsoscelesTriangle isTriangle(10, 20, 30);

  Parallelogram someParallelogram(21, 31, 20, 30);

  RectangleT someRectangle(20, 30);

  Square someSquare(40);

  Rhomb someRhomb(50, 60, 130);

  Figure fig;
  Figure* pfig = &fig;

  pfig = &scTriangle;
  print_info(pfig);
  
  pfig = &raTriangle;
  print_info(pfig);
  
  pfig = &eqTriangle;
  print_info(pfig);

  pfig = &isTriangle;
  print_info(pfig);

  pfig = &someParallelogram;
  print_info(pfig);

  pfig = &someRectangle;
  print_info(pfig);

  pfig = &someSquare;
  print_info(pfig);

  pfig = &someRhomb;
  print_info(pfig);

  return 0;
}
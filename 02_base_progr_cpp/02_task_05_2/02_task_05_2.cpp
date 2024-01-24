#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

//-----------------------------------------------------------------------------
class Figure {
  protected:
    std::string name;

    Figure(std::string name_) {
      name = name_;
    }

  public:
    virtual void printData() {
      std::cout << name << ":" << std::endl;
    }

    Figure() 
      :Figure("Фигура") {}
};//class


//-----------------------------------------------------------------------------
class ScaleneTriangle :public Figure
{
  protected:
    unsigned short side_a, side_b, side_c;
    unsigned short angle_A, angle_B, angle_C;

  public:
    ScaleneTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
      unsigned short angle_A_, unsigned short angle_B_, unsigned short angle_C_) 
      :Figure() {

      name = "Треугольник";

      side_a = side_a_;
      side_b = side_b_;
      side_c = side_c_;

      angle_A = angle_A_;
      angle_B = angle_B_;
      angle_C = angle_C_;
    }

    void printData() {
      std::cout << name << ": " << std::endl;
      std::cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << std::endl;
      std::cout << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << std::endl;
    }
};//class


//-----------------------------------------------------------------------------
class RightAngledTriangle :public ScaleneTriangle
{
public:
  RightAngledTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
    unsigned short angle_A_, unsigned short angle_B_)
    :ScaleneTriangle (side_a_, side_b_, side_c_, angle_A_, angle_B_, angle_C) {
    name = "Прямоугольный треугольник";

    angle_C = 90;
  }
};//class

//-----------------------------------------------------------------------------
class EquilateralTriangle:public ScaleneTriangle
{
public:
  EquilateralTriangle(unsigned short side_a_)
    :ScaleneTriangle(side_a_, side_b, side_c, angle_A, angle_B, angle_C) {
    name = "Равносторонний треугольник";

    side_a = side_b = side_c = side_a_;
    angle_A = angle_B = angle_C = 60;
  }
};//class

//-----------------------------------------------------------------------------
class IsoscelesTriangle :public ScaleneTriangle
{
public:
  IsoscelesTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short angle_B_) 
    :ScaleneTriangle(side_a_, side_b_, side_c, angle_A, angle_B_, angle_C) {
    name = "Равнобедренный треугольник";

    side_a = side_c = side_a_;
    side_b = side_b_;

    angle_A = angle_C = 60;
    angle_B = angle_B_;
  }
};//class

//-----------------------------------------------------------------------------
class Quadrilateral: public Figure
{
protected:
  unsigned short side_a, side_b, side_c, side_d;
  unsigned short angle_A, angle_B, angle_C, angle_D;

public:
  Quadrilateral(unsigned short side_a_, unsigned short side_b_,
    unsigned short side_c_, unsigned short side_d_, 
    unsigned short angle_A_, unsigned short angle_B_, 
    unsigned short angle_C_, unsigned short angle_D_) 
    :Figure() {

    name = "Четырехугольник";

    side_a = side_a_;
    side_b = side_b_;
    side_c = side_c_;
    side_d = side_d_;

    angle_A = angle_A_;
    angle_B = angle_B_;
    angle_C = angle_C_;
    angle_D = angle_D_;
  }

  void printData() {
    std::cout << name << ": " << std::endl;
    std::cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << " d=" << side_d << std::endl;
    std::cout << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << " D=" << angle_D << std::endl;
  }
};//class


//-----------------------------------------------------------------------------
class Parallelogram :public Quadrilateral
{
public:
  Parallelogram(unsigned short side_a_, unsigned short side_b_,
    unsigned short angle_A_, unsigned short angle_B_) 
    :Quadrilateral(side_a_, side_b_, side_c, side_d, angle_A_, angle_B_, angle_C, angle_D) {
    name = "Параллелограмм";

    side_a = side_c = side_a_;
    side_b = side_d = side_b_;
    angle_A = angle_C = angle_A_;
    angle_B = angle_D = angle_B_;
  }
};//class

//-----------------------------------------------------------------------------
class RectangleT:public Quadrilateral
{
public:
  RectangleT(unsigned short side_a_, unsigned short side_b_)
    :Quadrilateral(side_a_, side_b_, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
    name = "Прямоугольник";

    side_a = side_c = side_a_;
    side_b = side_d = side_b_;
    angle_A = angle_B = angle_C = angle_D = 90;
  }
};//class


//-----------------------------------------------------------------------------
class Square :public Quadrilateral
{
public:
  Square(unsigned short side_a_) 
    :Quadrilateral(side_a_, side_b, side_c, side_d, angle_A, angle_B, angle_C, angle_D) {
    name = "Квадрат";

    side_a = side_c = side_b = side_d =  side_a_;
    angle_A = angle_B = angle_C = angle_D = 90;
  }
};//class


//-----------------------------------------------------------------------------
class Rhomb :public Quadrilateral
{
public:
  Rhomb(unsigned short side_a_, unsigned short angle_A_, unsigned short angle_B_) 
    :Quadrilateral(side_a_, side_b, side_c, side_d, angle_A_, angle_B_, angle_C, angle_D) {
    name = "Ромб";

    side_a = side_c = side_b = side_d = side_a_;
    angle_A = angle_C = angle_A_;
    angle_B = angle_D = angle_B_;
  }
};//class

void print_info(Figure* figure) {
  figure->printData();
  std::cout << std::endl;
}


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

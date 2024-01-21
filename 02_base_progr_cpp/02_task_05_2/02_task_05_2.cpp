#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

//-----------------------------------------------------------------------------
class PolygonT
{
protected:
  std::string name;
  unsigned short numberOfSides;

  unsigned short side_a;
  unsigned short side_b;
  unsigned short side_c;

  unsigned short angle_A;
  unsigned short angle_B;
  unsigned short angle_C;

  PolygonT(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
    unsigned short angle_A_, unsigned short angle_B_, unsigned short angle_C_) {
    name = "Многоугольник";
    numberOfSides = 3;

    side_a = side_a_;
    side_b = side_b_;
    side_c = side_c_;

    angle_A = angle_A_;
    angle_B = angle_B_;
    angle_C = angle_C_;
  }

public:
  PolygonT() :PolygonT(1, 1, 1, 60, 60, 60) {}

  void printData() {
    std::cout << name << ": " << std::endl;
    std::cout << "Стороны: a=" << side_a << " b=" << side_b << " c=" << side_c << std::endl;
    std::cout << "Углы: A=" << angle_A << " B=" << angle_B << " C=" << angle_C << std::endl;
  }
};//class

//-----------------------------------------------------------------------------
class ScaleneTriangle :public PolygonT
{
  public:
    ScaleneTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
      unsigned short angle_A_, unsigned short angle_B_, unsigned short angle_C_) :PolygonT() {
     name = "Треугольник";
     
     side_a = side_a_;
     side_b = side_b_;
     side_c = side_c_;

     angle_A = angle_A_;
     angle_B = angle_B_;
     angle_C = angle_C_;

    }
};//class

//-----------------------------------------------------------------------------
class RightAngledTriangle :public PolygonT
{
public:
  RightAngledTriangle (unsigned short side_a_, unsigned short side_b_, unsigned short side_c_,
    unsigned short angle_A_, unsigned short angle_B_) :PolygonT() {
    name = "Прямоугольный треугольник";

    side_a = side_a_;
    side_b = side_b_;
    side_c = side_c_;

    angle_A = angle_A_;
    angle_B = angle_B_;
    angle_C = 90;
  }
};//class

//-----------------------------------------------------------------------------
class EquilateralTriangle:public PolygonT
{
public:
  EquilateralTriangle(unsigned short side_a_) :PolygonT() {
    name = "Равносторонний треугольник";

    side_a = side_b = side_c = side_a_;

    angle_A = angle_B = angle_C = 60;
  }
};//class

//-----------------------------------------------------------------------------
class IsoscelesTriangle :public PolygonT
{
public:
  IsoscelesTriangle(unsigned short side_a_, unsigned short side_b_, unsigned short angle_B_) :PolygonT() {
    name = "Равнобедренный треугольник";

    side_a = side_c = side_a_;
    side_b= side_b_;

    angle_A = angle_C = 60;
    angle_B = angle_B_;
  }
};//class

//-----------------------------------------------------------------------------
class Quadrilateral
{
protected:
  std::string name;
  unsigned short numberOfSides;

  unsigned short side_a;
  unsigned short side_b;
  unsigned short side_c;
  unsigned short side_d;

  unsigned short angle_A;
  unsigned short angle_B;
  unsigned short angle_C;
  unsigned short angle_D;

  Quadrilateral(unsigned short side_a_, unsigned short side_b_,
    unsigned short side_c_, unsigned short side_d_, 
    unsigned short angle_A_, unsigned short angle_B_, 
    unsigned short angle_C_, unsigned short angle_D_) {

    name = "Четырехугольник";
    numberOfSides = 4;

    side_a = side_a_;
    side_b = side_b_;
    side_c = side_c_;
    side_d = side_d_;

    angle_A = angle_A_;
    angle_B = angle_B_;
    angle_C = angle_C_;
    angle_D = angle_D_;
  }

public:
  Quadrilateral() :Quadrilateral(1, 1, 1, 1, 90, 90, 90, 90) {}

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
    unsigned short angle_A_, unsigned short angle_B_) :Quadrilateral( ) {
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
  RectangleT(unsigned short side_a_, unsigned short side_b_):Quadrilateral() {
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
  Square(unsigned short side_a_) :Quadrilateral() {
    name = "Квадрат";

    side_a = side_c = side_b = side_d =  side_a_;

    angle_A = angle_B = angle_C = angle_D = 90;
  }
};//class


//-----------------------------------------------------------------------------
class Rhomb :public Quadrilateral
{
public:
  Rhomb(unsigned short side_a_, unsigned short angle_A_, unsigned short angle_B_) :Quadrilateral() {
    name = "Ромб";

    side_a = side_c = side_b = side_d = side_a_;

    angle_A = angle_C = angle_A_;
    angle_B = angle_D = angle_B_;
  }
};//class


int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  ScaleneTriangle scTriangle(45, 46, 47, 50, 50, 50);

  RightAngledTriangle raTriangle(10, 20, 30, 50, 60);

  EquilateralTriangle eqTriangle(15);

  IsoscelesTriangle isTriangle(10, 20, 30);

  RectangleT someRectangle(20, 30);

  Parallelogram someParallelogram(20, 30, 20, 30);

  Square someSquare(40);

  Rhomb someRhomb(50, 60, 130);

  scTriangle.printData();
  std::cout << std::endl;

  raTriangle.printData();
  std::cout << std::endl;

  eqTriangle.printData();
  std::cout << std::endl;

  isTriangle.printData();
  std::cout << std::endl;

  someRectangle.printData();
  std::cout << std::endl;

  someParallelogram.printData();
  std::cout << std::endl;

  someSquare.printData();
  std::cout << std::endl;

  someRhomb.printData();
  std::cout << std::endl;

  return 0;
}

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
    unsigned short numberOfSides;

    Figure(std::string name_, unsigned short numberOfSides_) {
      name = name_;
      numberOfSides = numberOfSides_;
    }

  public:
    Figure() :Figure("Фигура", 0) {}

    virtual bool check() {
      if (numberOfSides == 0) {
        return true;
      }
      else {
        return false;
      }
    };

    virtual void print_info() {
      std::cout << std::endl;
      std::cout << name << ":" << std::endl;
      if (check()) {
        std::cout << "Правильная" << std::endl;
      }
      else {
        std::cout << "Неправильная" << std::endl;
      }
      std::cout << "Количество сторон: " << numberOfSides << std::endl;
    }
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
      numberOfSides = 3;

      side_a = side_a_;
      side_b = side_b_;
      side_c = side_c_;

      angle_A = angle_A_;
      angle_B = angle_B_;
      angle_C = angle_C_;
    }

    virtual bool check() override {
      unsigned short sum_of_angle { 0 };
      sum_of_angle = angle_A + angle_B + angle_C;
      
      if (numberOfSides == 3 && sum_of_angle == 180) {
        return true;
      }
      else {
        return false;
      }
    };

    void print_info() {
      Figure::print_info();
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

  virtual bool check() override {
    if (ScaleneTriangle::check() && angle_C == 90) {
      return true;
    }
    else {
      return false;
    }
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

  virtual bool check() override {
    if (ScaleneTriangle::check() && angle_A == 60 && side_a == side_b) {
      return true;
    }
    else {
      return false;
    }
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

  virtual bool check() override {
    if (ScaleneTriangle::check() && angle_A == 60 && side_a == side_c) {
      return true;
    }
    else {
      return false;
    }
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

  virtual bool check() override {
    unsigned short sum_of_angle{ 0 };
    sum_of_angle = angle_A + angle_B + angle_C + angle_D;

    if (numberOfSides == 4 && sum_of_angle == 360) {
      return true;
    }
    else {
      return false;
    }
  };

  void print_info() {
    Figure::print_info();
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

  virtual bool check() override {
    if (Quadrilateral::check() && side_a == side_c && side_b == side_d && 
      angle_A == angle_C && angle_B == angle_D) {
      return true;
    }
    else {
      return false;
    }
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

  virtual bool check() override {
    if (Quadrilateral::check() && side_a == side_c && side_b == side_d &&
      angle_A == 90) {
      return true;
    }
    else {
      return false;
    }
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

  virtual bool check() override {
    if (Quadrilateral::check() && side_a == side_c && angle_A == 90) {
      return true;
    }
    else {
      return false;
    }
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

  virtual bool check() override {
    if (Quadrilateral::check() && side_a == side_c && angle_A == angle_C && 
      angle_B == angle_D) {
      return true;
    }
    else {
      return false;
    }
  }
};//class


int main(int argc, char** argv)
{
  setlocale(0, "Rus");
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  Figure fig;

  ScaleneTriangle scTriangle(44, 55, 66, 50, 50, 50);

  RightAngledTriangle raTriangle(10, 20, 30, 50, 60);

  EquilateralTriangle eqTriangle(15);

  IsoscelesTriangle isTriangle(10, 20, 30);

  Quadrilateral someQuadrilateral (10, 20, 30, 40, 50, 60, 70, 80);

  Parallelogram someParallelogram(21, 31, 20, 30);

  RectangleT someRectangle(20, 30);

  Square someSquare(40);

  Rhomb someRhomb(50, 60, 130);

  fig.print_info();

  Figure* pfig = &fig;
  pfig = &scTriangle;
  scTriangle.print_info();
  
  pfig = &raTriangle;
  raTriangle.print_info();

  pfig = &eqTriangle;
  pfig->print_info();

  pfig = &isTriangle;
  pfig->print_info();

  pfig = &someQuadrilateral;
  pfig->print_info();

  pfig = &someParallelogram;
  pfig->print_info();

  pfig = &someRectangle;
  pfig->print_info();

  pfig = &someSquare;
  pfig->print_info();

  pfig = &someRhomb;
  pfig->print_info();

  return 0;
}
#pragma once
#include <string>

class Figure {
  protected:
    std::string name;
    Figure(std::string name_);

  public:
    Figure();
    ~Figure() {};
    virtual void printData();
};//class
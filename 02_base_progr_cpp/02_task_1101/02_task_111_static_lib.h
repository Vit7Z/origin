#pragma once
#include <string>

class Greeter {
  //protected:
  //  std::string inputStr;
 
  public:
    Greeter() {};
    ~Greeter() {};
    std::string greet(std::string);
};//class
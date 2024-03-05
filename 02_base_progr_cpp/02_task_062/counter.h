#pragma once

class Counter {
 private:
   int num1;

  public:
    Counter();
    Counter(int num1_);
    ~Counter() {};

    void increase();
    void decrease(); 
    int get_num();
  }; //end of class
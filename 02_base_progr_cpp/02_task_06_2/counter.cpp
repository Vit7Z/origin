#include "counter.h"

Counter::Counter(int num1_) {
  num1 = num1_;
}

Counter::Counter() {
  num1 = 1;
}

void Counter::increase() {
  num1++;
}

void Counter::decrease() {
  num1--;
}

int Counter::get_num() {
  return num1;
}
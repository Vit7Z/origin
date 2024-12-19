#include <iostream>
#include "data_class.h"
#include <vector>
#include <Windows.h>
#include <thread>

using namespace std;

void SwapByLock(Data& d_1, Data& d_2) {
  lock(d_1.GetMutex(), d_2.GetMutex());
  lock_guard<mutex> lock_1(d_1.GetMutex(), adopt_lock);
  lock_guard<mutex> lock_2(d_2.GetMutex(), adopt_lock);

  int temp = d_1.GetValue();
  d_1.SetValue(d_2.GetValue());
  d_2.SetValue(temp);

  d_1.GetMutex().unlock();
  d_2.GetMutex().unlock();
}

void SwapByScopedLock(Data& d_1, Data& d_2) {
  scoped_lock lock(d_1.GetMutex(), d_2.GetMutex());

  int temp = d_1.GetValue();
  d_1.SetValue(d_2.GetValue());
  d_2.SetValue(temp);
}

void SwapByUniqueLock(Data& d_1, Data& d_2) {
  unique_lock<mutex> lock_1(d_1.GetMutex(), defer_lock);
  unique_lock<mutex> lock_2(d_2.GetMutex(), defer_lock);
  lock_1.lock();
  lock_2.lock();

  int tmp = d_1.GetValue();
  d_1.SetValue(d_2.GetValue());
  d_2.SetValue(tmp);
}

void PrintData(string str, const Data& d_1, const Data& d_2) {
  cout << str << "\t\t" <<
    "data_1  " << d_1.GetValue() << "    " 
    "data_2  " << d_2.GetValue() << std::endl;
}

int main() {
  setlocale(0, "Rus");

  Data data_1(777);
  Data data_2(999);

  PrintData("Исх. данные:", data_1, data_2);
  SwapByLock(data_1, data_2);
  PrintData("SwapByLock:", data_1, data_2);
  
  PrintData("Исх. данные:", data_1, data_2);
  SwapByScopedLock(data_1, data_2);
  PrintData("SwapByScopedLock:", data_1, data_2);

  PrintData("Исх. данные:", data_1, data_2);
  SwapByUniqueLock(data_1, data_2);
  PrintData("SwapByUniqueLock:", data_1, data_2);
 
  return 0;
}
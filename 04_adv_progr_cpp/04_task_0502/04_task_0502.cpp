//#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class table {
  private:
    int row, col;

    class ArrOfStrings;
    ArrOfStrings* strOfTable; 

    class ArrOfStrings {
      public:
        int* arrOfElements;
        ArrOfStrings() {}

        ArrOfStrings(int size) {
          arrOfElements = new int[size];
          for (int i = 0; i < size; i++) {
            arrOfElements[i] = 0;
          }
        }

        int & operator [] (int i) {
          return arrOfElements[i];
        }
    };

  public:
    table(const int rows, const int cols) {
      if (rows < 1) {
        row = 1;
      }
      else {
        row = rows;
      }

      if (cols < 1) {
        col = 1;
      }
      else {
        col = cols;
      }
      
      strOfTable = new ArrOfStrings [row];

      for (int i = 0; i < row; i++) {
        strOfTable[i] = ArrOfStrings(col);      
      }     
    }
  
    ArrOfStrings & operator [] (int i) {
      return strOfTable[i];
    }

    int GetCol() {
      return col;
    }

    int GetRow() {
      return row;
    }

  ~table() {
    for (int i = 0; i < row; i++) {
      if (strOfTable[i].arrOfElements != nullptr) {
        delete[](strOfTable[i].arrOfElements);
      }
    }

    if (strOfTable != nullptr) {
      delete[] strOfTable;
    }
  }
};

int main() {
  auto test = table<int>(2, 3);
  test[0][0] = 4;
  std::cout << test[0][0];
  return 0;
}
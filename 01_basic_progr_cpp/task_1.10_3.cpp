#include <iostream>
#include <fstream>
#include <string>

unsigned int** create_two_dim_array (unsigned int i_OfArray_, unsigned int j_OfArray_) {

  unsigned int** arrOfStr = new unsigned int* [i_OfArray_];

  for (unsigned int i = 0; i < i_OfArray_; i++) {
    arrOfStr[i] = new unsigned int[j_OfArray_];
  }//for

  return arrOfStr;
}//create_two_dim_array

void fill_two_dim_array (unsigned int** multiplTable_, unsigned int i_OfArray_, unsigned int j_OfArray_) {
    unsigned int k = 1;

    for (unsigned int i = 0; i < i_OfArray_; i++) {

      unsigned int m = 1;

      for (unsigned int j = 0; j < j_OfArray_; j++) {

        *(&multiplTable_[i][j]) = k * m;

        m++;
      }//for

      k++;
    }//for
}//fill_two_dim_array

void print_two_dim_array (unsigned int** multiplTable_, unsigned int i_OfArray_, unsigned int j_OfArray_) {

    for (unsigned int i = 0; i < i_OfArray_; i++) {
            for (unsigned int j = 0; j < j_OfArray_; j++) {

                std::cout << multiplTable_[i][j] << "\t";

    }//for

      std::cout << std::endl;
    }//for
}//print_two_dim_array

void delete_two_dim_array (unsigned int** multiplTable_, unsigned int i_OfArray_, unsigned int j_OfArray_) {

    for (unsigned int i = 0; i < i_OfArray_; i++) {
      delete [] multiplTable_[i];
    }//for

    delete [] multiplTable_;
}//delete_two_dim_array


int main(int argc, char** argv)
{

  static unsigned int i_OfArr, j_OfArr;

  ///////----------------------------------------------------------------------
  std::cout << "Enter the number of rows:" << "\t";

  std::cin >> i_OfArr;

  std::cout << "Enter the number of columns:" << "\t";

  std::cin >> j_OfArr;

  std::cout << std::endl;

  ///////----------------------------------------------------------------------

  unsigned int** multiplTable = create_two_dim_array (i_OfArr, j_OfArr);

  fill_two_dim_array (multiplTable, i_OfArr, j_OfArr);

  print_two_dim_array (multiplTable, i_OfArr, j_OfArr);

  delete_two_dim_array (multiplTable, i_OfArr, j_OfArr);

  return 0;
}

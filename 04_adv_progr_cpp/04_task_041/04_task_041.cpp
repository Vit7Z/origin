#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include <locale.h>

using namespace std;

//-------------------------------------
template <class T>
T my_square(T& a) {
  return a * a;
}

//-------------------------------------
template <>
vector<long> my_square(vector<long>& b) {
  for (size_t i = 0; i < b.size(); ++i) {
    b[i] *= b[i];
  }
  return b;
}

//-------------------------------------
void PrintVector(vector<long> b) {
  for (size_t i = 0; i < (b.size() - 1); ++i) {
    cout << b[i] << ", ";
  }
  cout << b.back() << "\n";
}

//-------------------------------------
int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  int a = 4;
  cout << "[IN]: " << a << "\n";
  cout << "[OUT]: " << my_square(a) << "\n";

  vector<long> vector_1 { -1, 4, 8, -11, 20, 567};
  cout << "[IN]: ";
  PrintVector(vector_1);

  my_square(vector_1);

  cout << "[OUT]: ";
  PrintVector(vector_1);

  return 0;
}
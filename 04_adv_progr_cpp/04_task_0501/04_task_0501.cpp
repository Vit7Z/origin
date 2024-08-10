#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include <locale.h>

using namespace std;

//-------------------------------------
template <class T>
T my_square(const T& a) {
  return a * a;
}

//-------------------------------------
template <>
vector<long> my_square(const vector<long>& b) {
  vector<long> c (b.size());
  for (size_t i = 0; i < b.size(); ++i) {
    c[i] = b[i] * b[i];
  }
  return c;
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

  vector<long> vector_2 = my_square(vector_1);

  cout << "[OUT]: ";
  PrintVector(vector_2);

  return 0;
}
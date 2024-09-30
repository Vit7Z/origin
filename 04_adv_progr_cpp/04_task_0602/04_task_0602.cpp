#include <iostream>
#include <set>
#include <clocale>
#include <algorithm>
    
int main(){
  setlocale(0, "Rus");

  size_t lengthVec{};
  int tmp;
  std::set <int, std::greater<int> > vectorSymb{};

  std::cout << "Длина потока:" << '\t';
  std::cin >> lengthVec;
  
  for (size_t i = 0; i < lengthVec; i++) {
    std::cin >> tmp;
    vectorSymb.insert(tmp);
  }
  
  std::cout << "---------------" << '\n';

  for (const auto& elem : vectorSymb) {
    std::cout << elem << " ";
  }
 
  return 0;
}
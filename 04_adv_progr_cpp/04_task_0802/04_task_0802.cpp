#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <list>
#include <clocale>
#include <algorithm>
#include <fstream>  

//-------------------------------------
template <typename T>
void print_container(const T& m_cont) {
  T::const_iterator i = m_cont.cbegin();
  while (i != m_cont.cend()) {
    std::cout << *i << "  ";
    i++;
  }
  std::cout << '\n';
}

int main(){
  setlocale(0, "Rus");

  std::set <std::string> test_set = {"one", "two", "three", "four"};
  std::list <std::string> test_list = { "one", "two", "three", "four" };
  std::vector <std::string> test_vector = { "one", "two", "three", "four" };

  std::cout << "print (test_set): ";
  print_container (test_set);

  std::cout << "print (test_list): ";
  print_container(test_list);
  
  std::cout << "print (test_vector): ";
  print_container(test_vector);

  return 0;
}
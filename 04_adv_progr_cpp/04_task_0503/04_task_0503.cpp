#include <iostream>
#include <string>
#include <vector>
#include <clocale>

class simple_functor {
  int m_counter;
  int m_sum;

  public:
    simple_functor() : m_counter{ 0 }, m_sum{ 0 } {}

    void operator()(int m_a) {
      if (m_a % 3 == 0) {
        m_counter++;
        m_sum += m_a;
      }
    }
  
    int get_sum() {
      return m_sum;
    };
  
    int get_count() {
      return m_counter;
    };
};

int main() {
  setlocale(0, "Rus");
  
  std::vector<int> vec{1, 12, 7, -9, 4, 33, 2, 1, 3, 6, 25, 54 };
  simple_functor sf;

  for (auto& a : vec) {
    sf(a);
  }

  std::cout << "get_sum() = " << sf.get_sum() << '\n';
  std::cout << "get_count() = " << sf.get_count() << '\n';

  return 0;
}
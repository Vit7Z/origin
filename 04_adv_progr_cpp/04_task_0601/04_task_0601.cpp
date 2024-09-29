#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include <unordered_map>
#include <algorithm>
    

class simple_functor {
  int m_counter;

public:
  simple_functor() : m_counter{ 0 } {}

  void operator()(char& m_letter, char& m_key) {
    if (m_letter == m_key) {
      m_counter++;
      
    }
  }

  int get_count() {
    return m_counter;
  };
};

int main(){
  setlocale(0, "Rus");

  std::string string{ "Hello world!!" };
  std::unordered_map<char, int> stringTmp{};

  for (auto& i : string) {
    simple_functor sf;

    for (auto& j : string) {
      sf (i, j);
    }

    stringTmp[i] = sf.get_count();
  }

  std::vector<std::pair<char, int>> result;

  for (auto& i : stringTmp)
    result.push_back(i);

  std::sort(result.begin(), result.end(),
    [&](std::pair<char, int>& a, std::pair<char, int>& b) 
    { return a.second > b.second; });

  for (auto& [letter, freq] : result) {
    std::cout << letter << ":" << "\t" << freq << std::endl;
  }
    
  return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <clocale>
#include <algorithm>
#include <fstream>    

int main(){
  setlocale(0, "Rus");
  std::vector <int> vectorSymb{};
  std::string tmpStr;
  std::string tmpSym;

  std::cout << "<-- ";

  getline(std::cin, tmpStr, '\n');

  for (int i = 0; i < tmpStr.length(); i++) {

    if (tmpStr[i] != ' ') {
      tmpSym += tmpStr[i];
    }
    else {
      vectorSymb.push_back(stoi(tmpSym));
      tmpSym.clear();
    }

    if ((i + 1) == tmpStr.length()) {
      vectorSymb.push_back(stoi(tmpSym));
    }
  }
  
  //vectorSymb = {11, 22, 33, 11, 56, -33, 44, -33, 44, 789, 900, 33, 900, 11, 22, 11};
  //vectorSymb = { 1, 1, 2, 5, 6, 1, 2, 4};

  std::sort(vectorSymb.begin(), vectorSymb.end());

  auto vectorTmp = std::unique(vectorSymb.begin(), vectorSymb.end());

  vectorSymb.erase(vectorTmp, vectorSymb.end());

  std::cout << "-->  ";

  for (const auto& elem : vectorSymb) {
    std::cout << elem << " ";
  }

  return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>


//-------------------------------------------------------------------------------------
void find_substring_light_rabin_karp(std::string& m_strSource, std::string& m_strKey) {
  int m = m_strKey.size();
  int n = m_strSource.size();
  int i, j;
 
  unsigned long long hashStrSource{ 0 };
  unsigned long long hashStrKey{ 0 };
  unsigned long h{ 1 };
  unsigned long q { 65713 };
  unsigned long d{ 52 };

  for (i = 0; i < m; i++) {
    h = (h * d) % q;
  }

  // Calculate hash value for pattern and text
  for (i = 0; i < m; i++) {
    hashStrSource = (d * hashStrSource + (int)m_strSource[i]) % q;
    hashStrKey = (d * hashStrKey + (int)m_strKey[i]) % q;

    std::cout << "hashStrSource: " << hashStrSource << "\n";
    std::cout << "hashStrKey: " << hashStrKey << "\n";

  }

  // Find the match
  for (i = 0; i < n - m; i++) {
    if (hashStrSource == hashStrKey) {
      for (j = 0; j < m; j++) {
        if (m_strSource[i + j] != m_strKey[j]) {
          break;
        }
      }

      if (j == m)
        std::cout << "Pattern is found at position: " << i + 1 << "\n";
    }

    if (i < n - m) {
      m_strSource = (d * (hashStrSource - m_strSource[i] * h) + m_strSource[i + m]) % q;

      if (hashStrSource < 0) {
        hashStrSource = (hashStrSource + q);
      }
        
    }
  }
}




int main() {

  std::string strSource = "0";
  std::string strKey = "0";
  int hash{ 0 };

  //std::cout << "¬ведите строку, в которой будет осуществл€тьс€ поиск: ";
  //std::cin >> strSource;

  //std::cout << "¬ведите подстроку, которую нужно найти: ";
  //std::cin >> strKey;

  strSource = "hellohellomydearfriend";
  strKey = "hello";


  find_substring_light_rabin_karp(strSource, strKey);
  return 0;
}




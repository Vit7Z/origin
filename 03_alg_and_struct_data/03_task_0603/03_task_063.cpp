#include <iostream>
#include <fstream>
#include <vector>
#include <clocale>
#include <cmath>
#include <locale.h>

//--вычисление хэш для последовательности симоволов----------------------------
signed long getHash(std::string& m_String, size_t m_Strlen) {
  unsigned long long tmp{ 0 };
  unsigned long long hashString{ 0 };

  for (int i = m_Strlen; i > 0; i--) {
    tmp = ((int)m_String[m_Strlen - i] * (unsigned long long)pow(31, i - 1)) % 2147483647;
    hashString += tmp;
  }
  return hashString;
}

//-------------------------------------------------------------------
void find_substring_light_rabin_karp(std::string& m_Key, std::string& m_Seq) {
  unsigned long long hashKey{ 0 };
  unsigned long long hashTmp{ 0 };

  unsigned long long hashPlus{ 0 };
  unsigned long long hashMinus{ 0 };

  size_t m_Keylen = m_Key.length();
  size_t m_Seqlen = m_Seq.length();

  int s{ -1 };
  std::vector<int> positions;

  /////// находим хэш ключа (подстроки) ///////
  hashKey = getHash(m_Key, m_Keylen);

  for (int i = 0; i <= m_Seqlen - m_Keylen; i++) {

    /////// находим хэш последовательности символов в m_Seq длиной ключа ///////
    if (i == 0) {
      hashTmp = getHash(m_Seq, m_Keylen);
    }

    /////// если хэши совпали ///////
    if (hashKey == hashTmp) {
      for (int j = i; j <= i + m_Keylen - 1; j++) {
        if (m_Seq.substr(j, 1) == m_Key.substr(j - i, 1)) {
          s = 0;
        }
      }

      if (s == 0) {
        positions.push_back(i);
      }
    }

    hashMinus = (int)m_Seq[i] * (unsigned long long)pow(31, m_Keylen - 1);
    hashTmp = (hashTmp - hashMinus) * 31;
    hashPlus = (int)m_Seq[i + m_Keylen];
    hashTmp = (hashTmp + hashPlus) % 2147483647;
  }//for

  /////// печать результата ///////
  if (positions.empty()) {
    positions.push_back(-1);
    std::cout << "Подстрока " << m_Key << " не найдена." << "\n";
  }
  else {
    std::cout << "Подстрока найдена (индекс): ";
    for (auto k : positions) {
      std::cout << " " << k << " ";
    }
    std::cout << "\n";
  }
}//find_substring_light_rabin_karp

int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  std::string strKey { "0" };
  std::string strSource { "0" };
  
  std::cout << "Введите строку, в которой будет осуществляться поиск: ";
  std::cin >> strSource;

  while (strKey != "exit") {
    std::cout << "Введите подстроку, которую нужно найти: ";
    std::cin >> strKey;

    if (strSource.size() < strKey.size()) {
      std::cout << "Неправильный ввод: длина подстроки больше длины строки!" << "\n";
    }
    else {
      find_substring_light_rabin_karp(strKey, strSource);
    }
  }

  return 0;
}    
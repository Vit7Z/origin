#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>
#include <unordered_map>



//-------------------------------------------------------------------------------------
size_t calculateHash(std::string m_string)
{
  unsigned long long sum { 0 };
  unsigned long long tmp { 0 };
  unsigned int hash { 0 };
  unsigned int p { 52 };
  unsigned int n { 65713 };

  for (int i = 0; i < m_string.length(); i++) {
    tmp = (int)m_string[i] * (unsigned long long)pow(p, i);
    sum += tmp;
    hash = (unsigned int)(sum % n);
  }
  //std::cout << "hash: " << hash << "\n";
  return hash;
  
}

//-------------------------------------------------------------------------------------
int find_substring_light_rabin_karp(std::string source, std::string substring)
{
  unsigned int position{ 0 };
  unsigned int hashSub{ 0 };
  unsigned int hashTmp{ 0 };
  unsigned int lengthSource = (unsigned int)source.length();
  unsigned int lengthSub = (unsigned int)substring.length();

  hashSub = calculateHash(substring);

  std::cout << "hashSub: " << hashSub << "\n";

  for (int i = 0; i <= source.length() - lengthSub; i++) {

    std::cout << "Строка: " << source.substr(i, lengthSub) << "   ";

    if (i == 0) {
      hashTmp = calculateHash(source.substr(0, lengthSub));
      std::cout << "hashTmp: " << hashTmp << "\n";
    }
    else {
      hashTmp -= calculateHash(source.substr(i - 1, 1));
      hashTmp += calculateHash(source.substr(i - 1 + lengthSub, 1));
      std::cout << "//////: " << hashTmp << "\n";
    }
////
////    if (hashSub != hashTmp) {
////      return i;
////    //}
////    //else {
////    //  for (int j = 0; j <= lengthSub; j++) {
////    //    if 
////    //  }
////
////
////
////    }//if
////    
////
////
  }//for
  return position;
}




int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  std::string strSource = "0";
  std::string strKey = "0";
  int hash {0};

  //std::cout << "Введите строку, в которой будет осуществляться поиск: ";
  //std::cin >> strSource;

  //std::cout << "Введите подстроку, которую нужно найти: ";
  //std::cin >> strKey;

  strSource = "hellohellomydearfriend";
  strKey = "hello";

  //std::cout << "Position: " << find_substring_light_rabin_karp(strSource, strKey);


  find_substring_light_rabin_karp(strSource, strKey);


  return 0;
}
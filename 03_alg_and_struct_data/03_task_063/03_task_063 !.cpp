#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>

//-------------------------------------------------------------------
int GetHash(std::string& m_String, int m_n)
{
  signed long tmp { 0 };
  signed long m_hash { 0 };

  for (int i = 0; i <= m_n; i++) {
    tmp = (signed long)m_String[i] * (signed long)pow(53, i);
    m_hash += tmp;
  }
  return m_hash;
}

//
int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  std::string strSource { "0" };
  std::string strKey { "0" };

  size_t strSourcelen { 0 };
  size_t strKeylen { 0 };

  signed long hashSource { 0 };
  signed long hashKey{ 0 };

  //std::cout << "Введите строку, в которой будет осуществляться поиск: ";
  //std::cin >> strSource;

  //std::cout << "Введите подстроку, которую нужно найти: ";
  //std::cin >> strKey;

  //strSource = "hellohellomydearfriend";
  //strKey = "hello";
  //"rthellohellomydearfriend"
  strSource = "rthellohellomydearfriend";
  strKey = "hello";

  strSourcelen = strSource.length() - 1;
  strKeylen = strKey.length() - 1;

  //std::cout << "strSource.length " << strSourcelen << "\n";
  //std::cout << "strKey.length " << strKeylen << "\n";


  hashSource = GetHash(strSource, strKeylen);
  hashKey = GetHash(strKey, strKeylen);

  std::cout << "Хэш строки strSource: " << hashSource << "\n";
  std::cout << "Хэш строки strKey: " << hashKey << "\n";


  for (int i = 0; i <= strSourcelen - strKeylen; i++) {

    std::cout << i << "    hashSource " << hashSource << "\n";
std::cout << "     " << strSource.substr(i, strKeylen + 1) << "\n";
std::cout << "-" << GetHash(strSource.substr(i, 1), 1) << " для " << strSource.substr(i, 1);
std::cout << "    +" << GetHash(strSource.substr(i + strKeylen, 1), 1) << " для " << strSource.substr(i + strKeylen, 1) << "\n";

    if (hashSource == hashKey) {
      std::cout << "Хэш совпадения " << i << " " << hashSource << "\n";



      //for (int j = i; j <= i + strKeylen; j++) {
      //  //if () {

      //  //}
      //  std::cout << "       " << j << " " << strSource.substr(j, 1) << "\n";
      //}

    }


    hashSource = hashSource - GetHash(strSource.substr(i, 1), 1) + GetHash(strSource.substr(i + strKeylen, 1), 1);
  }
  
  return 0;
}    




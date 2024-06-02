#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>

//-------------------------------------------------------------------
void find_substring_light_rabin_karp(std::string& m_String, std::string& m_Key)
{
  signed long tmp { 0 };
  signed long hashStr{ 0 };
  signed long hashKey{ 0 };

  size_t m_Strlen = m_String.length() - 1;
  size_t m_Keylen = m_Key.length() - 1;

  /////// ������� ��� ����� (���������)
  for (int i = 0; i <= m_Keylen; i++) {
    tmp = (signed long)m_Key[i] * (signed long)pow(53, i);
    hashKey += tmp;

    std::cout << "��� ���������: " << hashKey << "\n";
  }

  tmp = 0;

  /////// ������� ��� ��� ������, ������ �����
  for (int i = 0; i <= m_Keylen; i++) {
    tmp = (signed long)m_String[i] * (signed long)pow(53, i);
    hashStr += tmp;

    std::cout << "��� ������ ������ Key: " << hashStr << "\n";
  }


  for (int i = 1; i <= m_Strlen - m_Keylen; i++) {

    //std::cout << i << "    hashSource " << hashSource << "\n";
    //std::cout << "     " << strSource.substr(i, strKeylen + 1) << "\n";
    //std::cout << "-" << GetHash(strSource.substr(i, 1), 1) << " ��� " << strSource.substr(i, 1);
    //std::cout << "    +" << GetHash(strSource.substr(i + strKeylen, 1), 1) << " ��� " << strSource.substr(i + strKeylen, 1) << "\n";

    //if (hashSource == hashKey) {
    //  std::cout << "��� ���������� " << i << " " << hashSource << "\n";



    //  //for (int j = i; j <= i + strKeylen; j++) {
    //  //  //if () {

    //  //  //}
    //  //  std::cout << "       " << j << " " << strSource.substr(j, 1) << "\n";
    //  //}

    //}


    //hashSource = hashSource - GetHash(strSource.substr(i, 1), 1) + GetHash(strSource.substr(i + strKeylen, 1), 1);
  }



 
}

//
int main(int argc, char** argv)
{
  setlocale(0, "Rus");

  std::string strSource { "0" };
  std::string strKey { "0" };



  //std::cout << "������� ������, � ������� ����� �������������� �����: ";
  //std::cin >> strSource;

  //std::cout << "������� ���������, ������� ����� �����: ";
  //std::cin >> strKey;

  //strSource = "hellohellomydearfriend";
  //strKey = "hello";
  //"rthellohellomydearfriend"
  strSource = "rthellohellomydearfriend";
  strKey = "hello";


  find_substring_light_rabin_karp (strSource, strKey);









  //std::cout << "strSource.length " << strSourcelen << "\n";
  //std::cout << "strKey.length " << strKeylen << "\n";


  //hashSource = GetHash(strSource, strKeylen);
  //hashKey = GetHash(strKey, strKeylen);

  //std::cout << "��� ������ strSource: " << hashSource << "\n";
  //std::cout << "��� ������ strKey: " << hashKey << "\n";


//  for (int i = 0; i <= strSourcelen - strKeylen; i++) {
//
//    std::cout << i << "    hashSource " << hashSource << "\n";
//std::cout << "     " << strSource.substr(i, strKeylen + 1) << "\n";
//std::cout << "-" << GetHash(strSource.substr(i, 1), 1) << " ��� " << strSource.substr(i, 1);
//std::cout << "    +" << GetHash(strSource.substr(i + strKeylen, 1), 1) << " ��� " << strSource.substr(i + strKeylen, 1) << "\n";
//
//    if (hashSource == hashKey) {
//      std::cout << "��� ���������� " << i << " " << hashSource << "\n";
//
//
//
//      for (int j = i; j <= i + strKeylen; j++) {
//        //if () {
//
//        //}
//        std::cout << "       " << j << " " << strSource.substr(j, 1) << "\n";
//      }
//
//    }
//
//
//    hashSource = hashSource - GetHash(strSource.substr(i, 1), 1) + GetHash(strSource.substr(i + strKeylen, 1), 1);
//  }
  
  return 0;
}    




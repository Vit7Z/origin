#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <cmath>
#include <locale.h>

//-----------------------------------------------------------------------------
int hInit(unsigned int strLen) {
  int d = 52;
  int  p = 65713;
 
  int h = 1;
  for(unsigned int i=1; i < strLen; i++) {
    h = (h*d) % p;
  }
 
  return h;
}

//-----------------------------------------------------------------------------
int ringHash(std::string str, unsigned int strLen, int prevHash, int *h) {
  int d = 52; //��������� �� �������
  int  p = 65713; //���������� ������������ �� ������ �������� �����
 
  //h = d^(len-1) (mod p) - ��������� ��� ��������� ��������� ����
  if(*h == 0) { //���� ��������� �� ����������������
    *h = hInit(strLen);
  }
 
  //���� ������� ��� ������ ���
  if(prevHash == 0) {
    for(unsigned int i=0; i<strLen; i++) {
      prevHash += (d*prevHash + (int)str[i]) % p;
    }
    if(prevHash < 0) {
      prevHash += p;
    }
 
    return prevHash;
  }
  //���� ������������� ��� ������� ����
  else {
    int hash = (d * (prevHash - (int)str[0] * (*h)) + (int)str[strLen]) % p;
    if(hash < 0) {
      hash += p;
    }
 
    return hash;
  }
}

//-----------------------------------------------------------------------------
int rabinKarpSearch(std::string text, std::string str) {
  unsigned int strLen = str.size();
  unsigned int textLen = text.size();
  int h = 0;
 
  //��� ��������� ��� ������
  int strHash = ringHash(str, strLen, 0, &h);
  //��� ������� ���� � ������
  int textHash = ringHash(text, strLen, 0, &h);
 
  for(unsigned int k = 0; k <= (textLen-strLen); k++) {
    if(strHash == textHash) {
      //���� ���� �������, ��������� �����������
      for(unsigned int i = 0; (i < strLen) && (str[i] == text[k+i]); i++) {
        if(i == (strLen-1)) {
          return k;
        }
      }
    }
    //��� ���������� ����
    textHash = ringHash(&text[k], strLen, textHash, &h);
  }
  //������ �� �������
  return -1;
}



//-----------------------------------------------------------------------------
 




int main() {

  std::string strSource = "0";
  std::string strKey = "0";
  int hash{ 0 };

  //std::cout << "������� ������, � ������� ����� �������������� �����: ";
  //std::cin >> strSource;

  //std::cout << "������� ���������, ������� ����� �����: ";
  //std::cin >> strKey;

  strSource = "rellohellomydearfriend";
  strKey = "hello";


  std::cout << rabinKarpSearch(strSource, strKey);
  return 0;
}
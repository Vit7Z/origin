#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

struct BankAccount
  {
    unsigned long accountNumber;
    std::string ownerName;     
    double amountOfMoney;
  };

void printBankAccount(BankAccount* BankAccount_) {

  std::cout << "��� ����: ";
  std::cout << BankAccount_->ownerName << ", ";
  std::cout << BankAccount_->accountNumber << ", ";
  std::cout << BankAccount_->amountOfMoney;
  std::cout << std::endl;
}

void changeAmount(BankAccount* BankAccount_, double amountOfMoney_) {

  BankAccount_->amountOfMoney = amountOfMoney_;
}

int main(int argc, char** argv)
{
    setlocale(0, "Rus");

    SetConsoleCP(1251);

    SetConsoleOutputCP(1251);

    BankAccount accountCurrent{1, "����", 0};

    std::cout << "������� ����� �����: ";

    std::cin >> accountCurrent.accountNumber;

    std::cout << "������� ��� ���������: ";

    std::cin >> accountCurrent.ownerName;

    std::cout << "������� ������: ";

    std::cin >> accountCurrent.amountOfMoney;

    std::cout << "������� ����� ������: ";

    double amountOfMoneyNew;

    std::cin >> amountOfMoneyNew;

    changeAmount(&accountCurrent, amountOfMoneyNew);

    printBankAccount (&accountCurrent);

    return 0;
}

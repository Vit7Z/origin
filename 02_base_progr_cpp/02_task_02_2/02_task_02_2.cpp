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

  std::cout << "¬аш счЄт: ";
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

    BankAccount accountCurrent{1, "»ван", 0};

    std::cout << "¬ведите номер счЄта: ";

    std::cin >> accountCurrent.accountNumber;

    std::cout << "¬ведите им€ владельца: ";

    std::cin >> accountCurrent.ownerName;

    std::cout << "¬ведите баланс: ";

    std::cin >> accountCurrent.amountOfMoney;

    std::cout << "¬ведите новый баланс: ";

    double amountOfMoneyNew;

    std::cin >> amountOfMoneyNew;

    changeAmount(&accountCurrent, amountOfMoneyNew);

    printBankAccount (&accountCurrent);

    return 0;
}

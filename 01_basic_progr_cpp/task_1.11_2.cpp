#include <iostream>
#include <string>
#include <locale.h>

int main(int argc, char** argv)
{
  setlocale(0, "Russian");

  std::string TheEnteredWord, TheSearchWord;

  TheSearchWord = "персик";

  while (TheSearchWord != TheEnteredWord)
  {
    std::cout << "Угадайте фрукт: ";

    std::cin >> TheEnteredWord;

    if (TheEnteredWord != TheSearchWord)
    {
      std::cout << "Неправильно. Повторите ввод." << std::endl;
    }
  }

  std::cout << "Правильно! Вы победили! Загаданное слово — " << TheSearchWord << std::endl;

	return 0;
}

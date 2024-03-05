#include <iostream>

int main(int argc, char** argv)
{
  std::string FirstName, LastName;

  std::cout << "¬ведите им€: ";

  std::cin >> FirstName;

  std::cout << "¬ведите фамилию: ";

  std::cin >> LastName;

  std::cout << "«дравствуйте, " << FirstName << " " << LastName;

  std::cout << std::endl;

	return 0;
}

#include <iostream>

int main(int argc, char** argv)
{
  std::string FirstName, LastName;

  std::cout << "������� ���: ";

  std::cin >> FirstName;

  std::cout << "������� �������: ";

  std::cin >> LastName;

  std::cout << "������������, " << FirstName << " " << LastName;

  std::cout << std::endl;

	return 0;
}

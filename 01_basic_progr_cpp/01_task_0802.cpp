#include <iostream>

namespace Addition
{
  int calc(int x, int y)
  {
    return x + y;
  }
}

namespace Subtraction
{
  int calc(int x, int y)
  {
    return x - y;
  }
}

namespace Multiplication
{
  int calc(int x, int y)
  {
    return x * y;
  }
}

namespace Division
{
  int calc(int x, int y)
  {
    return x / y;
  }
}

int main(int argc, char** argv)
{
	int x = 6, y = 9;

	std::cout << "x = " << x << ", " << "y = " << y << std::endl;

	std::cout << "��������: " << Addition::calc (x, y) << std::endl;

	std::cout << "���������: " << Subtraction::calc (x, y) << std::endl;

  std::cout << "���������: " << Multiplication::calc (x, y) << std::endl;

	std::cout << "�������: " << Division::calc (x, y) << std::endl;

	return 0;
}

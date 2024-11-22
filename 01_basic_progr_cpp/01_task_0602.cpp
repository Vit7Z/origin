#include <iostream>

void DegreeOfInt(int value, int power, int result)
{
  for (int i = 0; i < power; i++)
  {
    result *= value;
  }

  std::cout << value << " в степени " << power << " = " << result << std::endl;
}

int main(int argc, char** argv)
{

  DegreeOfInt(5, 2, 1);

  DegreeOfInt(3, 3, 1);

  DegreeOfInt(4, 4, 1);

	return 0;
}

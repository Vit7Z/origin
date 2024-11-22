#include <iostream>

//int counter = 1;

void counting_function()
{
  static int counter;

  std::cout << "Количество вызовов функции counting_function():" << " " << counter << std::endl;

  counter++;
}

int main(int argc, char** argv)
{
  int i;

	for (int i = 0; i < 15; i++)
    {
      counting_function();
    }

	return 0;
}

#include <iostream>

int main(int argc, char** argv)

{
  int Value_1 = 100;

  short Value_2 = 100;

  long Value_3 = 100;

  long long Value_4 = 100;

  float Value_5 = 100.0;

  double Value_6 = 100.0;

  long double Value_7 = 100.0;

  bool Value_8 = 1;

  std::cout << "int: " << &Value_1 << " " << sizeof(Value_1) << std::endl;

  std::cout << "short: " << &Value_2 << " " << sizeof(Value_2) << std::endl;

  std::cout << "long: " << &Value_3 << " " << sizeof(Value_3) << std::endl;

  std::cout << "long long: " << &Value_4 << " " << sizeof(Value_4) << std::endl;

  std::cout << "float: " << &Value_5 << " " << sizeof(Value_5) << std::endl;

  std::cout << "double: " << &Value_6 << " " << sizeof(Value_6) << std::endl;

  std::cout << "long double: " << &Value_7 << " " << sizeof(Value_7) << std::endl;

  std::cout << "bool: " << &Value_8 << " " << sizeof(Value_8) << std::endl;

	return 0;
}

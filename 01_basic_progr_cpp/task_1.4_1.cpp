#include <iostream>
#include <string>

int main() {

  int Sum = 0, Number = 1;

  while (0 != Number)
  {
    std::cout << "������� ����� ����� ��� ����� '0', ����� ���������:\n";

    std::cin >> Number;

    Sum += Number;
}

  std::cout << "�����: " << Sum;

}

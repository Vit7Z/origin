#include <iostream>
#include <string>

int main() {

  int Number_1 = 0, Number_2 = 0, Number_3 = 0;

  int result = 100;

  std::cout << "������� ����� �����, Enter - ��������� �����\n";

  std::cout << "����� 1: ";

  std::cin >> Number_1;

  std::cout << "����� 2: ";

  std::cin >> Number_2;

  std::cout << "����� 3: ";

  std::cin >> Number_3;

  result = Number_1 > Number_2
    ?Number_1 > Number_3
      ?Number_2 > Number_3
        ? 11 : result : result : result;

  result = Number_1 > Number_2
    ?Number_1 > Number_3
      ?Number_3 > Number_2
        ? 12 : result : result : result;

  result = Number_2 > Number_1
    ?Number_2 > Number_3
      ?Number_1 > Number_3
        ? 13 : result : result : result;

  result = Number_2 > Number_1
    ?Number_2 > Number_3
      ?Number_3 > Number_1
        ? 14 : result : result : result;

  result = Number_3 > Number_1
    ?Number_3 > Number_2
      ?Number_1 > Number_2
        ? 15 : result : result : result;

  result = Number_3 > Number_1
    ?Number_3 > Number_2
      ?Number_2 > Number_1
        ? 16 : result : result : result;

  switch (result) {
    case 100:
     std::cout << "��� ����� �����!" << " " << "���������:" << " " << Number_1 << " " << Number_2 << " " << Number_3 << std::endl;
    break;

    case 11:
     std::cout << "���������:" << " " << Number_1 << " " << Number_2 << " " << Number_3 << std::endl;
    break;

    case 12:
     std::cout << "���������:" << " " << Number_1 << " " << Number_3 << " " << Number_2 << std::endl;
    break;

    case 13:
     std::cout << "���������:" << " " << Number_2 << " " << Number_1 << " " << Number_3 << std::endl;
    break;

    case 14:
     std::cout << "���������:" << " " << Number_2 << " " << Number_3 << " " << Number_1 << std::endl;
    break;

    case 15:
     std::cout << "���������:" << " " << Number_3 << " " << Number_1 << " " << Number_2 << std::endl;
    break;

    case 16:
     std::cout << "���������:" << " " << Number_3 << " " << Number_2 << " " << Number_1 << std::endl;
    break;
  }
}

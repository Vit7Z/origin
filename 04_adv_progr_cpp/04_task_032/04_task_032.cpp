#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>
#include<array>

using namespace std; 

//---------------------------------------------------------
class smart_array 
{
	protected:
		int actualSize{ 1 };
		int logicSize{ 0 };
		int* arrNum;

  public:
		smart_array(int actualSize_) {
			actualSize_ = actualSize;
			arrNum = new int[actualSize] {0};
	  }
		
		void add_element(int num_) {
			logicSize += 1;
			if (logicSize >= actualSize) {
				actualSize *= 2;
				int* arrNew{ new int[actualSize] };
				for (int i = 0; i < logicSize; i++) {
					arrNew[i] = arrNum[i];
				}
				arrNum = arrNew;
			}
			arrNum[logicSize - 1] = num_;
		}

		smart_array& operator=(smart_array& arr1)
		{
			for (int i = 0; i < arr1.get_LogicSize(); i++) {
				arrNum[i] = arr1.arrNum[i];
			}
			return *this;
		}

	  int get_element(int num_) {
			if (num_ < 0  > logicSize) {
			return arrNum[num_];
		}

		int get_LogicSize() {
			return logicSize;
		}

		~smart_array() {
			delete[]arrNum;
		}
};//class

//---------------------------------------------------------
int main(int argc, char** argv)
{
	setlocale(0, "Rus");
	smart_array arr(5);
	arr.add_element(1);
	arr.add_element(4);
	arr.add_element(155);

	smart_array new_array(2);
	new_array.add_element(44);
	new_array.add_element(34);

	std::cout << "Массив 1" << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << arr.get_element(i) << "\t";
	}
	std::cout << std::endl;

	//std::cout << "Массив 2" << std::endl;
	//for (int i = 0; i < 2; i++) {
	//	std::cout << new_array.get_element(i) << "\t";
	//}
	//std::cout << std::endl;

	//arr = new_array;

	//std::cout << "Массив сочеленнный" << std::endl;

	//for (int i = 0; i < 5; i++) {
	//	std::cout << arr.get_element(i) << "\t";
	//}

	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

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
				int* arrNew{ new int[actualSize]};
				for (int i = 0; i <= logicSize; i++) {
					arrNew[i] = arrNum[i];
				}
				arrNum = arrNew;
			}
			arrNum[logicSize - 1] = num_;
		}

	  int get_element(int num_) {
			return arrNum[num_];
		}

		~smart_array() {
			delete[]arrNum;
		}
};//class

//---------------------------------------------------------
int main(int argc, char** argv)
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	
	return 0;
}
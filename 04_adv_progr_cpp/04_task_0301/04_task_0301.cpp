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
			actualSize = actualSize_;
			arrNum = new int[actualSize] {0};
	  }

		smart_array(const smart_array&) = delete;
		smart_array& operator=(const smart_array&) = delete;

		void add_element(int num_) {
			logicSize += 1;
			if (logicSize > actualSize) {
				actualSize *= 2;
				int* arrNew{ new int[actualSize] {0} };
				for (int i = 0; i < logicSize - 1; i++) {
					arrNew[i] = arrNum[i];
				}

				*arrNum = *arrNew;
				delete[] arrNew;
			}
			arrNum[logicSize - 1] = num_;
		}

	  int get_element(int num_) {
			try {
				return arrNum[num_];
	    }
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
	    }
		}

		~smart_array() {
			delete[] arrNum;
		}
};//class

//------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	setlocale(0, "Rus");

	try {
		smart_array arr(2);
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
#include <iostream>
#include <thread>
#include <future>
#include <vector>

void SomeFunc(int& a) {
	a *= 2;
}

void ForEach(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	for_each(start, end, SomeFunc);
}

void ParallelForEachFunc(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	int temp = std::distance(start, end);
	if (temp < 2) {
		ForEach(start, end);
	}
	else {
		ForEach(start, end - temp / 2);
		std::async(std::launch::async, ForEach, start + temp / 2, end);
	}
}

void PrintData(std::string str, const std::vector<int>& vec) {
  std::cout << str << " ";
  for (int num : vec) {
    std::cout << num << "\t";
  }
  std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "Rus");

	std::vector<int> arr_1D{ -73, 16, -11, -55, 70, 9, 0, 66, -91, 49, -38, 99 };

  PrintData("До for_each:         ", arr_1D),
		
  ParallelForEachFunc(arr_1D.begin(), arr_1D.end());

  PrintData("После for_each (* 2):", arr_1D);
		 
	return 0;
}
#include <iostream>
#include <vector>
#include <future>

void GetMinByAsync(const std::vector<int>& arr, size_t start, size_t end, std::promise<int>&& promiseObj) {
  int min = arr[start];
  for (size_t i = start + 1; i < end; ++i) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  promiseObj.set_value(min);
}

void SortingByChoice(std::vector<int>& arr) {
  size_t n = arr.size();
  for (size_t i = 0; i < n; ++i) {
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread thread(GetMinByAsync, std::ref(arr), i, n, std::move(promiseObj));

    int min_value = futureObj.get();
    thread.join(); 

    size_t min_index = i;
    for (size_t j = i; j < n; ++j) {
      if (arr[j] == min_value) {
        min_index = j;
        break;
      }
    }
       
    std::swap(arr[i], arr[min_index]);
  }
}

void PrintData(std::string str, const std::vector<int>& vec) {
  std::cout << str << " ";
  for (int num : vec) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

int main() {
  setlocale(0, "Rus");
  
  std::vector<int> arr_1D{ -73, 16, -11, -55, 70, 9, 0, 66, -91, 49, -38, 99 };

  PrintData("До сортировки:   ", arr_1D),
		
  SortingByChoice(arr_1D);

  PrintData("После сортировки:", arr_1D);

  return 0;
}

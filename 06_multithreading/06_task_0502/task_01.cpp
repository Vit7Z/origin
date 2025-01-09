#include <array>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////
// сложение частей двух векторов
int AddingPartsOfVectors(const vector<int>& vec_1, const vector<int>& vec_2, size_t start_vec, size_t end_vec) {
 	int sum{0};

	for (size_t i{ start_vec }; i < end_vec; i++) {
		sum += vec_1[i] + vec_2[i];
	}
	return sum;
}

/////////////////////////////////////////////////////////////////////////////////////////
// получить время вычисления
string GetExecutionTime(const vector<int>& vec_1, const vector<int>& vec_2, const size_t& num_thr) {
	vector<thread> vec_threads(num_thr);
	auto length = vec_1.size() / num_thr;
	auto start = std::chrono::steady_clock::now();

	for (size_t i{ 0 }; i < num_thr; i++) {
		auto start_v = i * length;
		auto end_v = start_v + length;
		if (i + 1 == num_thr) {
			end_v = vec_1.size();
		}
		vec_threads.push_back(thread(AddingPartsOfVectors, ref(vec_1), ref(vec_2), start_v, end_v));
	}

	auto end = std::chrono::steady_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;

	for (auto& t : vec_threads) {
		if (t.joinable()) {
			t.join();
		}
	}
	string elapsed_time = to_string(elapsed_seconds.count()) + "s";
	return elapsed_time;
}

/////////////////////////////////////////////////////////////////////////////////////////
int main() {
	setlocale(0, "Rus");

 //таблица времени выполнения
	array <string, 5> row_1{ "2 threads", "0", "0", "0", "0" };
	array <string, 5> row_2{ "4 threads", "0", "0", "0", "0" };
	array <string, 5> row_3{ "8 threads", "0", "0", "0", "0" };
	array <string, 5> row_4{ "16 threads", "0", "0", "0", "0" };
	array <array<string, 5>, 4> execution_time{ row_1, row_2, row_3, row_4};
	unsigned int j;// индекс столбца времени выполнения

	vector<size_t> num_threads {2, 4, 8, 16}; //вектор потоков
  vector<int> arrA1D (1, 1);// вектора чисел
	vector<int> arrB1D (1, 1);

	arrA1D.resize(1000, 1);// 1000
	arrB1D.resize(1000, 1);
	j = 0;
	for (const auto& i : num_threads) {
		execution_time[j][1] = GetExecutionTime(arrA1D, arrB1D, i);
		j++;
	}

	arrA1D.resize(10000, 1);// 10000
	arrB1D.resize(10000, 1);
	j = 0;
	for (const auto& i : num_threads) {
		execution_time[j][2] = GetExecutionTime(arrA1D, arrB1D, i);
		j++;
	}

	arrA1D.resize(100000, 1);// 100000
	arrB1D.resize(100000, 1);
	j = 0;
	for (const auto& i : num_threads) {
		execution_time[j][3] = GetExecutionTime(arrA1D, arrB1D, i);
		j++;
	}

	arrA1D.resize(1000000, 1);// 1000000
	arrB1D.resize(1000000, 1);
	j = 0;
	for (const auto& i : num_threads) {
		execution_time[j][4] = GetExecutionTime(arrA1D, arrB1D, i);
		j++;
	}

	cout << "Number of cores (g++): " << std::thread::hardware_concurrency() << "\n";
	cout << " " << "\t\t" << "1'000" << "\t\t" << "10'000" << "\t\t" << "100'000" << "\t\t"<<  "1'000'000" << "\n";
  
	for (const auto& i : execution_time) {
		for (auto& j : i) {
			cout << j << "\t";
		}
		cout << "\n";
	}

	return 0;
}
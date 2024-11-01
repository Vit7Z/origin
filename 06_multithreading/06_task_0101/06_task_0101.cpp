#include <iostream>
#include <thread>

using namespace std;

void increase(unsigned int& maxNum, unsigned int& crntNum) {
	while (crntNum < maxNum) {
		this_thread::sleep_for(chrono::seconds(1));
		crntNum++;
		cout << "Число клиентов (+): " << crntNum << std::endl;
	}
}

void decrease(unsigned int& crntNum) {
	while (crntNum > 0) {
		this_thread::sleep_for(chrono::seconds(2));
		crntNum--;
		cout << "Число клиентов (-): " << crntNum << std::endl;
	}
}

int main() {
	setlocale(0, "Rus");

	unsigned int maxNumberClients {10};
	//std::cout << "Введите max количество клиентов: ";
	//std::cin >> maxNumberClients;

	unsigned int currentClients{ 1 };

	cout << "Число клиентов (начало): " << currentClients << std::endl;

	thread t_1(increase, ref(maxNumberClients), ref(currentClients));
	t_1.detach();

	thread t_2(decrease, ref(currentClients));
	t_2.join();

	return 0;
}
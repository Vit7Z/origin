#include <iostream>
#include <mutex>
#include <ratio>
#include <thread>
#include <vector>
#include "Timer.h"

using namespace std;

once_flag flag;
mutex mtx_1;
mutex mtx_2;
mutex mtx_3;

void PrintTableHeaders() {
	cout << 
    "#   " << 
    "id\t" << 
    "   Progress Bar\t" << 
    "                  Time" << endl; 
}

void DrawProgressBar(int number_thread) {
	call_once(flag, PrintTableHeaders);

  int start_bar {11};
  int length { 40 };
  int position_time { 42 };
 
  mtx_1.lock();
  Timer timer_1;
  consol_parameter point_1;
  point_1.SetPosition(0, number_thread + 1);
  cout << number_thread << "   " << this_thread::get_id() << "\t";
  mtx_1.unlock();

  while (start_bar < length)
  {
    this_thread::sleep_for(chrono::milliseconds(20));

    mtx_2.lock();
    point_1.SetPosition(start_bar, number_thread + 1);
    cout << char(178);
    this_thread::sleep_for(chrono::milliseconds(20));
    ++start_bar;
    mtx_2.unlock();
  }
  
  this_thread::sleep_for(chrono::milliseconds(40));

  mtx_3.lock();
  point_1.SetPosition(position_time, number_thread + 1);
  timer_1.print();
  mtx_3.unlock();
}

int main() {
	int N { 5 };
	thread* arr_threads = new thread[N];

	for (size_t i = 0; i < N; i++) {
    arr_threads[i] = thread(DrawProgressBar, i);
	}

  for (size_t i = 0; i < N; i++) {
    arr_threads[i].join();
  }

  consol_parameter::SetPosition(0, 6);
   
	return 0;
}
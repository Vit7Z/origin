#pragma once
#include <mutex>

using namespace std;

class Data {
	private:
	  int value_ {0};
	  mutex mutex_;

  public:
	  Data() = default;
	  Data(int value) : value_(value) {}

	  int GetValue() const;
	  void SetValue (int value);
		mutex& GetMutex();
};
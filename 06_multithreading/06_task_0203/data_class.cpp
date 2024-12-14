#include <iostream>
#include "data_class.h"

int Data::GetValue() const {
	return value_;
}

void Data::SetValue(int value) {
	value_ = value;
}

mutex& Data::GetMutex() {
	return mutex_;
}
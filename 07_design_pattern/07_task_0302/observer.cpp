#include "Observer.h"

Observed& Observed::addObserver(Observer* observer) {
	observers_.push_back(observer);
	return *this;
}

Observed& Observed::removeObserver(Observer* observer) {
	std::cout << "Removed observer: " << observer << std::endl;
	std::vector<Observer*>::iterator it =
		std::remove(observers_.begin(), observers_.end(), observer);
	observers_.erase(it, observers_.end());
	return *this;
}

void Observed::warning(const std::string& message) const {
	for (const auto& i : observers_) {
		i->onWarning(message);
	}
}

void Observed::error(const std::string& message) const {
	for (const auto& i : observers_) {
		i->onError(message);
	}
}

void Observed::fatalError(const std::string& message) const {
	for (const auto& i : observers_) {
		i->onFatalError(message);
	}
}

void ObserverOnWarning::onWarning(const std::string& message) {
	std::cout << "Warning: " << message << " from " << this << std::endl;
}

ObserverOnError::ObserverOnError(const std::string fileName) {
	fout.open(fileName, std::ofstream::app);
	if (!fout.is_open()) {
		std::cout << "ObserverOnError не открыт!" << std::endl;
	}
}

ObserverOnError::~ObserverOnError() {
	fout.close();
}

void ObserverOnError::onError(const std::string& message) {
	fout.seekp(0, std::ios::end);
	fout << "Error: " << message << " from " << this << std::endl;
}

ObserverOnFatalError::ObserverOnFatalError(const std::string fileName) {
	fout.open(fileName, std::ofstream::app);
	if (!fout.is_open()) {
		std::cout << "ObserverOnFatalError не открыт!" << std::endl;
	}
}

ObserverOnFatalError::~ObserverOnFatalError() {
	fout.close();
}

void ObserverOnFatalError::onFatalError(const std::string& message) {
	std::cout << "FatalError: " << message << " from " << this << std::endl;
	fout.seekp(0, std::ios::end);
	fout << "FatalError: " << message << " from " << this << std::endl;
}
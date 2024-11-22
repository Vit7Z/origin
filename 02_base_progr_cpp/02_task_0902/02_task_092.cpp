#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <clocale>
#include <locale.h>
#include <windows.h>
#include <numeric>

//-----------------------------------------------------------------------------
void checkZero(int& num_1_, int num_2_) {
	while (num_1_ == 0) {
		std::cout << "Ошибка! Знаментаель не может быть равным 0!" << "\n";
		std::cout << "Введите знаменатель дроби " << num_2_ << ": ";
		std::cin >> num_1_;
	}//while
}

//-------вычислить НОД---------------------------------------------------------
int calculateGcd(int num1, int num2) {
	if (num1 == 0) {
    return num2;
	}
		
	if (num2 == 0) {
    return num1;
	}

	if (num1 == num2) {
		return num1;
	}

	if (num1 > num2) {
		return calculateGcd(num1 - num2, num2);
	}
		
	return calculateGcd(num1, num2 - num1);
}

//-------вычислить НОК---------------------------------------------------------
int calculateLcm(int num1, int num2) {
	return (num1 * num2 / calculateGcd(num1, num2));
}

//-----------------------------------------------------------------------------
class Fraction {
	private:
		int num_;
	  int denom_;

  public:
	  Fraction(int num_1, int num_2)
		{
		  num_ = num_1;
		  denom_ = num_2;
	  }

		int getNum() {
			return num_;
		}

		int getDenum() {
			return denom_;
		}

		void reduce() {
			int gcd_ = calculateGcd(abs(num_), denom_);
			if (gcd_ != 1) {
				num_ = num_ / gcd_;
				denom_ = denom_ / gcd_;
			}
		}

		std::string printInFraction() {
			std::string fractionIn = std::to_string(num_) + "/" + std::to_string(denom_);
			return fractionIn;
		}

		std::string printOutFraction () {
			reduce();
		  std::string fraction = "";

			if (num_ == 0) {
				fraction = "0";
			}

			if (num_ != 0) {
				if (denom_ != 1) {
					if (num_ % denom_ == 0) {
						fraction = std::to_string(num_ / denom_);
					} else {
            fraction = std::to_string(num_) + "/" + std::to_string(denom_);
					}
				}
				if (denom_ == 1) {
					fraction = std::to_string(num_);
				}
			}
		  return fraction;
		}

		Fraction operator+ (Fraction other) {
			int denomTmp = calculateLcm(denom_, other.denom_);
			int numTmp = (num_ * (denomTmp / denom_)) + (other.num_ * (denomTmp / other.denom_));
			Fraction result = Fraction(numTmp, denomTmp);
			return result;
		}

		Fraction operator- (Fraction other) {
			int denomTmp = calculateLcm(denom_, other.denom_);
			int numTmp = (num_ * (denomTmp / denom_)) - (other.num_ * (denomTmp / other.denom_));
			Fraction result = Fraction(numTmp, denomTmp);
			return result;
		}

		Fraction operator* (Fraction other) {
			int numTmp = num_ * other.num_;
			int denomTmp = denom_ * other.denom_;
			Fraction result = Fraction(numTmp, denomTmp);
			return result;
		}

		Fraction operator/ (Fraction other) {
			int numTmp = num_ * other.denom_;
			int denomTmp = denom_ * other.num_;
			Fraction result = Fraction(numTmp, denomTmp);
			return result;
		}

		//----префикс++------------------------------
		Fraction& operator++() {
			num_ += denom_;
			reduce();
			return *this;
		}

		//----постфикс++-----------------------------
		Fraction operator++(int) {
			Fraction temp = *this;
			++(*this);
			reduce();
			return temp;
		}

		//----префикс--------------------------------
		Fraction& operator--() {
			num_ -= denom_;
			reduce();
			return *this;
		}

		//----постфикс-------------------------------
		Fraction operator--(int) {
			Fraction temp = *this;
			--(*this);
			reduce();
			return temp;
		}
};//class

int main(int argc, char** argv) 
{
	setlocale(0, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int numerator_1 = 1;
	int denominator_1 = 1;
	int numerator_2 = 1;
	int denominator_2 = 1;

	int gcd;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator_1;

	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator_1;
	checkZero(denominator_1, 1);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator_2;

	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator_2;
	checkZero(denominator_2, 2);

	Fraction f1(numerator_1, denominator_1);
	Fraction f2(numerator_2, denominator_2);

	Fraction sumFraction = f1 + f2;

	Fraction subtrFraction = f1 - f2;

	Fraction multiplFraction = f1 * f2;

	Fraction divFraction = f1 / f2;

	std::cout << f1.printInFraction() << " + " << f2.printInFraction() << " = " << sumFraction.printOutFraction();

	std::cout << "\n";

	std::cout << f1.printInFraction() << " - " << f2.printInFraction() << " = " << subtrFraction.printOutFraction();

	std::cout << "\n";

	std::cout << f1.printInFraction() << " * " << f2.printInFraction() << " = " << multiplFraction.printOutFraction();

	std::cout << "\n";

	std::cout << f1.printInFraction() << " / " << f2.printInFraction() << " = " << divFraction.printOutFraction();

	std::cout << "\n";

  Fraction compos_pre = ++f1 * f2;

	compos_pre.reduce();

	--f1;

	std::cout << "++" << f1.printInFraction() << " * " << f2.printInFraction() << " = " << compos_pre.printOutFraction() << "\n";

	++f1;

	std::cout << "Значение дроби 1 -> "  << f1.printInFraction() << "\n";

	Fraction compos_post = f1-- * f2;

	++f1;

	std::cout << f1.printInFraction() << "-- * " << f2.printInFraction() << " = " << compos_pre.printOutFraction() << "\n";

	f1--;

	std::cout << "Значение дроби 1 -> " << f1.printInFraction() << "\n";

  return 0;
}
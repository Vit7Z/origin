#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <locale.h>
#include <windows.h>

class Fraction {
	private:
		int numerator_;
	  int denominator_;

  public:
	  Fraction(int numerator, int denominator) 
		{
		  numerator_ = numerator;
		  denominator_ = denominator;
	  }

		double decimalFraction() {
			return static_cast<double>(numerator_) / static_cast<double>(denominator_);
		}

		bool operator== (Fraction otherFraction_) {
			return decimalFraction() == otherFraction_.decimalFraction();
		}

		bool operator!= (Fraction otherFraction_) {
			return !(*this == otherFraction_);
		}

		bool operator> (Fraction otherFraction_) {
			return decimalFraction() > otherFraction_.decimalFraction();
		}

		bool operator< (Fraction otherFraction_) {
			return otherFraction_.decimalFraction() > decimalFraction();
		}

		bool operator>= (Fraction otherFraction_) {
			return !(*this < otherFraction_);
		}

		bool operator<= (Fraction otherFraction_) {
			return !(*this > otherFraction_);
		}

		std::string printFraction () {
			return std::to_string(numerator_) + "/" + std::to_string(denominator_);
		}
};

int main(int argc, char** argv) 
{
	setlocale(0, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "Дробь f1: " << f1.printFraction() << ". " << 
		           "Эквивалент десятичной дроби: " << f1.decimalFraction() << std::endl;
	
	std::cout << "Дробь f2: " << f2.printFraction() << ". " <<
		           "Эквивалент десятичной дроби: " << f2.decimalFraction() << std::endl;

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

  return 0;
}

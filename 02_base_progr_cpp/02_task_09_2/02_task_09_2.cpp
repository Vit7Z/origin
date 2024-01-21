#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <clocale>
#include <locale.h>
#include <windows.h>

//-----------------------------------------------------------------------------
void checkZero(int& num_1_, int num_2_) {
	while (num_1_ == 0) {
		std::cout << "Ошибка! Знаментаель не может быть равным 0!" << "\n";
		std::cout << "Введите знаменатель дроби " << num_2_ << ": ";
		std::cin >> num_1_;
	}//while
}

//НОД--------------------------------------------------------------------------
int calculateGcd(int num1, int num2) {
	while (num2 > 0) {
		int tmp = num1 % num2;
		num1 = num2;
		num2 = tmp;
	}
	return num1;
}

//НОК--------------------------------------------------------------------------
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

		//-------------------------------------------
		void reduce() {
			int gcd_ = calculateGcd(abs(num_), denom_);

			if (gcd_ != 1) {
				num_ = num_ / gcd_;
				denom_ = denom_ / gcd_;
			}
		}

		//-------------------------------------------
		std::string printFraction () {
			return std::to_string(num_) + "/" + std::to_string(denom_);
		}

		//-------------------------------------------
		Fraction operator+ (Fraction other) {
			int commonDenum = calculateLcm(denom_, other.denom_);
			int tmp_res = (num_ * (commonDenum / denom_)) + (other.num_ * (commonDenum / other.denom_));
			Fraction result = Fraction(tmp_res, commonDenum);
			reduce();
			return result;
		}


		//-------------------------------------------
		Fraction operator- (Fraction other) {
			//int commonDenum;

			if (num_ == other.num_ && denom_ == other.denom_) {
				int commonDenum = 0;
				int tmp_res = 0;
				Fraction result = Fraction(tmp_res, commonDenum);
				return result;
			}

			if (num_ != other.num_ && denom_ == other.denom_) {
				int commonDenum = denom_;
				int tmp_res = num_ - other.num_;
				Fraction result = Fraction(tmp_res, commonDenum);
				reduce();
				return result;
			}

			if (num_ != other.num_ && denom_ != other.denom_) {
				int commonDenum = calculateLcm(denom_, other.denom_);
				int tmp_res = (num_ * (commonDenum / denom_)) - (other.num_ * (commonDenum / other.denom_));
				Fraction result = Fraction(tmp_res, commonDenum);
				reduce();
				return result;
			}
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

	//std::cout << "Введите числитель дроби 1: ";
	//std::cin >> numerator_1;

	//std::cout << "Введите знаменатель дроби 1: ";
	//std::cin >> denominator_1;
	//checkZero(denominator_1, 1);

	//std::cout << "Введите числитель дроби 2: ";
	//std::cin >> numerator_2;

	//std::cout << "Введите знаменатель дроби 2: ";
	//std::cin >> denominator_2;
	//checkZero(denominator_2, 2);


	//Fraction f1(numerator_1, denominator_1);
	//Fraction f2(numerator_2, denominator_2);

	Fraction f1(1, 2);
	Fraction f2(1, 2);


	//Fraction f1(3, 4);
	//Fraction f2(4, 5);


	Fraction sumFraction = f1 + f2;

	//sumFraction.reduce();

	//Fraction subtrFraction = f1 - f2;

	//subtrFraction.reduce();



	std::cout << f1.printFraction() << " + " << f2.printFraction() << " = " << sumFraction.printFraction();

	std::cout << "\n";

	//std::cout << f1.printFraction() << " - " << f2.printFraction() << " = " << subtrFraction.printFraction();


  return 0;
}

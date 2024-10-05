#include <iostream>
#include "Fraction.h"
using namespace std;

//НОД
int Fraction::gcd(int value_numerator, int value_denominator)
{
	while (value_denominator != 0)
	{
		int temp = value_denominator;
		value_denominator = value_numerator % value_denominator;
		value_numerator = temp;
	}
	return value_numerator;

}
// сокращение дроби
void Fraction::fraction_reduction()
{
	int gc = gcd(numerator, denominator);
	numerator /= gc;
	denominator /= gc;
}
void Fraction::SetNumerator(int value)
{
	numerator = value;
}
int Fraction::GetNumerator()
{
	return numerator;
}
void Fraction::SetDenominator(int value)
{
	denominator = value;
}
int Fraction::GetDenominator()
{
	return denominator;
}
void Fraction::SetSign(bool value) {
	sign = value;
}
int Fraction::GetSign()
{
	return sign;
}
int Fraction::GetInteger()
{
	int integer = numerator / denominator;
	return integer;
}
double Fraction::GetDouble()
{
	return numerator / (1.0 * denominator);
}
void Fraction::show()
{
	if (sign) cout << numerator << "/" << denominator << endl;
	else cout << (-1) * numerator << "/" << denominator << endl;
}

//конструктор_1
Fraction::Fraction(int value_numerator, int value_denominator, bool value_sign)
	: numerator(value_numerator), denominator(value_denominator), sign(value_sign), integer_num(0)
{
	if (value_numerator <= 0 || value_denominator <= 0)
	{
		throw invalid_argument("Аргументы для дроби должны быть натуральными числами."); 
	}
	fraction_reduction();
}
//конструктор_2
Fraction::Fraction(int value_integer)
	: numerator(value_integer), denominator(1), sign(true), integer_num(value_integer)
{
	fraction_reduction(); 
}
//Конструктор копирования_3
Fraction::Fraction(const Fraction& other)
	: numerator(other.numerator), denominator(other.denominator), sign(other.sign), integer_num(other.integer_num)
{
}

//Перегрузка присваивания =
Fraction& Fraction::operator=(const Fraction& other)
{
	if (this == &other)
		return *this;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->sign = other.sign;
	this->integer_num = other.integer_num;
}
// Перегрузка ==
bool Fraction::operator==(const Fraction& other) const
{
	return (this->numerator == other.numerator &&
		this->denominator == other.denominator &&
		this->sign == other.sign);
}

// Перегрузка !=
bool Fraction::operator!=(const Fraction& other) const
{
	return !(*this == other);
}

//Перегрузка + (дробь + дробь)
Fraction Fraction::operator+(const Fraction& other) const {
	Fraction result(1, 1, true);
	if (this->denominator == other.denominator)
	{
		result.numerator = (this->sign ? this->numerator : -this->numerator) + (other.sign ? other.numerator : -other.numerator);
		result.denominator = this->denominator;
	}
	else 
	{
		result.numerator = (this->sign ? this->numerator : -this->numerator) * other.denominator + (other.sign ? other.numerator : -other.numerator) * this->denominator;
		result.denominator = this->denominator * other.denominator;
	}
	if (result.numerator < 0) 
	{
		result.numerator *= -1;
		result.sign = false; 
	}
	else 
	{
		result.sign = true; 
	}
	result.fraction_reduction();
	return result;
}
//Перегрузка += (дробь += дробь)
Fraction& Fraction::operator+=(const Fraction& other)
{
	int signed_numerator = this->sign ? this->numerator : -this->numerator;
	int signed_other_numerator = other.sign ? other.numerator : -other.numerator;
	if (this->denominator == other.denominator)
	{
		this->numerator = signed_numerator + signed_other_numerator;
	}
	else
	{
		this->numerator = signed_numerator * other.denominator + signed_other_numerator * this->denominator;
		this->denominator = this->denominator * other.denominator;
	}
	if (this->numerator < 0)
	{
		this->numerator *= -1;
		this->sign = false;
	}
	else
	{
		this->sign = true;
	}
	fraction_reduction();
	return *this;
}
//Перегрузка + (дробь + целое)
Fraction Fraction::operator+(int value_integer_number) const 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	Fraction result = *this + integer_number;
	result.fraction_reduction();
	return result;
}
//Перегрузка + (целое + дробь)
Fraction operator+(int value_integer_number, const Fraction& fraction) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	Fraction result = integer_number + fraction;
	result.fraction_reduction();
	return result;
}
//Перегрузка += (дробь += целое)
Fraction& Fraction::operator+=(int value_integer_number)
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	*this = *this + integer_number;
	fraction_reduction();
	return *this;
}

//Перегрузка - (дробь - дробь)
Fraction Fraction::operator-(const Fraction& other) const 
{
	Fraction result(1, 1, true);
	int signed_numerator = this->sign ? this->numerator : -this->numerator;
	int signed_other_numerator = other.sign ? other.numerator : -other.numerator;
	if (this->denominator == other.denominator) 
	{
		result.numerator = signed_numerator - signed_other_numerator;
		result.denominator = this->denominator;
	}
	else 
	{
		result.numerator = signed_numerator * other.denominator - signed_other_numerator * this->denominator;
		result.denominator = this->denominator * other.denominator;
	}
	if (result.numerator < 0) {
		result.numerator *= -1;
		result.sign = false;
	}
	else
	{
		result.sign = true;
	}
	result.fraction_reduction();
	return result;
}
//Перегрузка -= (дробь -= дробь)
Fraction& Fraction::operator-=(const Fraction& other)
{
	int signed_numerator = this->sign ? this->numerator : -this->numerator;
	int signed_other_numerator = other.sign ? other.numerator : -other.numerator;
	if (this->denominator == other.denominator)
	{
		this->numerator = signed_numerator - signed_other_numerator;
	}
	else
	{
		this->numerator = signed_numerator * other.denominator - signed_other_numerator * this->denominator;
		this->denominator = this->denominator * other.denominator;
	}
	if (this->numerator < 0)
	{
		this->numerator *= -1;
		this->sign = false;
	}
	else
	{
		this->sign = true;
	}
	fraction_reduction();
	return *this;
}
//Перегрузка - (дробь - целое)
Fraction Fraction::operator-(int value_integer_number) const 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	Fraction result = *this - integer_number;
	result.fraction_reduction();
	return result;
}
//Перегрузка - (целое - дробь)
Fraction operator-(int value_integer_number, const Fraction& fraction) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	Fraction result = integer_number - fraction;
	result.fraction_reduction();
	return result;
}
//Перегрузка -= (дробь -= целое)
Fraction& Fraction::operator-=(int value_integer_number)
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	*this = *this - integer_number;
	fraction_reduction();
	return *this;
}

// Перегрузка * (дробь * дробь)
Fraction Fraction::operator*(Fraction& other)
{
	Fraction result(1, 1, true);
	result.numerator = this->numerator * other.numerator;
	result.denominator = this->denominator * other.denominator;

	result.sign = (this->sign == other.sign);
	result.fraction_reduction();
	return result;
}
// Перегрузка *= (дробь *= дробь)
Fraction& Fraction::operator*=(const Fraction& other) 
{
	this->numerator = this->numerator * other.numerator;
	this->denominator = this->denominator * other.denominator;
	this->sign = (this->sign == other.sign);
	fraction_reduction();
	return *this;
}
// Перегрузка * (дробь * целое)
Fraction Fraction::operator*(int value_integer_number) 
{
	Fraction integer_number(value_integer_number);
	return *this * integer_number;
}
// Перегрузка * (целое * дробь)
Fraction operator*(int value_integer_number, Fraction& fraction) 
{
	Fraction integer_number(value_integer_number);
	return integer_number * fraction;
}
// Перегрузка *= (дробь *= целое)
Fraction& Fraction::operator*=(int value_integer_number) 
{
	Fraction integer_number(value_integer_number);
	*this *= integer_number;
	return *this;
}


// Перегрузка / (дробь / дробь)
Fraction Fraction::operator/(Fraction& other)
{
	if (other.numerator == 0) 
	{
		throw invalid_argument("Деление на ноль.");
	}
	Fraction result(1, 1, true);
	result.numerator = this->numerator * other.denominator;
	result.denominator = other.numerator * this->denominator;
	result.sign = (this->sign == other.sign);
	result.fraction_reduction();
	return result;
}
// Перегрузка /= (дробь /= дробь)
Fraction& Fraction::operator/=(const Fraction& other) 
{
	if (other.numerator == 0) 
	{
		throw invalid_argument("Деление на ноль.");
	}
	this->numerator = (this->sign ? this->numerator : -this->numerator) * (other.sign ? other.denominator : -other.denominator);
	this->denominator = (other.sign ? other.numerator : -other.numerator) * this->denominator;
	if (this->denominator < 0) this->denominator = this->denominator * (-1);
	this->sign = (this->sign == other.sign);
	fraction_reduction();
	return *this;
}
// Перегрузка / (дробь / целое)
Fraction Fraction::operator/(int value_integer_number) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return *this / integer_number;
}
// Перегрузка / (целое / дробь)
Fraction operator/(int value_integer_number, Fraction& fraction) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return integer_number / fraction;
}
// Перегрузка /= (дробь /= целое)
Fraction& Fraction::operator/=(int value_integer_number) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	*this /= integer_number;
	return *this;
}

// Перегрузка > (дробь > дробь)
bool Fraction::operator>(const Fraction& other) const 
{
	int l_numerator = (this->sign ? this->numerator : -this->numerator) * other.denominator;
	int r_numerator = (other.sign ? other.numerator : -other.numerator) * this->denominator;
	return l_numerator > r_numerator;
}
// Перегрузка < (дробь < дробь)
bool Fraction::operator<(const Fraction& other) const 
{
	int l_numerator = (this->sign ? this->numerator : -this->numerator) * other.denominator;
	int r_numerator = (other.sign ? other.numerator : -other.numerator) * this->denominator;
	return l_numerator < r_numerator;
}
// Перегрузка >= (дробь >= дробь)
bool Fraction::operator>=(const Fraction& other)
{
	return !(*this < other);
}
// Перегрузка <= (дробь <= дробь)
bool Fraction::operator<=(const Fraction& other) 
{
	return !(*this > other);
}


// Перегрузка > (дробь > целое)
bool Fraction::operator>(int value_integer_number) const 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return *this > integer_number; 
}
// Перегрузка > (целое > дробь)
bool operator>(int value_integer_number, const Fraction& fraction) {
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return integer_number > fraction; 
}
// Перегрузка < (дробь < целое)
bool Fraction::operator<(int value_integer_number) const 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return *this < integer_number;
}
// Перегрузка < (целое < дробь)
bool operator<(int value_integer_number, const Fraction& fraction) {
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return integer_number < fraction;
}

// Перегрузка >= (дробь >= целое)
bool Fraction::operator>=(int value_integer_number) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return *this >= integer_number; 
}
// Перегрузка >= (целое >= дробь)
bool operator>=(int value_integer_number, const Fraction& fraction) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return integer_number >= fraction; 
}
// Перегрузка <= (дробь <= целое)
bool Fraction::operator<=(int value_integer_number) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return *this <= integer_number; 
}
// Перегрузка <= (целое <= дробь)
bool operator<=(int value_integer_number, const Fraction& fraction) 
{
	Fraction integer_number(value_integer_number, 1, value_integer_number >= 0);
	return integer_number <= fraction; 
}

// Перегрузка ++ (постфиксный инкремент)
Fraction& Fraction::operator++() 
{
	Fraction one(1, 1, true);
	*this = *this + one;
	return *this;
}
// Перегрузка -- (постфиксный декремент)
Fraction& Fraction::operator--() 
{
	Fraction one(1, 1, true);
	*this = *this - one;
	return *this;
}
//Перегрузка дробь++
Fraction& Fraction::operator++(int value)
{
	Fraction temp(*this);
	Fraction one(1, 1, true);
	*this = *this + one;
	return temp;
}
//Перегрузка дробь --
Fraction& Fraction::operator--(int value)
{
	Fraction temp(*this);
	Fraction one(1, 1, true);
	*this = *this - one;
	return temp;
}

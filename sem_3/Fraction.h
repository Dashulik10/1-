#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <algorithm>

using namespace std;


class Fraction
{
private:
	int numerator;
	int denominator;
	bool sign;
	int integer_num;

	int gcd(int, int); 

	void fraction_reduction();

public:
	void SetNumerator(int);
	int GetNumerator();
	void SetDenominator(int);
	int GetDenominator();
	void SetSign(bool);
	int GetSign();
	int GetInteger();
	double GetDouble();
	void show();


	Fraction(int value_numerator, int value_denominator, bool value_sign);
	Fraction(int value_integer);
	Fraction(const Fraction& other);


	Fraction& operator = (const Fraction& other);
	
	bool operator == (const Fraction& other) const;

	bool operator != (const Fraction& other) const;

	
	Fraction operator+(const Fraction& other) const;
	
	Fraction& operator+=(const Fraction& other);
	
	Fraction operator+(int) const;
	
	friend Fraction operator+(int, const Fraction& fraction);

	Fraction& operator+=(int);

	
	Fraction operator-(const Fraction& other) const;
	
	Fraction& operator-=(const Fraction& other);

	Fraction operator-(int) const;
	
	friend Fraction operator-(int, const Fraction& fraction);

	Fraction& operator-=(int);

	
	Fraction operator*(Fraction& other);
	
	Fraction& operator*=(const Fraction& other);

	Fraction operator*(int);
	
	friend Fraction operator*(int, Fraction& fraction);

	Fraction& operator*=(int);


	Fraction operator/(Fraction& other);

	Fraction& operator/=(const Fraction& other);
	
	Fraction operator/(int);
	
	friend Fraction operator/(int, Fraction& fraction);
	
	Fraction& operator/=(int);

	
	bool operator > (const Fraction& other) const;
	
	bool operator < (const Fraction& other) const;

	bool operator >= (const Fraction& other);

	bool operator <= (const Fraction& other);


	bool operator>(int value_integer_number) const;

	friend bool operator>(int value_integer_number, const Fraction& fraction);


	bool operator<(int value_integer_number) const;

	friend bool operator<(int value_integer_number, const Fraction& fraction);

	bool operator>=(int value_integer_number);

	friend bool operator>=(int value_integer_number, const Fraction& fraction);

	bool operator<=(int value_integer_number);

	friend bool operator<=(int value_integer_number, const Fraction& fraction);


	Fraction& operator++();
	Fraction& operator--();

	Fraction& operator++(int);
	Fraction& operator--(int);

};

#endif 


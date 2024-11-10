#ifndef DATE_H 
#define DATE_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);
	Date();

	string getDayMonthYear() const;
	int getDay();
	int getMonth();
	int getYear();

	bool operator == (const Date& other) const;
	bool operator!=(const Date& other) const;
	bool operator > (const Date& other) const;
	bool operator < (const Date& other) const;
	bool operator >= (const Date& other) const;
	bool operator <= (const Date& other) const;

	static const int days_per_month[12];

	static bool isLeapYear(int year);
	static int daysInMonth(int month, int year);
	Date operator-(const Date& other) const;
	Date operator+(int days) const;

	Date& operator=(const Date& other);
};

#endif
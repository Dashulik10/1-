#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);

	string getDayMonthYear() const;
};
#endif
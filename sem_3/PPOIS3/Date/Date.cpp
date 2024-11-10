#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include <regex>
using namespace std;

Date::Date(int day, int month, int year)
{
    if (year < 1 || month < 1 || month > 12 || day < 1 ||
        (month == 2 && (day > (isLeapYear(year) ? 29 : 28))) ||
        ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) ||
        (day > 31)) throw invalid_argument("Invalid date");

    this->day = day;
    this->month = month;
    this->year = year;
}
Date::Date() : day(1), month(1), year(2000) {}

string Date::getDayMonthYear() const { return "Date: " + to_string(day) + "/" + to_string(month) + "/" + to_string(year); }
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

bool Date::operator==(const Date& other) const
{
    return (this->day == other.day &&
        this->month == other.month &&
        this->year == other.year);
}
bool Date::operator!=(const Date& other) const { return !(*this == other); }
bool Date::operator>(const Date& other) const
{
    if (this->year != other.year) return this->year > other.year;
    if (this->month != other.month) return this->month > other.month;
    return this->day > other.day;
}
bool Date::operator<(const Date& other) const
{
    if (this->year != other.year) return this->year < other.year;
    if (this->month != other.month) return this->month < other.month;
    return this->day < other.day;
}
bool Date::operator>=(const Date& other) const { return (*this > other) || (*this == other); }
bool Date::operator<=(const Date& other) const { return (*this < other) || (this->year == other.year && this->month == other.month && this->day == other.day); }
Date Date::operator-(const Date& other) const
{
    Date result = *this;
    int totalDaysThis = (this->year * 365) + this->day + (this->month > 2 ? (this->month - 1) * 30 : (this->month - 1) * 30 - (this->month - 1) / 2);
    int totalDaysOther = (other.year * 365) + other.day + (other.month > 2 ? (other.month - 1) * 30 : (other.month - 1) * 30 - (other.month - 1) / 2);

    int dayDifference = totalDaysThis - totalDaysOther;

    result.year = dayDifference / 365;
    int remainingDays = dayDifference % 365;

    result.month = remainingDays / 30;
    result.day = remainingDays % 30;

    return result;
}
Date Date::operator+(int days) const
{
    Date result = *this;
    while (days > 0)
    {
        int days_in_current_month = daysInMonth(result.month, result.year);

        if (result.day + days <= days_in_current_month)
        {
            result.day += days;
            days = 0;
        }
        else
        {
            days -= (days_in_current_month - result.day + 1);
            result.day = 1;
            if (result.month == 12)
            {
                result.month = 1;
                result.year++;
            }
            else
            {
                result.month++;
            }
        }
    }
    return result;
}
Date& Date::operator=(const Date& other)
{
    if (this != &other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }
    return *this;
}

const int Date::days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool Date::isLeapYear(int year) { return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0); }
int Date::daysInMonth(int month, int year)
{
    if (month < 1 || month > 12) throw invalid_argument("Month must be between 1 and 12.");
    return (month == 2) ? (Date::isLeapYear(year) ? 29 : 28) : days_per_month[month - 1];
}
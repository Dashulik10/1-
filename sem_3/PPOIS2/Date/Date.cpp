#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

//Date
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

string Date::getDayMonthYear() const
{
    return "Date: " + to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

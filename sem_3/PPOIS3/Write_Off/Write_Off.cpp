#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
#include "Write_Off.h"
using namespace std;

Write_off::Write_off() : date_of_writting_off(Date(1, 1, 2000)), reason_of_writting_off("No reason") {}
Write_off::Write_off(const Date& date, const string& reason)
{
    if (reason.empty())
    {
        throw invalid_argument("Reason for writing off cannot be empty.");
    }

    date_of_writting_off = date;
    reason_of_writting_off = reason;
}

string Write_off::getReasonOfWritingOff() const
{
    return reason_of_writting_off;
}
string Write_off::getDateOfWritingOff() const
{
    return date_of_writting_off.getDayMonthYear();
}

#ifndef WRITE_OFF_H 
#define WRITE_OFF_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
using namespace std;

class Write_off
{
private:
	Date date_of_writting_off;
	string reason_of_writting_off;
public:
	Write_off();
	Write_off(const Date& date, const string& reason);

	string getReasonOfWritingOff() const;
	string getDateOfWritingOff() const;
};

#endif

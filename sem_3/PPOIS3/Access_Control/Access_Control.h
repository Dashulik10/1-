#ifndef ACCESS_CONTROL_H 
#define ACCESS_CONTROL_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
#include "Emploee.h"
using namespace std;

class Access_Control
{
private:
	Date access_start_date;
	Date access_end_date;
public:
	Emploee empl;

	Access_Control();
	Access_Control(const Date& start_date, const Date& end_date, const Emploee& employee);
	Date getAccessStartDate() const;
	Date getAccessEndDate() const;

	bool checkAccessByDate(const Date& current_date) const;
	bool checkAccessByRating(double required_rating) const;
};

#endif
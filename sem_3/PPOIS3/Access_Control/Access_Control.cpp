#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
#include "Emploee.h"
#include "Access_Control.h"
using namespace std;

Access_Control::Access_Control()
    : access_start_date(Date(1, 1, 2000)), access_end_date(Date(1, 1, 2000)), empl(Emploee()) {}
Access_Control::Access_Control(const Date& start_date, const Date& end_date, const Emploee& employee)
    : access_start_date(start_date), access_end_date(end_date), empl(employee) {}

Date Access_Control::getAccessStartDate() const { return access_start_date; }
Date Access_Control::getAccessEndDate() const { return access_end_date; }
bool Access_Control::checkAccessByDate(const Date& current_date) const { return (current_date >= access_start_date && current_date <= access_end_date); }
bool Access_Control::checkAccessByRating(double required_rating) const { return empl.getRating() >= required_rating; }


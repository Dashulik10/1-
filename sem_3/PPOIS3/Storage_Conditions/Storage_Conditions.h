#ifndef STORAGE_CONDITIONS_H 
#define STORAGE_CONDITIONS_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Climate_Placement.h"
#include "Date.h"
using namespace std;

class Storage_Conditions
{
private:
	Date receipt_date;
	Date expiration_date;
	Climate_Placement type_climate;
public:
	Storage_Conditions();
	Storage_Conditions(Date receipt_date, Date expiration_date, Climate_Placement type_climate);

	Date getReceiptDate();
	Date getExpirationDate();
	Climate_Placement getTypeCLimate();

	bool isExpired(const Date& currentDate);
	Date daysBetwExp(const Date& currentDate) const;
};

#endif
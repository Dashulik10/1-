#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
#include "Climate_Placement.h"
#include "Storage_Conditions.h"
#include <regex>
using namespace std; 

Storage_Conditions::Storage_Conditions()
    : receipt_date(Date(1, 1, 2000)),
    expiration_date(Date(1, 1, 2001)),
    type_climate(Climate_Placement()) {}
Storage_Conditions::Storage_Conditions(Date receipt_date, Date expiration_date, Climate_Placement type_climate)
    : receipt_date(receipt_date), expiration_date(expiration_date), type_climate(type_climate)
{
    if (expiration_date.getYear() < receipt_date.getYear() ||
        (expiration_date.getYear() == receipt_date.getYear() && expiration_date.getMonth() < receipt_date.getMonth()) ||
        (expiration_date.getYear() == receipt_date.getYear() && expiration_date.getMonth() == receipt_date.getMonth() && expiration_date.getDay() < receipt_date.getDay()))
    {
        throw invalid_argument("Invalid expiration date: Expiration date must be after receipt date.");
    }
}

Date Storage_Conditions::getReceiptDate() { return receipt_date; }
Date Storage_Conditions::getExpirationDate() { return expiration_date; }
Climate_Placement Storage_Conditions::getTypeCLimate() { return type_climate; }
bool Storage_Conditions::isExpired(const Date& currentDate) { return (currentDate > expiration_date); }
Date Storage_Conditions::daysBetwExp(const Date& currentDate) const { return currentDate - expiration_date; }


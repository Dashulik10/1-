#ifndef PAYMENT_H
#define PAYMENT_H
#include <iostream>
#include <string>
#include <regex>
#include "Discount.h"
using namespace std;

class Payment 
{
public:

	double payment;
	string status_of_transfer;
	Discount discount_of_tour;

	Payment();
	Payment(double payment, string status_of_transfer, Discount discount_of_tour);

	double getDiscountedPrice() const;
	string getStatus() const;
};
#endif
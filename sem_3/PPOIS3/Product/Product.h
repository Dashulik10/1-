#ifndef PRODUCT_H 
#define PRODUCT_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Storage_Conditions.h"
using namespace std;

class Product
{
private:
	string name_of_product;
	string category;
	double rating_of_product;
public:

	Storage_Conditions conditions;

	Product();
	Product(const string&, const string&, double, const Storage_Conditions&);


	string getNameOfProduct() const;
	string getCategory() const;
	double getRatingOfProduct() const;
	bool isExpiringSoon(const Date&, int days_remaining = 7) const;

};

#endif


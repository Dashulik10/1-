#ifndef SUPPLIER_H 
#define SUPPLIER_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Person.h"
#include "Contact_Info.h"
using namespace std;

class Supplier : protected Person
{
private:
	string name_of_supplier;
	Contact_Info contInf_of_supplier;
	string category_of_goods;
	double rating_of_supplier;
public:
	Supplier();
	Supplier(const string& name, const Contact_Info& contact, const string& category, double rating);

	string getNameOfSupplier() const;
	ContactInfo getContactInfo() const;
	string getCategoryOfGoods() const;
	double getRatingOfSupplier() const;

	string SupplierRatingInfo() const;
};

#endif

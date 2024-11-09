#ifndef CUSTOMER_H 
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "ContactInfo.h"
#include "Product.h"
using namespace std;

class Customer
{
private:
	string customer;
	ContactInfo contInf_of_customer;
	vector <Product> list_of_required_goods;
public:
	Customer();
	Customer(const string& customer_name, const ContactInfo& contact, const vector<Product>& required_goods);

	void CustomerInfo() const;
};

#endif
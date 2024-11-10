#ifndef ORDER_H 
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
#include "Product.h"
#include "Supplier.h"
using namespace std;

class Order
{
private:
	string number_of_order;
	int days_for_delivery;
	Date date_of_creation_order;
	string status_of_order;
	vector <Product> product_for_order;
	Supplier supplier_of_order;
public:
	Order();
	Order(const string& order_number, int delivery_days, const Date& creation_date, const Supplier& supplier, const vector<Product>& products);

	bool isDeliveredOnTime(const Date& current_date) const;
	bool updateOrderStatus(const Date& current_date);
	string getStatusDescription() const;
	string getOrderInfo() const;
};

#endif

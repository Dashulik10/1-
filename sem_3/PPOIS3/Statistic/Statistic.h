#ifndef STATISTIC_H 
#define STATISTIC_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Product.h"
#include "Warehouse_Department.h"
using namespace std;

class Statistic
{
private:
	vector <Product> production;
	vector <Warehouse_Department> department;
public:

	Statistic();
	Statistic(const vector<Product>& prod, const vector<Warehouse_Department>& dep);

	string ProductInfo() const;
	string DepartmentInfo() const;
	string OccupancyInfo() const;
	int getProductionSize() const;
};

#endif

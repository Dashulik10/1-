#ifndef INVENTORY_H 
#define INVENTORY_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
#include "Statistic.h"
using namespace std;

class Inventory
{
private:
	Date date_of_inventory;
	int expected_number_of_goods;
	Statistic statistic_for_inventory;
public:
	Inventory();
	Inventory(const Date& date, int expected_goods, const Statistic& stat);

	string checkExpectedGoods() const;
	bool isInventoryRecent(const Date& current_date) const;
	string InventoryInfo(const Date& current_date) const;
};

#endif
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Date.h"
#include "Statistic.h"
#include "Inventory.h"
using namespace std;

Inventory::Inventory() : date_of_inventory(Date()), expected_number_of_goods(0), statistic_for_inventory(Statistic()) {}
Inventory::Inventory(const Date& date, int expected_goods, const Statistic& stat)
    : date_of_inventory(date), expected_number_of_goods(expected_goods), statistic_for_inventory(stat)
{
    if (expected_goods < 0)
        throw invalid_argument("Expected number of goods cannot be negative.");
}

string Inventory::checkExpectedGoods() const
{
    int actual_number_of_goods = statistic_for_inventory.getProductionSize();

    if (actual_number_of_goods == expected_number_of_goods)
    {
        return "The actual number of products matches the expected count.";
    }
    else
    {
        return "Mismatch in product count. Expected: " + to_string(expected_number_of_goods) +
            ", Actual: " + to_string(actual_number_of_goods);
    }
}
string Inventory::InventoryInfo(const Date& current_date) const
{
    string info = "Inventory " + date_of_inventory.getDayMonthYear() + "\n";
    info += "Expected Number of Goods: " + to_string(expected_number_of_goods) + "\n";
    info += "Actual Number of Goods: " + to_string(statistic_for_inventory.getProductionSize()) + "\n";
    return info;
}

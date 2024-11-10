#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "Storage_Conditions.h"
#include <regex>
using namespace std;

Product::Product() : name_of_product("Unknown"),
category("General"),
rating_of_product(0.0),
conditions(Storage_Conditions()) {}
Product::Product(const string& name_of_product, const string& category, double rating_of_product, const Storage_Conditions& conditions)
    : name_of_product(name_of_product),
    category(category),
    rating_of_product(rating_of_product),
    conditions(conditions)
{
    if (name_of_product.empty()) throw invalid_argument("Product name cannot be empty.");
    if (category.empty()) throw invalid_argument("Product category cannot be empty.");
    if (rating_of_product < 0.0 || rating_of_product > 10.0) throw invalid_argument("Product rating must be between 0 and 10.");
}

string Product::getNameOfProduct() const { return name_of_product; };
string Product::getCategory() const { return category; };
double Product::getRatingOfProduct() const { return rating_of_product; };
bool Product::isExpiringSoon(const Date& current_date, int days_remaining) const
{
    Date days_to_expiration = conditions.daysBetwExp(current_date);
    return days_to_expiration.getDay() <= days_remaining && days_to_expiration.getDay() >= 0;
}


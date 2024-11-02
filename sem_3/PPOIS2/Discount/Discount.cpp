#include <iostream>
#include <string>
#include <regex>
#include "Discount.h"
using namespace std;

// Discount
Discount::Discount() : persent(0) {}
Discount::Discount(int p)
    : persent(p) {}


int Discount::getDiscountPercent() const
{
    return persent;
}
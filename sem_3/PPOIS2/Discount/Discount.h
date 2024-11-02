#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Discount 
{
private:
	int persent;
public:
	Discount();
	Discount(int persent);

	int getDiscountPercent() const;
};
#endif
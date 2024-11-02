#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <string>
#include "ContactInfo.h"
using namespace std;

class Hotel 
{
private:
	string name_of_hotel;
	double payment;
	double rating_of_hotel;
public:

	Hotel();
	Hotel(string name_of_hotel, ContactInfo hotel_info, double payment, double rating_of_hotel);

	string getHotelInfo() const;

	double hotelPayment(int) const;
};
#endif
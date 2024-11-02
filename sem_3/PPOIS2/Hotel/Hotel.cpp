#include <iostream>
#include <string>
#include "Hotel.h"
using namespace std;

// Hotel
Hotel::Hotel() : name_of_hotel(""), payment(0.0), rating_of_hotel(0.0) {}
Hotel::Hotel(string name, ContactInfo info, double p, double rating)
    : name_of_hotel(name), payment(p), rating_of_hotel(rating) {}


double Hotel::hotelPayment(int nights_in_hotel) const
{
    return payment * nights_in_hotel;
}
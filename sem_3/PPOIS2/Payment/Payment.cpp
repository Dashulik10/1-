#include <iostream>
#include <string>
#include <regex>
#include "Payment.h"
using namespace std;

// Payment
Payment::Payment() : payment(0.0), status_of_transfer(""), discount_of_tour() {}
Payment::Payment(double p, string status, Discount ds)
    : payment(p), status_of_transfer(status), discount_of_tour(ds) {}

double Payment::getDiscountedPrice() const 
{
    return (payment - payment * discount_of_tour.getDiscountPercent() / 100.0);
}
string Payment::getStatus() const
{
    return status_of_transfer;
}
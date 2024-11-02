#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Tour.h"
#include "Payment.h"
#include "Comment.h"
#include "Country.h"
#include "Discount.h"
#include "Hotel.h"
#include "Excursion.h"
#include "Person.h"
#include "Emploee.h"

using namespace std;

class Reservation 
{
	public:
	string number_of_reservation;
	Payment payment_of_reservation;
	Comment comment_of_tour;
	vector<Tour> list_of_tour;
	string status_of_reservation;
	Reservation();
	Reservation(string number_of_reservation, string status_of_reservation, vector<Tour> list_of_tour, Payment payment_of_reservation, Comment comment_of_tour);

	string transcriptStatus() const;
	vector<string> listOfTours() const;
};
#endif
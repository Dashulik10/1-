#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Reservation.h"
#include "Date.h"
#include "Person.h"
#include "Country.h"
#include "Tour.h"
using namespace std;


class Client : public Person
{
public:
    string status_of_client;
	vector<Reservation> client_reservation;

	Client();
	Client(string name, string surname, string sex, Date birth_date, ContactInfo inf_person, string status_of_client, vector<Reservation> client_reservation);

	string setClientStatus();
	bool bookTour(const Reservation&);
};
#endif
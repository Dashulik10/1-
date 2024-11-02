#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Client.h"
#include "Country.h"
#include "Tour.h"
using namespace std;


// Client
Client::Client() : Person(), status_of_client(""), client_reservation() {}
Client::Client(string n, string s, string g, Date bd, ContactInfo info, string status, vector<Reservation> reservations)
    : Person(n, s, g, info), status_of_client(status), client_reservation(reservations) {}

string Client::setClientStatus()
{
    bool Confirmed = false;
    bool Canceled = false;

    for (const auto& reservation : client_reservation)
    {
        if (reservation.status_of_reservation == "CONF") Confirmed = true;
        else if (reservation.status_of_reservation == "CANC")Canceled = true;
    }

    if (Confirmed) return status_of_client = "Active";
    else return status_of_client = "Inactive";
}

bool Client::bookTour(const Reservation& new_reservation) {
    client_reservation.push_back(new_reservation);
    cout << "Successfully booked!" << endl;
    setClientStatus();
    return true;
}



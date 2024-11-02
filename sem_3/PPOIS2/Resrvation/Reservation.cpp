#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "Reservation.h"
#include "Country.h"
#include "Discount.h"
#include "Hotel.h"
#include "Excursion.h"
#include "Person.h"
#include "Emploee.h"
using namespace std;

// Reservation
Reservation::Reservation() : number_of_reservation(""), status_of_reservation(""), list_of_tour(), payment_of_reservation(), comment_of_tour() {}
Reservation::Reservation(string number, string status, vector<Tour> tours, Payment pay, Comment com)
    : number_of_reservation(number), status_of_reservation(status), list_of_tour(tours), payment_of_reservation(pay), comment_of_tour(com) {}


string Reservation::transcriptStatus() const
{
    if (status_of_reservation == "CONF") return "Confirmed";
    if (status_of_reservation == "CANC") return "Cancelled";
    return "Unknown status";
}

vector<string> Reservation::listOfTours() const
{
    vector<string> tourNames;
    for (const auto& tour : list_of_tour)
    {
        tourNames.push_back(tour.name_of_tour);
    }
    return tourNames;
}
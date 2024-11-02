#include <iostream>
#include <string>
#include <regex>
#include "Person.h"
#include "Emploee.h"
using namespace std;



// Emploee
Emploee::Emploee() : Person(), post(""), rating_of_emploee(0.0) {}
Emploee::Emploee(string n, string s, string g, ContactInfo info, string p, double rating)
    : Person(n, s, g, info), post(p), rating_of_emploee(rating) {}

string Emploee::getPostInfo()
{
    if (post == "Manager") return "Manager: Responsible for organizing tourist travel.";
    else if (post == "Guide") return "Guide: Responsible for stories, organizing tourist trips, finding interesting and safe routes along the route, resolving conflict or emergency situations.";
    else if (post == "Agent") return "Agent: Responsible for calculating the final cost of the trip, booking tickets, accommodation, visa processing.";
    else return post + ": General responsibilities.";
}

bool Emploee::checkingAccessToConfidentialDocs()
{
    if (post == "Manager" || post == "Agent") return true;
    else return false;
}

string Emploee::getCertificatePerformance()
{
    if (rating_of_emploee >= 8) return "Excellent performance!";
    else if (rating_of_emploee >= 5.0) return "Good performance, but there is room for improvement.";
    else return "Performance needs improvement.";
}
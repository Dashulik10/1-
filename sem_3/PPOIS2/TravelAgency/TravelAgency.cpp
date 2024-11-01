#include <iostream>
#include <string>
#include "TravelAgency.h"
using namespace std;


// TravelAgency
TravelAgency::TravelAgency() : name_of_travelAgency(""), web_site("") {}
TravelAgency::TravelAgency(string name, string site)
    : name_of_travelAgency(name), web_site(site) {}

bool TravelAgency::checkingExistanceSite()
{
    return (web_site.find("http://") == 0 || web_site.find("https://") == 0);
}
string TravelAgency::messageToClient(string message)
{
    string notification = "Dear client, " + message;
    return notification;
}

int TravelAgency::setNameOfTravelAgency(const string& name) { name_of_travelAgency = name; return 0; }
int TravelAgency::setWebSite(const string& site) { web_site = site; return 0; }
string TravelAgency::getNameOfTrAgencyAndWSite() const
{
    return "Travel Agency: " + name_of_travelAgency + ". Website: " + web_site + ". ";
}

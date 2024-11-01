#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <iostream>
#include <string>
using namespace std;

class TravelAgency
{
private:
	string name_of_travelAgency;
	string web_site;
public:
	TravelAgency();
	TravelAgency(string name_of_travelAgency, string wed_site);

	bool checkingExistanceSite();
	string messageToClient(string);

	int setNameOfTravelAgency(const string&);
	int setWebSite(const string&);
	string getNameOfTrAgencyAndWSite() const;
};
#endif

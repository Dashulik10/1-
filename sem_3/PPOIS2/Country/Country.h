#ifndef COUNTRY_H
#define COUNTRY_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map> 
#include <unordered_map>
using namespace std;

class Country 
{
private:
	string name_of_country;
	string kod_of_country;
public:
	Country();
	Country(string name_of_country, string kod_of_country);

	string getNameOfCountry() const;
	int setNameOfCountry(const string&);
	int setKodOfCountry(const string&);

	vector<string> getOficialListOfLanguages();
	string getNameOfContenentByKod();
};
#endif
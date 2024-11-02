#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <unordered_map>
#include "Country.h"
using namespace std;

// Country
Country::Country() : name_of_country(""), kod_of_country("") {}
Country::Country(string name, string kod) : name_of_country(name), kod_of_country(kod) {}


vector<string> Country::getOficialListOfLanguages()
{
    unordered_map<string, vector<string>> country_languages =
    {
        {"USA", {"English"}},
        {"France", {"French"}},
        {"Germany", {"German"}},
        {"Japan", {"Japanese"}},
        {"India", {"Hindi", "English"}}
    };
    if (country_languages.find(name_of_country) != country_languages.end()) return country_languages[name_of_country];
    else return { "Unknown" };
}

string Country::getNameOfContenentByKod()
{
    unordered_map<string, string> country_continents =
    {
        {"USA", "North America"},
        {"FR", "Europe"},
        {"DE", "Europe"},
        {"JP", "Asia"},
        {"IN", "Asia"},
        {"BR", "South America"},
        {"ZA", "Africa"}
    };
    if (country_continents.find(kod_of_country) != country_continents.end()) return country_continents[kod_of_country];
    else return "Unknown";
}

string Country::getNameOfCountry() const
{
    return "Name of country: " + name_of_country + ". Kod of country: " + kod_of_country + ". ";
}
int Country::setNameOfCountry(const string& name)
{
    name_of_country = name;
    return 0;
}
int Country::setKodOfCountry(const string& kod)
{
    kod_of_country = kod;
    return 0;
}
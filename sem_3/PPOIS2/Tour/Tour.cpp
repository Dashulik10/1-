#include <iostream>
#include <string>
#include <vector>
#include <map> 
#include <unordered_map>
#include "Tour.h"
using namespace std;

// Tour
Tour::Tour() : name_of_tour(""), country_of_tour(), excursions_of_tour(), hotel_of_tour(), discount_of_tour() {}
Tour::Tour(string name, Country country, vector<Excursion> excursions, Hotel hotel, Discount discount)
    : name_of_tour(name), country_of_tour(country), excursions_of_tour(excursions),
    hotel_of_tour(hotel), discount_of_tour(discount) {}


vector<string> Tour::excursionList() const 
{
    vector<string> excursion_names;
    for (const auto& excursion : excursions_of_tour) 
    {
        excursion_names.push_back(excursion.getNameOfExcursion());
    }
    return excursion_names;
}

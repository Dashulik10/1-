#ifndef TOUR_H
#define TOUR_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map> 
#include <unordered_map>
#include "Country.h"
#include "Hotel.h"
#include "Discount.h"
#include "Excursion.h"
using namespace std;

class Tour 
{
private:
	Country country_of_tour;
	Hotel hotel_of_tour;
	Discount discount_of_tour;
public:
	string name_of_tour;
	vector<Excursion> excursions_of_tour;

	Tour();
	Tour(string name_of_tour, Country country_of_tour, vector<Excursion> excursions_of_tour, Hotel hotel_of_tour, Discount discount_of_tour);

	
	vector<string> excursionList() const;
};
#endif
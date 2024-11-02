#ifndef EXCURSION_H
#define EXCURSION_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Guide.h"

using namespace std;


class Excursion 
{
public:
	string name_of_excursion;
	string short_description;
	Guide guide_of_exursion;

	Excursion();
	Excursion(string name_of_excursion, string short_description, Guide guide_of_exursion);

	string getNameOfExcursion() const;
};
#endif
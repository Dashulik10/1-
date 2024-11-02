#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include "Excursion.h"
using namespace std;

// Excursion
Excursion::Excursion() : name_of_excursion(""), short_description(""), guide_of_exursion() {}
Excursion::Excursion(string name, string desc, Guide guide)
    : name_of_excursion(name), short_description(desc), guide_of_exursion(guide) {}


string Excursion::getNameOfExcursion() const
{
    return name_of_excursion;
}
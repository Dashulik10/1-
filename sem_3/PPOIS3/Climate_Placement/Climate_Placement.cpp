#include <iostream>
#include <string>
#include <vector>
#include "Climate_Placement.h"
#include <regex>
using namespace std;

Climate_Placement::Climate_Placement() : name_of_placement("Unknown"), temperature(0.0), present_of_humidity(0) {}
Climate_Placement::Climate_Placement(string name_of_placement, double temperature, int present_of_humidity)
{
    if (name_of_placement.empty()) throw invalid_argument("Invalid placement name: Name cannot be empty.");
    this->temperature = temperature;
    if (present_of_humidity < 0 || present_of_humidity > 100)
    {
        throw invalid_argument("Invalid humidity: Must be between 0 and 100.");
    }
    this->name_of_placement = name_of_placement;
    this->present_of_humidity = present_of_humidity;
}

string Climate_Placement::getNameOfPlacement() { return name_of_placement; };
double Climate_Placement::getTemperature() { return temperature; };
int Climate_Placement::getPresentOfHumidity() { return present_of_humidity; };

string Climate_Placement::getStorageType() const
{
    if (temperature < 0) return "Freezer";
    else if (temperature >= 0 && temperature <= 10) return "Refrigerator";
    else if (temperature > 10 && temperature <= 25)
    {
        if (present_of_humidity < 50) return "Dry Storage";
        else return "Normal Storage";
    }
    else return "Warm Storage";
}
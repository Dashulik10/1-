#ifndef CLIMATE_PLACEMENT_H
#define CLIMATE_PLACEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class Climate_Placement
{
private:
	string name_of_placement;
	double temperature;
	int present_of_humidity;
public:

	Climate_Placement();
	Climate_Placement(string name_of_placement, double temperature, int present_of_humidity);

	string getNameOfPlacement();
	double getTemperature();
	int getPresentOfHumidity();

	string getStorageType() const;
};

#endif
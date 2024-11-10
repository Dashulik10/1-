#ifndef WAREHOUSE_DEPARTMENT_H 
#define WAREHOUSE_DEPARTMENT_H 

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Climate_Placement.h"
using namespace std;

class Warehouse_Department
{
private:
	string name_of_department;
	int number_of_available_places;
	int number_of_notavailable_places;
public:

	Climate_Placement type_of_placement;

	Warehouse_Department();
	Warehouse_Department(string&, int&, int&, Climate_Placement&);

	string getNameOfDepartment() const;
	int getNumberOfAvailablePlaces() const;
	int getNumberOfNotavailablePlaces() const;
	string getPlacementTypeName() const;
	void printDepartmentOccupancyInfo() const;
};

#endif
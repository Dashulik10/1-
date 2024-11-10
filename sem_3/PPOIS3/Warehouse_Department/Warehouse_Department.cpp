#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Climate_Placement.h"
#include "Warehouse_Department.h"
using namespace std;

Warehouse_Department::Warehouse_Department()
    : name_of_department("Default Name"), number_of_available_places(0), number_of_notavailable_places(0), type_of_placement(Climate_Placement()) {}
Warehouse_Department::Warehouse_Department(string& name, int& available, int& not_available, Climate_Placement& climat)
    : type_of_placement(climat)
{
    if (name.empty()) throw invalid_argument("Department name cannot be empty.");
    if (available < 0) throw invalid_argument("Number of available places cannot be negative.");
    if (not_available < 0) throw invalid_argument("Number of not available places cannot be negative.");

    name_of_department = name;
    number_of_available_places = available;
    number_of_notavailable_places = not_available;
}

string Warehouse_Department::getNameOfDepartment() const { return name_of_department; }
int Warehouse_Department::getNumberOfAvailablePlaces() const { return number_of_available_places; }
int Warehouse_Department::getNumberOfNotavailablePlaces() const { return number_of_notavailable_places; }
string Warehouse_Department::getPlacementTypeName() const
{
    return type_of_placement.getStorageType();
}
void Warehouse_Department::printDepartmentOccupancyInfo() const
{
    cout << "Department: " << name_of_department << endl;
    cout << "Available places: " << number_of_available_places << endl;
    cout << "Occupied places: " << number_of_notavailable_places << endl;
    int total_places = number_of_available_places + number_of_notavailable_places;
    double occupancy_rate = (static_cast<double>(number_of_notavailable_places) / total_places) * 100;
    cout << "Occupancy rate: " << occupancy_rate << "%" << endl;
}
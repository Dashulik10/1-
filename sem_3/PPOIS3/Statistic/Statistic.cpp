#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Product.h"
#include "Warehouse_Department.h"
#include "Statistic.h"
using namespace std;

Statistic::Statistic() : production(), department() {}
Statistic::Statistic(const vector<Product>& prod, const vector<Warehouse_Department>& dep)
    : production(prod), department(dep) {
    if (production.empty()) throw invalid_argument("Production vector cannot be empty.");
    if (department.empty()) throw invalid_argument("Department vector cannot be empty.");
}

string Statistic::ProductInfo() const
{
    string result;
    if (production.empty())
    {
        result = "No products in storage.\n";
    }
    else
    {
        result = "Products in storage:\n";
        for (const auto& product : production)
        {
            result += "- Product Name: " + product.getNameOfProduct() + ", ";
            result += "Category: " + product.getCategory() + ", ";
            result += "Rating: " + to_string(product.getRatingOfProduct()) + "\n";
        }
    }
    return result;
}
string Statistic::DepartmentInfo() const
{
    string result;
    if (department.empty())
    {
        result = "No departments in warehouse.\n";
    }
    else
    {
        result = "Warehouse Departments:\n";
        for (const auto& dept : department)
        {
            result += "- Department Name: " + dept.getNameOfDepartment() + ", ";
            result += "Placement Type: " + dept.getPlacementTypeName() + "\n";
        }
    }
    return result;
}
string Statistic::OccupancyInfo() const
{
    string result;
    if (department.empty())
    {
        result = "No departments to show occupancy information.\n";
    }
    else
    {
        result = "Warehouse Department Occupancy:\n";
        for (const auto& dept : department)
        {
            result += "- " + dept.getNameOfDepartment() + ":\n";
            result += "  Available places: " + to_string(dept.getNumberOfAvailablePlaces()) + "\n";
            result += "  Occupied places: " + to_string(dept.getNumberOfNotavailablePlaces()) + "\n";

            int total_places = dept.getNumberOfAvailablePlaces() + dept.getNumberOfNotavailablePlaces();
            double occupancy_rate = total_places > 0
                ? (static_cast<double>(dept.getNumberOfNotavailablePlaces()) / total_places) * 100
                : 0;

            result += "  Occupancy rate: " + to_string(occupancy_rate) + "%\n";
        }
    }
    return result;
}
int Statistic::getProductionSize() const
{
    return production.size();
}

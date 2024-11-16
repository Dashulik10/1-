#include <iostream>
#include <string>
#include <vector>
#include "Supplier.h"
#include "Person.h"
#include "Contact_Info.h"
#include <regex>
using namespace std;

Supplier::Supplier() : name_of_supplier("Unknown"), contInf_of_supplier(Contact_Info()), category_of_goods("General"), rating_of_supplier(0.0) {}
Supplier::Supplier(const string& name, const Contact_Info& contact, const string& category, double rating)
    : name_of_supplier(name), contInf_of_supplier(contact), category_of_goods(category), rating_of_supplier(rating)
{
    if (name.empty())
    {
        throw invalid_argument("Supplier name cannot be empty.");
    }
    if (category.empty())
    {
        throw invalid_argument("Category of goods cannot be empty.");
    }
    if (rating < 0.0 || rating > 10.0)
    {
        throw invalid_argument("Supplier rating must be between 0 and 10.");
    }
}

string Supplier::SupplierRatingInfo() const
{
    if (rating_of_supplier >= 8.0)
    {
        return "Excellent supplier with high reliability!";
    }
    else if (rating_of_supplier >= 5.0)
    {
        return "Good supplier, but there may be occasional issues.";
    }
    else
    {
        return "Supplier needs improvement in reliability and quality.";
    }
}
string Supplier::getNameOfSupplier() const { return name_of_supplier; }
Contact_Info Supplier::getContactInfo() const { return contInf_of_supplier; }
string Supplier::getCategoryOfGoods() const { return category_of_goods; }
double Supplier::getRatingOfSupplier() const { return rating_of_supplier; }



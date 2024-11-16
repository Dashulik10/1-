#include <iostream>
#include <string>
#include <vector>
#include "Emploee.h"
#include <regex>
using namespace std;

Emploee::Emploee() : Person(), post(""), rating_of_emploee(0.0) {}
Emploee::Emploee(string n, string s, string g, Contact_Info info, string p, double rating)
    : Person(n, s, g, info), post(p), rating_of_emploee(rating) {}

string Emploee::getPostInfo()
{
    if (post == "Storekeeper") return "Main responsibilities: receiving, placing and issuing goods; maintaining records in the warehouse; checking the quantity and quality of products.";
    else if (post == "Warehouse Operations Manager") return "Main responsibilities: coordination of warehouse operations, distribution of tasks between employees, control over order fulfillment.";
    else if (post == "Receiving and shipping specialist (receiver)") return "Main responsibilities: monitoring the process of acceptance and shipment of goods, preparation of accompanying documents.";
    else return "General responsibilities: " + post;
}
bool Emploee::checkingAccessToConfidentialDocs()
{
    if (post == "Warehouse Operations Manager" || post == "Receiving and shipping specialist (receiver)") return true;
    else return false;
}
string Emploee::getCertificatePerformance()
{
    if (rating_of_emploee >= 8) return "Excellent performance!";
    else if (rating_of_emploee >= 5.0) return "Good performance, but there is room for improvement.";
    else return "Performance needs improvement.";
}
string Emploee::getPost() const { return post; }
double Emploee::getRating() const { return rating_of_emploee; }


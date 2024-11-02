#include <iostream>
#include <string>
#include <regex> 
#include "Person.h"
#include "ContactInfo.h"
using namespace std;

// Person
Person::Person() : name(""), surname(""), sex(""), inf_person() {}
Person::Person(string n, string s, string g, ContactInfo info)
    : name(n), surname(s), sex(g), inf_person(info) {}

string Person::getClientGender()
{
    if (sex == "male") return "Mr.";
    else if (sex == "female") return "Ms.";
    else return "Mx.";
}

bool Person::CorrectnessContactInf()
{
    if (inf_person.isContactInfCompl()) return true;
    else return false;
}

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Person.h"
#include "Guide.h"
#include "Emploee.h"
using namespace std;

// Guide
Guide::Guide() : Emploee(), list_of_lan() {}
Guide::Guide(string n, string s, string g, ContactInfo info, string p, double rating, vector<string> lan)
    : Emploee(n, s, g, info, p, rating), list_of_lan(lan) {}

bool Guide::addNewLanguage(const string& new_language)
{
    for (const string& lang : list_of_lan) if (lang == new_language) return false;
    list_of_lan.push_back(new_language);
    return true;
}

string Guide::getListOfLanguages() const
{
    string languages = "Languages known: ";
    for (const string& lang : list_of_lan) languages += lang + ", ";
    if (!list_of_lan.empty()) languages = languages.substr(0, languages.size() - 2);
    return languages;
}
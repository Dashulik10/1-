#ifndef GUIDE_H
#define GUIDE_H
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Emploee.h"
using namespace std;

class Guide : public Emploee
{
private:
	vector<string> list_of_lan;
public:
	Guide();
	Guide(string name, string surname, string sex, ContactInfo inf_person, string post, double rating_of_emploee, vector<string> list_of_lan);


	bool addNewLanguage(const string&);
	string getListOfLanguages() const;
};
#endif
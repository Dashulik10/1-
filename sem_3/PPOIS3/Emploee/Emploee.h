#ifndef EMPLOEE_H
#define EMPLOEE_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Person.h"
#include "Contact_Info.h"
using namespace std;

class Emploee : protected Person
{
private:
	string post;
	double rating_of_emploee;
public:
	Emploee();
	Emploee(string name, string surname, string sex, Contact_Info inf_person, string post, double rating_of_emploee);

	string getPostInfo();
	bool checkingAccessToConfidentialDocs();
	string getCertificatePerformance();
	string getPost() const;
	double getRating() const;

};

#endif

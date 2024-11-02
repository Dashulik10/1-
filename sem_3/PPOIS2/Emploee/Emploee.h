#ifndef EMPLOEE_H
#define EMPLOEE_H
#include <iostream>
#include <string>
#include <regex>
#include "ContactInfo.h"
#include "Person.h"
using namespace std;

class Emploee : protected Person 
{
public:
	string post;
	double rating_of_emploee;

	Emploee();
	Emploee(string name, string surname, string sex, ContactInfo inf_person, string post, double rating_of_emploee);

	string getPostInfo();
	bool checkingAccessToConfidentialDocs();
	string getCertificatePerformance();
};
#endif
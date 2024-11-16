#ifndef PERSON_H 
#define PERSON_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "Contact_Info.h"
using namespace std;

class Person
{
protected:
	string name;
	string surname;
	string sex;
	ContactInfo inf_person;
public:
	Person();
	Person(string name, string surname, string sex, ContactInfo inf_person);

	string getClientGender();
	bool CorrectnessContactInf();
};

#endif 

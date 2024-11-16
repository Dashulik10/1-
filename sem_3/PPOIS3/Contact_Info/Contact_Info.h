#ifndef CONTACT_INFO_H 
#define CONTACT_INFO_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class Contact_Info
{
private:
	string telephone_number;
	string email;
public:

	Contact_Info();
	Contact_Info(string telephone_number, string email);

	bool phoneInputCheck();
	bool emailInputCheck();
	bool isContactInfCompl();

	string getTelephoneNumber() const;
	string getEmail() const;

	int setTelephoneNumber(const string&);
	int setEmail(const string&);
};

#endif

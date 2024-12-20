#ifndef CONTACTINFO_H
#define CONTACTINFO_H
#include <iostream>
#include <string>
#include <regex>
using namespace std;

class ContactInfo
{
private:
	string telephone_number;
	string email;
public:


	ContactInfo();
	ContactInfo(string telephone_number, string email);

	bool phoneInputCheck();
	bool emailInputCheck();
	bool isContactInfCompl();

	string getTelephoneNumber() const;
	string getEmail() const;

	int setTelephoneNumber(const string&);
	int setEmail(const string&);
};
#endif
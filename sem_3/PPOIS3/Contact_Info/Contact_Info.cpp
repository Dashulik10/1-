
#include <iostream>
#include <string>
#include <vector>
#include "Contact_Info.h"
#include <regex>
using namespace std;

Contact_Info::Contact_Info() : telephone_number(""), email("") {}
Contact_Info::Contact_Info(string tel, string em)
    : telephone_number(tel), email(em) {}

bool Contact_Info::emailInputCheck()
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
bool Contact_Info::phoneInputCheck() { return (telephone_number[0] == '+' && telephone_number.length() <= 13); }
bool Contact_Info::isContactInfCompl() { return (!telephone_number.empty() && !email.empty()); }
string Contact_Info::getTelephoneNumber() const { return telephone_number; }
string Contact_Info::getEmail() const { return email; }
int Contact_Info::setTelephoneNumber(const string& tel) { telephone_number = tel; return 0; }
int Contact_Info::setEmail(const string& em) { email = em; return 0; }

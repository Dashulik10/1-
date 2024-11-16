
#include <iostream>
#include <string>
#include <vector>
#include "Contact_Info.h"
#include <regex>
using namespace std;

ContactInfo::ContactInfo() : telephone_number(""), email("") {}
ContactInfo::ContactInfo(string tel, string em)
    : telephone_number(tel), email(em) {}

bool ContactInfo::emailInputCheck()
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
bool ContactInfo::phoneInputCheck() { return (telephone_number[0] == '+' && telephone_number.length() <= 13); }
bool ContactInfo::isContactInfCompl() { return (!telephone_number.empty() && !email.empty()); }
string ContactInfo::getTelephoneNumber() const { return telephone_number; }
string ContactInfo::getEmail() const { return email; }
int ContactInfo::setTelephoneNumber(const string& tel) { telephone_number = tel; return 0; }
int ContactInfo::setEmail(const string& em) { email = em; return 0; }

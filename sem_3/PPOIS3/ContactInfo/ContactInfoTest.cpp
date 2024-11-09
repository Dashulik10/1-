#include <gtest/gtest.h>
#include "ContactInfo.h"

TEST(ContactInfoTest, DefaultConstructor) 
{
    ContactInfo contact;
    EXPECT_EQ(contact.getTelephoneNumber(), "");
    EXPECT_EQ(contact.getEmail(), "");
}
TEST(ContactInfoTest, Constructor)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    EXPECT_EQ(contact.getTelephoneNumber(), "+1234567890123");
    EXPECT_EQ(contact.getEmail(), "test@example.com");
}


TEST(ContactInfoTest, PhoneInputCheck) 
{
    ContactInfo contact("+123459", "test@example.com");
    EXPECT_TRUE(contact.phoneInputCheck());
}
TEST(ContactInfoTest, PhoneInputCheckInvalid) 
{
    ContactInfo contact("+1234567890124345493", "test@example.com");
    EXPECT_FALSE(contact.phoneInputCheck());

    ContactInfo contact2("+123455069890589389", "test@example.com");
    EXPECT_FALSE(contact2.phoneInputCheck());
}

TEST(ContactInfoTest, EmailInputCheck) 
{
    ContactInfo contact("+1234567890123", "valid_email@example.com");
    EXPECT_TRUE(contact.emailInputCheck());

    ContactInfo contact2("+1234567890123", "name.lastname@example.co.uk");
    EXPECT_TRUE(contact2.emailInputCheck());
}
TEST(ContactInfoTest, EmailInputCheckInvalid)
{
    ContactInfo contact("+1234567890123", "invalid_email@.com");
    EXPECT_FALSE(contact.emailInputCheck());

    ContactInfo contact2("+1234567890123", "invalid_email.com"); 
    EXPECT_FALSE(contact2.emailInputCheck());

    ContactInfo contact3("+1234567890123", "invalid@domain");
    EXPECT_FALSE(contact3.emailInputCheck());
}

TEST(ContactInfoTest, IsContactInfoComplete)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    EXPECT_TRUE(contact.isContactInfCompl());

    ContactInfo contact2("+1234567890123", "");
    EXPECT_FALSE(contact2.isContactInfCompl());

    ContactInfo contact3("", "test@example.com"); 
    EXPECT_FALSE(contact3.isContactInfCompl());
}

TEST(ContactInfoTest, GetTelephoneNumber) 
{
    ContactInfo contact("+1234567890123", "test@example.com");
    EXPECT_EQ(contact.getTelephoneNumber(), "+1234567890123");
}
TEST(ContactInfoTest, GetEmail)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    EXPECT_EQ(contact.getEmail(), "test@example.com");
}
TEST(ContactInfoTest, SetTelephoneNumber)
{
    ContactInfo contact;
    contact.setTelephoneNumber("+1234567890123");
    EXPECT_EQ(contact.getTelephoneNumber(), "+1234567890123");
}
TEST(ContactInfoTest, SetEmail)
{
    ContactInfo contact;
    contact.setEmail("test@example.com");
    EXPECT_EQ(contact.getEmail(), "test@example.com");
}


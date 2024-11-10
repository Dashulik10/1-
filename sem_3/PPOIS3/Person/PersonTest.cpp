#include <gtest/gtest.h>
#include "Person.h"
#include "ContactInfo.h"

TEST(PersonTest, DefaultConstructor) 
{
    Person person;
    EXPECT_EQ(person.getClientGender(), "Mx.");
    EXPECT_FALSE(person.CorrectnessContactInf());
}
TEST(PersonTest, Constructor)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_EQ(person.getClientGender(), "Mr.");
    EXPECT_TRUE(person.CorrectnessContactInf());
}
TEST(PersonTest, ConstructorFemale)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Person person("Jane", "Doe", "female", contact);
    EXPECT_EQ(person.getClientGender(), "Ms.");
    EXPECT_TRUE(person.CorrectnessContactInf());
}
TEST(PersonTest, ConstructorGenderNeutral)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Person person("Alex", "Smith", "non-binary", contact);
    EXPECT_EQ(person.getClientGender(), "Mx.");
    EXPECT_TRUE(person.CorrectnessContactInf());
}


TEST(PersonTest, GetClientGenderMale) 
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_EQ(person.getClientGender(), "Mr.");
}
TEST(PersonTest, GetClientGenderFemale) 
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Person person("Jane", "Doe", "female", contact);
    EXPECT_EQ(person.getClientGender(), "Ms.");
}
TEST(PersonTest, GetClientGenderUnknown)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Person person("Taylor", "Doe", "unknown", contact);
    EXPECT_EQ(person.getClientGender(), "Mx.");
}


TEST(PersonTest, CorrectnessContactInfComplete)
{
    ContactInfo contact("+1234567890123", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_TRUE(person.CorrectnessContactInf());
}
TEST(PersonTest, CorrectnessContactInfIncompleteEmail)
{
    ContactInfo contact("+1234567890123", "");
    Person person("John", "Doe", "male", contact);
    EXPECT_FALSE(person.CorrectnessContactInf());
}
TEST(PersonTest, CorrectnessContactInfIncompletePhone) 
{
    ContactInfo contact("", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_FALSE(person.CorrectnessContactInf());
}
TEST(PersonTest, CorrectnessContactInfEmpty) 
{
    ContactInfo contact;
    Person person("John", "Doe", "male", contact);
    EXPECT_FALSE(person.CorrectnessContactInf());
}

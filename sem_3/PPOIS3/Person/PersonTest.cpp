#include <gtest/gtest.h>
#include "Person.h"
#include "Contact_Info.h"

TEST(PersonTest, DefaultConstructor) 
{
    Person person;
    EXPECT_EQ(person.getClientGender(), "Mx.");
    EXPECT_FALSE(person.CorrectnessContactInf());
}
TEST(PersonTest, Constructor)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_EQ(person.getClientGender(), "Mr.");
    EXPECT_TRUE(person.CorrectnessContactInf());
}
TEST(PersonTest, ConstructorFemale)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Person person("Jane", "Doe", "female", contact);
    EXPECT_EQ(person.getClientGender(), "Ms.");
    EXPECT_TRUE(person.CorrectnessContactInf());
}
TEST(PersonTest, ConstructorGenderNeutral)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Person person("Alex", "Smith", "non-binary", contact);
    EXPECT_EQ(person.getClientGender(), "Mx.");
    EXPECT_TRUE(person.CorrectnessContactInf());
}


TEST(PersonTest, GetClientGenderMale) 
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_EQ(person.getClientGender(), "Mr.");
}
TEST(PersonTest, GetClientGenderFemale) 
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Person person("Jane", "Doe", "female", contact);
    EXPECT_EQ(person.getClientGender(), "Ms.");
}
TEST(PersonTest, GetClientGenderUnknown)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Person person("Taylor", "Doe", "unknown", contact);
    EXPECT_EQ(person.getClientGender(), "Mx.");
}


TEST(PersonTest, CorrectnessContactInfComplete)
{
    Contact_Info contact("+1234567890123", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_TRUE(person.CorrectnessContactInf());
}
TEST(PersonTest, CorrectnessContactInfIncompleteEmail)
{
    Contact_Info contact("+1234567890123", "");
    Person person("John", "Doe", "male", contact);
    EXPECT_FALSE(person.CorrectnessContactInf());
}
TEST(PersonTest, CorrectnessContactInfIncompletePhone) 
{
    Contact_Info contact("", "test@example.com");
    Person person("John", "Doe", "male", contact);
    EXPECT_FALSE(person.CorrectnessContactInf());
}
TEST(PersonTest, CorrectnessContactInfEmpty) 
{
    Contact_Info contact;
    Person person("John", "Doe", "male", contact);
    EXPECT_FALSE(person.CorrectnessContactInf());
}

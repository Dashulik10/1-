#include <gtest/gtest.h>
#include "Access_Control.h"
#include "Date.h"
#include "Emploee.h"


TEST(AccessControlTest, DefaultConstructor)
{
    Access_Control accessControl;

    Date defaultStartDate(1, 1, 2000);
    Date defaultEndDate(1, 1, 2000);

    EXPECT_EQ(accessControl.getAccessStartDate(), defaultStartDate);
    EXPECT_EQ(accessControl.getAccessEndDate(), defaultEndDate);
    EXPECT_DOUBLE_EQ(accessControl.empl.getRating(), 0.0);  
}


TEST(AccessControlTest, ParameterizedConstructor)
{
    Date startDate(10, 5, 2023);
    Date endDate(10, 5, 2024);
    Emploee employee("John", "Doe", "male", ContactInfo("+1234567890123", "johndoe@test.com"), "Manager", 8.5);

    Access_Control accessControl(startDate, endDate, employee);

    EXPECT_EQ(accessControl.getAccessStartDate(), startDate);
    EXPECT_EQ(accessControl.getAccessEndDate(), endDate);
    EXPECT_EQ(accessControl.empl.getPost(), "Manager");
    EXPECT_DOUBLE_EQ(accessControl.empl.getRating(), 8.5);
}


TEST(AccessControlTest, CheckAccessByDate)
{
    Date startDate(1, 1, 2023);
    Date endDate(31, 12, 2023);
    Emploee employee("Alice", "Smith", "female", ContactInfo("+9876543210987", "alice@test.com"), "Engineer", 7.5);

    Access_Control accessControl(startDate, endDate, employee);

    Date testDateWithin(15, 6, 2023);
    Date testDateBefore(31, 12, 2022);
    Date testDateAfter(1, 1, 2024);

    EXPECT_TRUE(accessControl.checkAccessByDate(testDateWithin));
    EXPECT_FALSE(accessControl.checkAccessByDate(testDateBefore));
    EXPECT_FALSE(accessControl.checkAccessByDate(testDateAfter));
}


TEST(AccessControlTest, CheckAccessByRating) 
{
    Date startDate(1, 1, 2023);
    Date endDate(31, 12, 2023);
    Emploee employee("Bob", "Williams", "male", ContactInfo("+1122334455667", "bob@test.com"), "Technician", 6.0);

    Access_Control accessControl(startDate, endDate, employee);

    EXPECT_TRUE(accessControl.checkAccessByRating(5.5));
    EXPECT_TRUE(accessControl.checkAccessByRating(6.0));
    EXPECT_FALSE(accessControl.checkAccessByRating(7.0));
}


TEST(AccessControlTest, AccessOnBoundaryDates)
{
    Date startDate(15, 3, 2023);
    Date endDate(15, 3, 2023); 
    Emploee employee("Cathy", "Brown", "female", ContactInfo("+5556667778889", "cathy@test.com"), "Supervisor", 7.2);

    Access_Control accessControl(startDate, endDate, employee);

    EXPECT_TRUE(accessControl.checkAccessByDate(startDate)); 
    EXPECT_TRUE(accessControl.checkAccessByDate(endDate));  

    Date testDateBefore(14, 3, 2023);
    Date testDateAfter(16, 3, 2023);

    EXPECT_FALSE(accessControl.checkAccessByDate(testDateBefore));
    EXPECT_FALSE(accessControl.checkAccessByDate(testDateAfter));
}

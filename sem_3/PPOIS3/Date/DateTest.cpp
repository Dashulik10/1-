#include <gtest/gtest.h>
#include "Date.h"

TEST(DateTest, Constructor) 
{
    Date date(15, 5, 2023);
    EXPECT_EQ(date.getDay(), 15);
    EXPECT_EQ(date.getMonth(), 5);
    EXPECT_EQ(date.getYear(), 2023);
}
TEST(DateTest, ConstructorInvalid)
{
    EXPECT_THROW(Date(32, 1, 2023), std::invalid_argument);
    EXPECT_THROW(Date(29, 2, 2021), std::invalid_argument); 
    EXPECT_THROW(Date(0, 5, 2023), std::invalid_argument); 
    EXPECT_THROW(Date(15, 13, 2023), std::invalid_argument); 
    EXPECT_THROW(Date(15, 0, 2023), std::invalid_argument); 
}
TEST(DateTest, DefaultConstructor)
{
    Date date;
    EXPECT_EQ(date.getDay(), 1);
    EXPECT_EQ(date.getMonth(), 1);
    EXPECT_EQ(date.getYear(), 2000);
}



TEST(DateTest, Equality) 
{
    Date date1(15, 5, 2023);
    Date date2(15, 5, 2023);
    Date date3(16, 5, 2023);
    EXPECT_TRUE(date1 == date2);
    EXPECT_FALSE(date1 == date3);
}
TEST(DateTest, Inequality) 
{
    Date date1(15, 5, 2023);
    Date date2(16, 5, 2023);
    EXPECT_TRUE(date1 != date2);
}

TEST(DateTest, GreaterThan) 
{
    Date date1(15, 5, 2023);
    Date date2(14, 5, 2023);
    EXPECT_TRUE(date1 > date2);
}
TEST(DateTest, LessThan) 
{
    Date date1(15, 5, 2023);
    Date date2(16, 5, 2023);
    EXPECT_TRUE(date1 < date2);
}
TEST(DateTest, GreaterThanOrEqua)
{
    Date date1(15, 5, 2023);
    Date date2(15, 5, 2023);
    Date date3(14, 5, 2023);
    EXPECT_TRUE(date1 >= date2);
    EXPECT_TRUE(date1 >= date3);
}
TEST(DateTest, LessThanOrEqual)
{
    Date date1(15, 5, 2023);
    Date date2(15, 5, 2023);
    Date date3(16, 5, 2023);
    EXPECT_TRUE(date1 <= date2);
    EXPECT_TRUE(date1 <= date3);
}



TEST(DateTest, Addition) 
{
    Date date(28, 2, 2020);
    Date result = date + 1;
    EXPECT_EQ(result.getDay(), 29);
    EXPECT_EQ(result.getMonth(), 2);
    EXPECT_EQ(result.getYear(), 2020);

    Date result2 = date + 2; 
    EXPECT_EQ(result2.getDay(), 1);
    EXPECT_EQ(result2.getMonth(), 3);
    EXPECT_EQ(result2.getYear(), 2020);
}

TEST(DateTest, IsLeapYear) 
{
    EXPECT_TRUE(Date::isLeapYear(2020)); 
    EXPECT_FALSE(Date::isLeapYear(2021)); 
    EXPECT_TRUE(Date::isLeapYear(2000)); 
    EXPECT_FALSE(Date::isLeapYear(1900)); 
}

TEST(DateTest, DaysInMonth)
{
    EXPECT_EQ(Date::daysInMonth(2, 2020), 29); 
    EXPECT_EQ(Date::daysInMonth(2, 2021), 28); 
    EXPECT_EQ(Date::daysInMonth(1, 2023), 31); 
    EXPECT_EQ(Date::daysInMonth(4, 2023), 30); 
    EXPECT_THROW(Date::daysInMonth(13, 2023), std::invalid_argument);
}


TEST(DateTest, Assignment)
{
    Date date1(15, 5, 2023);
    Date date2;
    date2 = date1;
    EXPECT_EQ(date2.getDay(), 15);
    EXPECT_EQ(date2.getMonth(), 5);
    EXPECT_EQ(date2.getYear(), 2023);
}

TEST(DateTest, GetDayMonthYear) 
{
    Date date(1, 1, 2023);
    EXPECT_EQ(date.getDayMonthYear(), "Date: 1/1/2023");
}


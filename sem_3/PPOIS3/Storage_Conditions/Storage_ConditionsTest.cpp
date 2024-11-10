#include <gtest/gtest.h>
#include "Storage_Conditions.h"
#include "Date.h"
#include "Climate_Placement.h"

TEST(StorageConditionsTest, DefaultConstructor) 
{
    Storage_Conditions sc;
    EXPECT_EQ(sc.getReceiptDate(), Date(1, 1, 2000));
    EXPECT_EQ(sc.getExpirationDate(), Date(1, 1, 2001));
    EXPECT_EQ(sc.getTypeCLimate().getNameOfPlacement(), "Unknown");
}

TEST(StorageConditionsTest, ConstructorInput)
{
    Date receiptDate(1, 6, 2023);
    Date expirationDate(1, 6, 2024);
    Climate_Placement climate("Cold Room", 5.0, 40);
    Storage_Conditions sc(receiptDate, expirationDate, climate);

    EXPECT_EQ(sc.getReceiptDate(), receiptDate);
    EXPECT_EQ(sc.getExpirationDate(), expirationDate);
    EXPECT_EQ(sc.getTypeCLimate().getNameOfPlacement(), "Cold Room");
}
TEST(StorageConditionsTest, ConstructorDates)
{
    Date receiptDate(1, 6, 2023);
    Date expirationDate(1, 6, 2022);
    Climate_Placement climate("Cold Room", 5.0, 40);
    EXPECT_THROW(Storage_Conditions(receiptDate, expirationDate, climate), std::invalid_argument);
}


TEST(StorageConditionsTest, GetReceiptDate) 
{
    Date receiptDate(1, 7, 2023);
    Storage_Conditions sc(receiptDate, Date(1, 7, 2024), Climate_Placement());
    EXPECT_EQ(sc.getReceiptDate(), receiptDate);
}
TEST(StorageConditionsTest, GetExpirationDate)
{
    Date expirationDate(1, 8, 2024);
    Storage_Conditions sc(Date(1, 8, 2023), expirationDate, Climate_Placement());
    EXPECT_EQ(sc.getExpirationDate(), expirationDate);
}
TEST(StorageConditionsTest, GetTypeClimate)
{
    Climate_Placement climate("Cool Storage", 10.0, 55);
    Storage_Conditions sc(Date(1, 8, 2023), Date(1, 8, 2024), climate);
    EXPECT_EQ(sc.getTypeCLimate().getNameOfPlacement(), "Cool Storage");
}


TEST(StorageConditionsTest, IsExpired) 
{
    Date receiptDate(1, 8, 2023);
    Date expirationDate(1, 8, 2024);
    Storage_Conditions sc(receiptDate, expirationDate, Climate_Placement());

    Date currentDate(1, 8, 2025);
    EXPECT_TRUE(sc.isExpired(currentDate));

    Date currentDateBeforeExp(1, 8, 2024); 
    EXPECT_FALSE(sc.isExpired(currentDateBeforeExp));

    Date currentDateBefore(1, 8, 2023); 
    EXPECT_FALSE(sc.isExpired(currentDateBefore));
}

TEST(StorageConditionsTest, DaysBetweenExpirationBefore) 
{
    Date receiptDate(1, 8, 2023);
    Date expirationDate(3, 8, 2024);
    Storage_Conditions sc(receiptDate, expirationDate, Climate_Placement());

    Date currentDate(1, 8, 2024);
    Date daysBetween = sc.daysBetwExp(currentDate);
    EXPECT_LT(daysBetween.getDay(), 2); 
}

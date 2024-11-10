#include <gtest/gtest.h>
#include "Product.h"
#include "Date.h"
#include "Storage_Conditions.h"
#include "Climate_Placement.h"


TEST(ProductTest, DefaultConstructor)
{
    Product product;
    EXPECT_EQ(product.getNameOfProduct(), "Unknown");
    EXPECT_EQ(product.getCategory(), "General");
    EXPECT_EQ(product.getRatingOfProduct(), 0.0);
}


TEST(ProductTest, ConstructorInput) {
    Date receiptDate(1, 6, 2023);
    Date expirationDate(1, 6, 2024);
    Climate_Placement climate("Cold Storage", 5.0, 40);
    Storage_Conditions storageConditions(receiptDate, expirationDate, climate);

    Product product("Milk", "Dairy", 8.5, storageConditions);

    EXPECT_EQ(product.getNameOfProduct(), "Milk");
    EXPECT_EQ(product.getCategory(), "Dairy");
    EXPECT_DOUBLE_EQ(product.getRatingOfProduct(), 8.5);
    EXPECT_EQ(product.conditions.getReceiptDate(), receiptDate);
    EXPECT_EQ(product.conditions.getExpirationDate(), expirationDate);
}

TEST(ProductTest, ConstructorName)
{
    Date receiptDate(1, 6, 2023);
    Date expirationDate(1, 6, 2024);
    Climate_Placement climate("Cold Storage", 5.0, 40);
    Storage_Conditions storageConditions(receiptDate, expirationDate, climate);

    EXPECT_THROW(Product("", "Dairy", 8.5, storageConditions), std::invalid_argument);
}
TEST(ProductTest, ConstructorCategory)
{
    Date receiptDate(1, 6, 2023);
    Date expirationDate(1, 6, 2024);
    Climate_Placement climate("Cold Storage", 5.0, 40);
    Storage_Conditions storageConditions(receiptDate, expirationDate, climate);

    EXPECT_THROW(Product("Milk", "", 8.5, storageConditions), std::invalid_argument);
}
TEST(ProductTest, ConstructorRating) 
{
    Date receiptDate(1, 6, 2023);
    Date expirationDate(1, 6, 2024);
    Climate_Placement climate("Cold Storage", 5.0, 40);
    Storage_Conditions storageConditions(receiptDate, expirationDate, climate);

    EXPECT_THROW(Product("Milk", "Dairy", 12.0, storageConditions), std::invalid_argument);
}


TEST(ProductTest, GetNameOfProduct) 
{
    Product product("Cheese", "Dairy", 7.8, Storage_Conditions());
    EXPECT_EQ(product.getNameOfProduct(), "Cheese");
}
TEST(ProductTest, GetCategory)
{
    Product product("Bread", "Bakery", 8.0, Storage_Conditions());
    EXPECT_EQ(product.getCategory(), "Bakery");
}
TEST(ProductTest, GetRatingOfProduct) 
{
    Product product("Juice", "Beverages", 6.5, Storage_Conditions());
    EXPECT_DOUBLE_EQ(product.getRatingOfProduct(), 6.5);
}

TEST(ProductTest, IsExpiringSoonFalse) 
{
    Date receiptDate(1, 6, 2023);
    Date expirationDate(20, 6, 2023);
    Climate_Placement climate("Refrigerator", 4.0, 60);
    Storage_Conditions storageConditions(receiptDate, expirationDate, climate);

    Product product("Butter", "Dairy", 7.0, storageConditions);
    Date currentDate(8, 6, 2023);
    EXPECT_FALSE(product.isExpiringSoon(currentDate, 7));
}


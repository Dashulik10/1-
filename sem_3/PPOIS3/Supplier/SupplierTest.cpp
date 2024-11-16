#include <gtest/gtest.h>
#include "Supplier.h"
#include "Contact_Info.h"

TEST(SupplierTest, DefaultConstructor) 
{
    Supplier supplier;
    EXPECT_EQ(supplier.getNameOfSupplier(), "Unknown");
    EXPECT_EQ(supplier.getCategoryOfGoods(), "General");
    EXPECT_DOUBLE_EQ(supplier.getRatingOfSupplier(), 0.0);

    ContactInfo defaultContact;
    EXPECT_EQ(supplier.getContactInfo().getTelephoneNumber(), defaultContact.getTelephoneNumber());
    EXPECT_EQ(supplier.getContactInfo().getEmail(), defaultContact.getEmail());
}


TEST(SupplierTest, ConstructorInput) 
{
    ContactInfo contact("+1234567890123", "test@supplier.com");
    Supplier supplier("ABC Corp", contact, "Electronics", 9.0);

    EXPECT_EQ(supplier.getNameOfSupplier(), "ABC Corp");
    EXPECT_EQ(supplier.getContactInfo().getTelephoneNumber(), "+1234567890123");
    EXPECT_EQ(supplier.getContactInfo().getEmail(), "test@supplier.com");
    EXPECT_EQ(supplier.getCategoryOfGoods(), "Electronics");
    EXPECT_DOUBLE_EQ(supplier.getRatingOfSupplier(), 9.0);
}
TEST(SupplierTest, ConstructorInvalidName) 
{
    ContactInfo contact("+1234567890123", "test@supplier.com");
    EXPECT_THROW(Supplier("", contact, "Electronics", 9.0), std::invalid_argument);
}
TEST(SupplierTest, ConstructorInvalidCategory)
{
    ContactInfo contact("+1234567890123", "test@supplier.com");
    EXPECT_THROW(Supplier("ABC Corp", contact, "", 9.0), std::invalid_argument);
}
TEST(SupplierTest, ConstructorInvalidRating)
{
    ContactInfo contact("+1234567890123", "test@supplier.com");
    EXPECT_THROW(Supplier("ABC Corp", contact, "Electronics", 11.0), std::invalid_argument);  
    EXPECT_THROW(Supplier("ABC Corp", contact, "Electronics", -1.0), std::invalid_argument); 
}


TEST(SupplierTest, SupplierRatingInfo)
{
    ContactInfo contact("+1234567890123", "test@supplier.com");

    Supplier excellentSupplier("Excellent Supplier", contact, "Electronics", 9.0);
    EXPECT_EQ(excellentSupplier.SupplierRatingInfo(), "Excellent supplier with high reliability!");

    Supplier goodSupplier("Good Supplier", contact, "Electronics", 6.0);
    EXPECT_EQ(goodSupplier.SupplierRatingInfo(), "Good supplier, but there may be occasional issues.");

    Supplier poorSupplier("Poor Supplier", contact, "Electronics", 4.0);
    EXPECT_EQ(poorSupplier.SupplierRatingInfo(), "Supplier needs improvement in reliability and quality.");
}


TEST(SupplierTest, Getters) 
{
    ContactInfo contact("+1234567890123", "test@supplier.com");
    Supplier supplier("XYZ Ltd", contact, "Clothing", 7.5);

    EXPECT_EQ(supplier.getNameOfSupplier(), "XYZ Ltd");
    EXPECT_EQ(supplier.getContactInfo().getTelephoneNumber(), "+1234567890123");
    EXPECT_EQ(supplier.getContactInfo().getEmail(), "test@supplier.com");
    EXPECT_EQ(supplier.getCategoryOfGoods(), "Clothing");
    EXPECT_DOUBLE_EQ(supplier.getRatingOfSupplier(), 7.5);
}

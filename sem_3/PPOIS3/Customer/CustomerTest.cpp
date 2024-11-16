#include <gtest/gtest.h>
#include "Customer.h"
#include "Contact_Info.h"
#include "Product.h"
#include "Date.h"
#include "Climate_Placement.h"
#include "Storage_Conditions.h"


TEST(CustomerTest, DefaultConstructor) 
{
    Customer customer;

    testing::internal::CaptureStdout();
    customer.CustomerInfo();
    std::string output = testing::internal::GetCapturedStdout();

}

TEST(CustomerTest, ParameterizedConstructorEmptyName) 
{
    ContactInfo contact("123-456-7890", "customer@example.com");
    Date receiptDate(1, 6, 2023);
    Date expirationDate(1, 6, 2024);
    Climate_Placement climate("Cold Storage", 5.0, 40);
    Storage_Conditions storageConditions(receiptDate, expirationDate, climate);

    Product product("Milk", "Dairy", 8.5, storageConditions);
    std::vector<Product> products = { product };

    EXPECT_THROW(Customer customer("", contact, products), invalid_argument); 
}


TEST(CustomerTest, ParameterizedConstructorEmptyProductList) 
{
    ContactInfo contact("123-456-7890", "customer@example.com");

    EXPECT_THROW(Customer customer("John Doe", contact, {}), invalid_argument);  
}

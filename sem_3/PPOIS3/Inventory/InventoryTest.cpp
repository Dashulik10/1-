#include <gtest/gtest.h>
#include "Inventory.h"
#include "Date.h"
#include "Statistic.h"
#include "Product.h"
#include "Warehouse_Department.h"


TEST(InventoryTest, DefaultConstructor) 
{
    Inventory inventory;
    EXPECT_EQ(inventory.checkExpectedGoods(), "The actual number of products matches the expected count.");

    Date current_date(10, 11, 2023);
    string info = inventory.InventoryInfo(current_date);

    EXPECT_NE(info.find("Expected Number of Goods: 0"), string::npos);
    EXPECT_NE(info.find("Actual Number of Goods: 0"), string::npos);
}

TEST(InventoryTest, ConstructorData) 
{
    Date inventory_date(20, 10, 2023);
    vector<Product> products = 
    { 
        Product("Laptop", "Electronics", 9.0, Storage_Conditions()), 
        Product("Tablet", "Electronics", 8.0, Storage_Conditions()) 
    };
        Climate_Placement cp1 ("General", 20.0, 50);
        string name1 = "Electronics";
        int a1 = 20;
        int b1 = 5;
        Warehouse_Department wd1 (name1, a1, b1, cp1); 
    vector<Warehouse_Department> departments = { wd1 };
    Statistic stat(products, departments);
    Inventory inventory(inventory_date, 2, stat);

    EXPECT_EQ(inventory.checkExpectedGoods(), "The actual number of products matches the expected count.");
}

   TEST(StatisticTest, ConstructorInvalidData) 
   {
       std::vector<Product> products;
       std::vector<Warehouse_Department> departments;

       EXPECT_THROW({
           Statistic stat(products, departments);
       }, std::invalid_argument);
   }


TEST(InventoryTest, CheckExpectedGoodsMismatch)
{
    Date inventory_date(30, 9, 2023);
    vector<Product> products = { Product("Chair", "Furniture", 7.5, Storage_Conditions()) };

    Climate_Placement cp2 ("General", 20.0, 50);
        string name2 = "Electronics";
        int a2 = 20;
        int b2 = 5;
        Warehouse_Department wd2 (name2, a2, b2, cp2); 

    vector<Warehouse_Department> departments = { wd2
    };
    Statistic stat(products, departments);
    Inventory inventory(inventory_date, 2, stat);

    EXPECT_EQ(inventory.checkExpectedGoods(), "Mismatch in product count. Expected: 2, Actual: 1");
}

TEST(InventoryTest, InventoryInfo)
{
    Date inventory_date(15, 10, 2023);
    vector<Product> products = { Product("Desk", "Office", 7.8, Storage_Conditions()) };

        Climate_Placement cp4 ("Storage", 18.0, 55);
        string name4 = "Office";
        int a4 = 15;
        int b4 = 7;
        Warehouse_Department wd4 (name4, a4, b4, cp4); 

    vector<Warehouse_Department> departments = { wd4};
    Statistic stat(products, departments);
    Inventory inventory(inventory_date, 1, stat);

    Date current_date(30, 10, 2023);
    string info = inventory.InventoryInfo(current_date);

    EXPECT_NE(info.find("Inventory Date: 15/10/2023"), string::npos);
    EXPECT_NE(info.find("Expected Number of Goods: 1"), string::npos);
    EXPECT_NE(info.find("Actual Number of Goods: 1"), string::npos);
}
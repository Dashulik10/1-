#include <gtest/gtest.h>
#include "Statistic.h"
#include "Product.h"
#include "Warehouse_Department.h"
#include "Climate_Placement.h"


TEST(StatisticTest, DefaultConstructor) 
{
    Statistic stat;

    EXPECT_EQ(stat.getProductionSize(), 0);
    EXPECT_EQ(stat.ProductInfo(), "No products in storage.\n");
    EXPECT_EQ(stat.DepartmentInfo(), "No departments in warehouse.\n");
    EXPECT_EQ(stat.OccupancyInfo(), "No departments to show occupancy information.\n");
}


TEST(StatisticTest, ConstructorInvalidData)
{
    vector<Product> emptyProducts;
    vector<Warehouse_Department> emptyDepartments;

    Climate_Placement climate1("Storage", 15.0, 60);
    string name2 = "Furniture Dept";
    int a2 = 10; 
    int b2 = 5;
    Warehouse_Department dept1(name2, a2, b2, climate1);
    vector<Warehouse_Department> departments = { dept1 };
    EXPECT_THROW(Statistic(emptyProducts, departments), invalid_argument);

    Product product("Sofa", "Furniture", 7.0, Storage_Conditions());
    vector<Product> products = { product };
    EXPECT_THROW(Statistic(products, emptyDepartments), invalid_argument);
}


TEST(StatisticTest, GetProductionSize) 
{
    Product product1("Television", "Electronics", 8.0, Storage_Conditions());
    Product product2("Desk", "Furniture", 7.5, Storage_Conditions());
    vector<Product> products = { product1, product2 };

    Climate_Placement climate("Storage", 20.0, 40);
    string name7 = "Electronics";
    int a7 = 12; 
    int b7 = 3;
    Warehouse_Department dept(name7, a7, b7, climate);
    vector<Warehouse_Department> departments = { dept };

    Statistic stat(products, departments);

    EXPECT_EQ(stat.getProductionSize(), 2);
}

// Тест метода ProductInfo
TEST(StatisticTest, ProductInfo)
{
    Product product1("Laptop", "Electronics", 9.5, Storage_Conditions());
    Product product2("Chair", "Furniture", 8.0, Storage_Conditions());
    vector<Product> products = { product1, product2 };

    Climate_Placement climate("Main Storage", 18, 50);
    string name1 = "Main Department";
    int a1 = 20;
    int b1 = 10;
    Warehouse_Department dept(name1, a1, b1, climate);
    vector<Warehouse_Department> departments = { dept };

    Statistic stat(products, departments);

    string expectedOutput = "Products in storage:\n";
    expectedOutput += "- Product Name: Laptop, Category: Electronics, Rating: 9.500000\n";
    expectedOutput += "- Product Name: Chair, Category: Furniture, Rating: 8.000000\n";

    EXPECT_EQ(stat.ProductInfo(), expectedOutput);
}

// Тест метода DepartmentInfo
TEST(StatisticTest, DepartmentInfo)
{
    Climate_Placement climate1("Dry Storage", -10.0, 90);
    Climate_Placement climate2("Warehouse", 20.0, 30);

    string name2 = "Frozen Goods";
    int a2 = 5;
    int b2 = 3;
    Warehouse_Department dept1(name2, a2, b2, climate1);
    string name3 = "General Storage";
    int a3 = 15;
    int b3 = 10;
    Warehouse_Department dept2(name3, a3, b3, climate2);
    vector<Warehouse_Department> departments = { dept1, dept2 };

    Product product("Milk", "Dairy", 6.5, Storage_Conditions());
    vector<Product> products = { product };

    Statistic stat(products, departments);

    string expectedOutput = "Warehouse Departments:\n";
    expectedOutput += "- Department Name: Frozen Goods, Placement Type: Freezer\n";
    expectedOutput += "- Department Name: General Storage, Placement Type: Dry Storage\n";

    EXPECT_EQ(stat.DepartmentInfo(), expectedOutput);
}

// Тест метода OccupancyInfo
TEST(StatisticTest, OccupancyInfo)
{
    Climate_Placement climate("Cold Storage", 5.0, 75);
    string name4 = "Cold Section";
    int a4 = 8;
    int b4 = 4;
    Warehouse_Department dept(name4, a4, b4, climate);
    vector<Warehouse_Department> departments = { dept };

    Product product("Butter", "Dairy", 7.0, Storage_Conditions());
    vector<Product> products = { product };

    Statistic stat(products, departments);

    string expectedOutput = "Warehouse Department Occupancy:\n";
    expectedOutput += "- Cold Section:\n";
    expectedOutput += "  Available places: 8\n";
    expectedOutput += "  Occupied places: 4\n";
    expectedOutput += "  Occupancy rate: 33.333333%\n";

    EXPECT_EQ(stat.OccupancyInfo(), expectedOutput);
}
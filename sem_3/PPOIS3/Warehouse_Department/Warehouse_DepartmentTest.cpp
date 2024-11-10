#include <gtest/gtest.h>
#include "Warehouse_Department.h"
#include "Climate_Placement.h"

TEST(WarehouseDepartmentTest, ConstructorData) 
{
    string name = "Electronics";
    int available = 10;
    int notAvailable = 5;
    Climate_Placement climate("Storage", 10.0, 30);

    Warehouse_Department department(name, available, notAvailable, climate);

    EXPECT_EQ(department.getNameOfDepartment(), "Electronics");
    EXPECT_EQ(department.getNumberOfAvailablePlaces(), 10);
    EXPECT_EQ(department.getNumberOfNotavailablePlaces(), 5);
    EXPECT_EQ(department.getPlacementTypeName(), "Refrigerator"); 
}


TEST(WarehouseDepartmentTest, ConstructorInvalidData) 
{
    string name = "";
    int available = -1;
    int notAvailable = -2;
    Climate_Placement climate("Storage", 5.0, 20);

    EXPECT_THROW(Warehouse_Department(name, available, notAvailable, climate), std::invalid_argument);

    name = "Appliances";
    available = -1;
    notAvailable = 3;
    EXPECT_THROW(Warehouse_Department(name, available, notAvailable, climate), std::invalid_argument);

    available = 5;
    notAvailable = -2;
    EXPECT_THROW(Warehouse_Department(name, available, notAvailable, climate), std::invalid_argument);
}

TEST(WarehouseDepartmentTest, PrintDepartmentOccupancyInfo) 
{
    string name = "Furniture";
    int available = 15;
    int notAvailable = 5;
    Climate_Placement climate("General Storage", 22.0, 60);

    Warehouse_Department department(name, available, notAvailable, climate);

    testing::internal::CaptureStdout();
    department.printDepartmentOccupancyInfo();
    string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Department: Furniture"), string::npos);
    EXPECT_NE(output.find("Available places: 15"), string::npos);
    EXPECT_NE(output.find("Occupied places: 5"), string::npos);
    EXPECT_NE(output.find("Occupancy rate: 25%"), string::npos);  // 5 �� 20 ���� ������
}

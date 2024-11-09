#include <gtest/gtest.h>
#include "Climate_Placement.h"

TEST(ClimatePlacementTest, DefaultConstructor)
{
    Climate_Placement cp;
    EXPECT_EQ(cp.getNameOfPlacement(), "Unknown");
    EXPECT_DOUBLE_EQ(cp.getTemperature(), 0.0);
    EXPECT_EQ(cp.getPresentOfHumidity(), 0);
}
TEST(ClimatePlacementTest, Constructorf)
{
    Climate_Placement cp("Cold Storage", -5.0, 30);
    EXPECT_EQ(cp.getNameOfPlacement(), "Cold Storage");
    EXPECT_DOUBLE_EQ(cp.getTemperature(), -5.0);
    EXPECT_EQ(cp.getPresentOfHumidity(), 30);
}
TEST(ClimatePlacementTest, Constructors)
{
    EXPECT_THROW(Climate_Placement("", 5.0, 40), std::invalid_argument);
}
TEST(ClimatePlacementTest, Constructorth) 
{
    EXPECT_THROW(Climate_Placement("Storage", 5.0, -10), std::invalid_argument);
}
TEST(ClimatePlacementTest, Constructorfor)
{
    EXPECT_THROW(Climate_Placement("Storage", 5.0, 150), std::invalid_argument);
}


TEST(ClimatePlacementTest, GetNameOfPlacement)
{
    Climate_Placement cp("Warehouse", 15.0, 60);
    EXPECT_EQ(cp.getNameOfPlacement(), "Warehouse");
}
TEST(ClimatePlacementTest, GetTemperature)
{
    Climate_Placement cp("Storage Room", 20.0, 55);
    EXPECT_DOUBLE_EQ(cp.getTemperature(), 20.0);
}
TEST(ClimatePlacementTest, GetPresentOfHumidity)
{
    Climate_Placement cp("Storage Room", 20.0, 55);
    EXPECT_EQ(cp.getPresentOfHumidity(), 55);
}


TEST(ClimatePlacementTest, GetStorageTypeFreezer)
{
    Climate_Placement cp("Cold Room", -10.0, 30);
    EXPECT_EQ(cp.getStorageType(), "Freezer");
}
TEST(ClimatePlacementTest, GetStorageTypeRefrigerator) 
{
    Climate_Placement cp("Fridge Room", 5.0, 45);
    EXPECT_EQ(cp.getStorageType(), "Refrigerator");
}
TEST(ClimatePlacementTest, GetStorageTypeDryStorage)
{
    Climate_Placement cp("Dry Goods Room", 15.0, 40);
    EXPECT_EQ(cp.getStorageType(), "Dry Storage");
}
TEST(ClimatePlacementTest, GetStorageTypeNormalStorage) 
{
    Climate_Placement cp("General Storage", 15.0, 60);
    EXPECT_EQ(cp.getStorageType(), "Normal Storage");
}
TEST(ClimatePlacementTest, GetStorageTypeWarmStorage) 
{
    Climate_Placement cp("Warm Room", 30.0, 70);
    EXPECT_EQ(cp.getStorageType(), "Warm Storage");
}

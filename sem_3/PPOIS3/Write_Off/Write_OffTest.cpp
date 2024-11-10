#include <gtest/gtest.h>
#include "Write_Off.h"
#include "Date.h"


TEST(WriteOffTest, DefaultConstructor)
{
    Write_off write_off;
    EXPECT_EQ(write_off.getDateOfWritingOff(), "Date: 1/1/2000");
    EXPECT_EQ(write_off.getReasonOfWritingOff(), "No reason");  
}

TEST(WriteOffTest, ConstructorValidData) 
{
    Date date(15, 10, 2023);
    string reason = "Product expired";
    Write_off write_off(date, reason);

    EXPECT_EQ(write_off.getDateOfWritingOff(), "Date: 15/10/2023"); 
    EXPECT_EQ(write_off.getReasonOfWritingOff(), "Product expired"); 
}


TEST(WriteOffTest, ParameterizedConstructorEmptyReason) 
{
    Date date(15, 10, 2023);
    string empty_reason = "";

    EXPECT_THROW(Write_off write_off(date, empty_reason), invalid_argument);  
}


TEST(WriteOffTest, GetReasonOfWritingOff)
{
    Date date(15, 10, 2023);
    string reason = "Damaged during transport";
    Write_off write_off(date, reason);

    EXPECT_EQ(write_off.getReasonOfWritingOff(), "Damaged during transport");
}


TEST(WriteOffTest, GetDateOfWritingOff)
{
    Date date(10, 5, 2023);
    string reason = "Inventory adjustment";
    Write_off write_off(date, reason);

    EXPECT_EQ(write_off.getDateOfWritingOff(), "Date: 10/5/2023");
}

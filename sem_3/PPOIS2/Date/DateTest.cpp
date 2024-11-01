#include <gtest/gtest.h>
#include "Date.h"

TEST(DateTest, TestGetDayMonthYear) {
    Date date(15, 10, 2023);
    EXPECT_EQ(date.Date::getDayMonthYear(), "Date: 15/10/2023");
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "RU");
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
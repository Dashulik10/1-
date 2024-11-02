#include <gtest/gtest.h>
#include "Discount.h"

TEST(DiscountTest, GetPercent) {
    Discount discount(15);
    EXPECT_EQ(discount.getDiscountPercent(), 15);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

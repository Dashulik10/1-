#include <gtest/gtest.h>
#include "Payment.h"
#include "Discount.h"

TEST(PaymentTest, Constructor) {
    Payment payment;
    EXPECT_EQ(payment.getStatus(), "");
    EXPECT_DOUBLE_EQ(payment.getDiscountedPrice(), 0.0);
}

TEST(PaymentTest, ParConstructor) {
    Discount dis(20);
    Payment payment(100.0, "Paid", dis);

    EXPECT_EQ(payment.getStatus(), "Paid");     
    EXPECT_DOUBLE_EQ(payment.getDiscountedPrice(), 80.0); 
}

TEST(PaymentTest, GetDiscountedPriceNoDiscount) {
    Discount discount(0);
    Payment payment(200.0, "Paid", discount);

    EXPECT_DOUBLE_EQ(payment.getDiscountedPrice(), 200.0); 
}

TEST(PaymentTest, GetStatus) {
    Discount discount(10);
    Payment payment(100.0, "Pending", discount);

    EXPECT_EQ(payment.getStatus(), "Pending");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
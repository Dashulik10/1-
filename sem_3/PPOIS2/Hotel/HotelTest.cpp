#include <gtest/gtest.h>
#include "Hotel.h"
#include "ContactInfo.h"

TEST(HotelTest, Constructor) {
    Hotel ht;
    EXPECT_EQ(ht.hotelPayment(1), 0.0);
}

TEST(HotelTest, ParConstructor) {
    ContactInfo info("+375259689451", "dasha@mail.com");
    Hotel ht("Hotel California", info, 100.0, 4.5);
    
    EXPECT_EQ(ht.hotelPayment(1), 100.0); 
    EXPECT_EQ(ht.hotelPayment(2), 200.0); 
    EXPECT_EQ(ht.hotelPayment(3), 300.0);
}

TEST(HotelTest, HotelCount) {
    ContactInfo info("+375259689451", "dasha@mail.com");
    Hotel ht("Grand Hotel", info, 150.0, 5.0);
    
    EXPECT_EQ(ht.hotelPayment(3), 450.0);
    EXPECT_EQ(ht.hotelPayment(5), 750.0); 
    EXPECT_EQ(ht.hotelPayment(10), 1500.0); 
}
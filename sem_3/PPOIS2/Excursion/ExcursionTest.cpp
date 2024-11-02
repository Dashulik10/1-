#include <gtest/gtest.h>
#include "Excursion.h"
#include "Guide.h"
#include "ContactInfo.h"

TEST(ExcursionTest, Constructor) {
    Excursion exc;
    EXPECT_EQ(exc.getNameOfExcursion(), "");
}

TEST(ExcursionTest, ParConstructor) {
    ContactInfo info("+375259689451", "dasha@example.com");
    vector<string> languages = { "English", "Spanish" };
    Guide rab("Dasha", "Sergievich", "female", info, "Guide", 7.5, languages);

    Excursion exc("City Tour", "A tour through the historic center", rab);
    EXPECT_EQ(exc.getNameOfExcursion(), "City Tour");
}

TEST(ExcursionTest, GetName) {
    Excursion exc1;
    EXPECT_EQ(exc1.getNameOfExcursion(), "");

    ContactInfo info("+1234567890123", "guide@example.com");
    vector<string> languages = { "French" };
    Guide guide("Dasha", "Sergievich", "female", info, "Guide", 8.0, languages);

    Excursion exc2("Museum Visit", "A guided visit to the main museum", guide);
    EXPECT_EQ(exc2.getNameOfExcursion(), "Museum Visit");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
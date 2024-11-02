#include <gtest/gtest.h>
#include "Emploee.h"
#include "ContactInfo.h"

TEST(EmploeeTest, Constructor) {
    Emploee rab;
    EXPECT_EQ(rab.getPostInfo(), ": General responsibilities.");
    EXPECT_FALSE(rab.checkingAccessToConfidentialDocs());
    EXPECT_EQ(rab.getCertificatePerformance(), "Performance needs improvement.");
}

TEST(EmploeeTest, ParConstructor) {
    ContactInfo info("+375259689451", "dasha@mail.com");
    Emploee rab("Dasha", "Sergievich", "female", info, "Manager", 9.0);
    EXPECT_EQ(rab.getPostInfo(), "Manager: Responsible for organizing tourist travel.");
    EXPECT_TRUE(rab.checkingAccessToConfidentialDocs());
    EXPECT_EQ(rab.getCertificatePerformance(), "Excellent performance!");
}

TEST(EmploeeTest, Post) {
    ContactInfo info("+375259689451", "dasha@mail.com");

    Emploee rab1("Dasha", "Sergievich", "female", info, "Manager", 7.0);
    EXPECT_EQ(rab1.getPostInfo(), "Manager: Responsible for organizing tourist travel.");

    Emploee rab2("Yana", "Banka", "female", info, "Guide", 6.0);
    EXPECT_EQ(rab2.getPostInfo(), "Guide: Responsible for stories, organizing tourist trips, finding interesting and safe routes along the route, resolving conflict or emergency situations.");

    Emploee rab3("Elisay", "Rimont", "male", info, "Agent", 8.5);
    EXPECT_EQ(rab3.getPostInfo(), "Agent: Responsible for calculating the final cost of the trip, booking tickets, accommodation, visa processing.");

    Emploee who("Marat", "Pereversev", "male", info, "Consultant", 7.5);
    EXPECT_EQ(who.getPostInfo(), "Consultant: General responsibilities.");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
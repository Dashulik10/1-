#include <gtest/gtest.h>
#include "TravelAgency.h"

TEST(TravelAgencyTest, Constructor) {
    TravelAgency ag;
    EXPECT_EQ(ag.getNameOfTrAgencyAndWSite(), "Travel Agency: . Website: . ");
}

TEST(TravelAgencyTest, ParConstructor) {
    TravelAgency ag("Best Travels", "https://jessica.com");
    EXPECT_EQ(ag.getNameOfTrAgencyAndWSite(), "Travel Agency: Best Travels. Website: https://jessica.com. ");
}
TEST(TravelAgencyTest, WebsiteCheck) {
    TravelAgency ag;
    ag.setWebSite("https://jessica.com");
    EXPECT_TRUE(ag.checkingExistanceSite());
}
TEST(TravelAgencyTest, Message) {
    TravelAgency ag;
    string message = "an update will be released soon!";
    EXPECT_EQ(ag.messageToClient(message), "Dear client, an update will be released soon!");
}
TEST(TravelAgencyTest, SetGet) {
    TravelAgency ag;
    ag.setNameOfTravelAgency("Jessika relax");
    ag.setWebSite("http://jessika.com");
    EXPECT_EQ(ag.getNameOfTrAgencyAndWSite(), "Travel Agency: Jessika relax. Website: http://jessika.com. ");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
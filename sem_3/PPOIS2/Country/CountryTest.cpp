#include <gtest/gtest.h>
#include "Country.h"

TEST(CountryTest, Constructor) {
    Country strana;
    EXPECT_EQ(strana.getNameOfCountry(), "Name of country: . Kod of country: . ");
}

TEST(CountryTest, ParConstructor) {
    Country strana("India", "IN");
    EXPECT_EQ(strana.getNameOfCountry(), "Name of country: India. Kod of country: IN. ");
}

TEST(CountryTest, ListLanguages) {
    Country usa("USA", "US");
    EXPECT_EQ(usa.getOficialListOfLanguages(), vector<string>({ "English" }));

    Country india("India", "IN");
    EXPECT_EQ(india.getOficialListOfLanguages(), vector<string>({ "Hindi", "English" }));
}

TEST(CountryTest, UnknownCountry) {
    Country un("Atlantis", "AT");
    EXPECT_EQ(un.getOficialListOfLanguages(), vector<string>({ "Unknown" }));
}

TEST(CountryTest, UnknownKod) {
    Country un("SmallCountry", "SC");
    EXPECT_EQ(un.getNameOfContenentByKod(), "Unknown");
}
TEST(CountryTest, SetGet) {
    Country strana;
    strana.setNameOfCountry("Brazil");
    strana.setKodOfCountry("BR");
    EXPECT_EQ(strana.getNameOfCountry(), "Name of country: Brazil. Kod of country: BR. ");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

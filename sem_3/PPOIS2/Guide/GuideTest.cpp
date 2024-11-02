#include <gtest/gtest.h>
#include "Guide.h"
#include "ContactInfo.h"

TEST(GuideTest, Constructor) {
    Guide rab;
    EXPECT_EQ(rab.getListOfLanguages(), "Languages known: ");
}

TEST(GuideTest, ParConstructor) {
    ContactInfo info("+375259689451", "dasha@mail.com");
    vector<string> languages = { "English", "Russian" };
    Guide guide("Vitala", "Olihver", "male", info, "Guide", 7.5, languages);
    EXPECT_EQ(guide.getListOfLanguages(), "Languages known: English, Russian");
}

TEST(GuideTest, AddNewLanguageGood) {
    Guide rab;
    EXPECT_TRUE(rab.addNewLanguage("C++"));
    EXPECT_EQ(rab.getListOfLanguages(), "Languages known: C++");
}

TEST(GuideTest, AddNewLanguageBad) {
    vector<string> languages = { "Spanish" };
    Guide rab("Misha", "Zabkov", "male", ContactInfo(), "Guide", 2.0, languages);
    EXPECT_FALSE(rab.addNewLanguage("Spanish"));
    EXPECT_EQ(rab.getListOfLanguages(), "Languages known: Spanish");
}

TEST(GuideTest, GetListOfLanguages_MultipleLanguages) {
    vector<string> languages = { "English", "Russian", "German" };
    Guide rab("Polina", "pechinskaya", "female", ContactInfo(), "Guide", 3.0, languages);
    EXPECT_EQ(rab.getListOfLanguages(), "Languages known: English, Russian, German");
}


int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
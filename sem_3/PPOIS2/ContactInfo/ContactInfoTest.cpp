#include <gtest/gtest.h>
#include "ContactInfo.h"


TEST(ContactInfoTest, Constructor) {
    ContactInfo info;
    EXPECT_EQ(info.getTelephoneNumber(), "");
    EXPECT_EQ(info.getEmail(), "");
}
TEST(ContactInfoTest, ParConstructor) {
    ContactInfo info("+375259689451", "dasha@mail.com");
    EXPECT_EQ(info.getTelephoneNumber(), "+375259689451");
    EXPECT_EQ(info.getEmail(), "dasha@mail.com");
}
TEST(ContactInfoTest, EmailCheck) {
    ContactInfo eminfo;
    eminfo.setEmail("dasha@example.com");
    EXPECT_TRUE(eminfo.emailInputCheck());
}
TEST(ContactInfoTest, PhoneCheck) {
    ContactInfo Phinfo;
    Phinfo.setTelephoneNumber("+375259689451");
    EXPECT_TRUE(Phinfo.phoneInputCheck());
}
TEST(ContactInfoTest, CompleteInfo) {
    ContactInfo fullinfo("+375259689451", "dasha@mail.com");
    EXPECT_TRUE(fullinfo.isContactInfCompl());
}
TEST(ContactInfoTest, NonfullCompleteInfo) {
    ContactInfo nonfullinfo("", "dasha@mail.com");
    EXPECT_FALSE(nonfullinfo.isContactInfCompl());
}
TEST(ContactInfoTest, SetGetTel) {
    ContactInfo PhInfo;
    PhInfo.setTelephoneNumber("+375259689451");
    EXPECT_EQ(PhInfo.getTelephoneNumber(), "+375259689451");
}
TEST(ContactInfoTest, SetGetEm) {
    ContactInfo Emailinfo;
    Emailinfo.setEmail("katusha@example.com");
    EXPECT_EQ(Emailinfo.getEmail(), "katusha@example.com");
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
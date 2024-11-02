#include <gtest/gtest.h>
#include "Person.h"
#include "ContactInfo.h"

/*TEST(PersonTest, ParConstructor) {
    ContactInfo info("+375259689451", "dasha@mail.com");
    Person man("Dasha", "Sergievich", "female", info);
    EXPECT_EQ(man.getClientGender(), "Ms.");
    EXPECT_TRUE(man.CorrectnessContactInf());
}*/

TEST(PersonTest, Male) {
    Person man("Danik", "Bizunov", "male", ContactInfo());
    EXPECT_EQ(man.getClientGender(), "Mr.");
}

TEST(PersonTest, Female) {
    Person man("Nastya", "Bizunova", "female", ContactInfo());
    EXPECT_EQ(man.getClientGender(), "Ms.");
}

TEST(PersonTest, Non) {
    Person yn("Yana", "Bankevich", "frog", ContactInfo());
    EXPECT_EQ(yn.getClientGender(), "Mx.");
}

TEST(PersonTest, CompleteInformation) {
    ContactInfo info("+375259689451", "dasha@mail.com");
    Person kt("Katya", "Rublevskaya", "female", info);
    EXPECT_TRUE(kt.CorrectnessContactInf());
}

TEST(PersonTest, NonCompleteInformaton) {
    ContactInfo info("", "daha@mail.com");
    Person man("Vanya", "Rubachev", "male", info);
    EXPECT_FALSE(man.CorrectnessContactInf());
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
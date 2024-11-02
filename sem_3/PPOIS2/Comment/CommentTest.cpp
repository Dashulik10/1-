#include <gtest/gtest.h>
#include "Comment.h"

TEST(CommentTest, Positive) {
    Comment posComment("Excellent experience!", 5);
    EXPECT_TRUE(posComment.isPositive()); 

    Comment neuComment("It was okay.", 3);
    EXPECT_FALSE(neuComment.isPositive());

    Comment negComment("Very disappointed.", 1);
    EXPECT_FALSE(negComment.isPositive());
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "RU");
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
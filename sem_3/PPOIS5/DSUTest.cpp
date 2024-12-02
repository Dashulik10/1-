#include <gtest/gtest.h>
#include "DSU.h"

TEST(DSUTests, Initialization) 
{
    DSU dsu(5);
    EXPECT_EQ(dsu.FindLeader(0), 0);
    EXPECT_EQ(dsu.FindLeader(1), 1);
    EXPECT_EQ(dsu.FindLeader(2), 2);
    EXPECT_EQ(dsu.FindLeader(3), 3);
    EXPECT_EQ(dsu.FindLeader(4), 4);
}

TEST(DSUTests, UnionAndFindLeader) 
{
    DSU dsu(5);

    dsu.UnionSet(0, 1);
    EXPECT_EQ(dsu.FindLeader(0), dsu.FindLeader(1));

    dsu.UnionSet(2, 3);
    EXPECT_EQ(dsu.FindLeader(2), dsu.FindLeader(3));
}

TEST(DSUTests, GetSize) {
    DSU dsu(5);

    dsu.UnionSet(0, 1);
    dsu.UnionSet(2, 3);
    dsu.UnionSet(1, 3);

    EXPECT_EQ(dsu.GetSize(0), 4); // –азмер множества, в котором находитс€ элемент 0, должен быть 4
}

TEST(DSUTests, SetNameAndGetName) 
{
    DSU dsu(5);

    dsu.SetName(0, "Group A");
    dsu.SetName(2, "Group B");

    EXPECT_EQ(dsu.GetName(0), "Group A");
    EXPECT_EQ(dsu.GetName(2), "Group B");
    EXPECT_EQ(dsu.GetName(4), "Unnamed Set");
}

TEST(DSUTests, Statement) 
{
    DSU dsu(5);
    dsu.UnionSet(0, 1);
    dsu.UnionSet(2, 3);
    dsu.UnionSet(1, 3);

    string expected = "“екущее состо€ние DSU:\n"
        "Ёлемент 0 -> Leader 0\n"
        "Ёлемент 1 -> Leader 0\n"
        "Ёлемент 2 -> Leader 0\n"
        "Ёлемент 3 -> Leader 0\n"
        "Ёлемент 4 -> Leader 4\n";

    EXPECT_EQ(dsu.Statement(), expected);
}

TEST(DSUTests, UnionSetDuplicate) 
{
    DSU dsu(5);

    EXPECT_EQ(dsu.UnionSet(0, 1), "Set1 is parent of Set2 now");
    EXPECT_EQ(dsu.UnionSet(1, 2), "Set2 is parent of Set1 now");
    EXPECT_EQ(dsu.UnionSet(0, 2), "Set1 and Set2 are already in the same set");
}


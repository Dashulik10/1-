#include "gtest/gtest.h"
#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include "IteratorAdjacency.h"
using namespace std;

TEST(IteratorAdjacencyTest, IncDec) 
{
    vector<int> neighbors = { 1, 2, 3 };
    IteratorAdjacency<int> it(neighbors, 0);

    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    --it;
    EXPECT_EQ(*it, 1);
    ++it;
    ++it;
    EXPECT_EQ(*it, 3);
}

TEST(IteratorAdjacencyTest, Comparison) 
{
    vector<int> neighbors = { 10, 11, 12 };
    IteratorAdjacency<int> it1(neighbors, 0);
    IteratorAdjacency<int> it2(neighbors, 0);
    IteratorAdjacency<int> it_end(neighbors, neighbors.size());

    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);
    it2 = it_end;
    EXPECT_TRUE(it1 != it_end);
    EXPECT_TRUE(it2 == it_end);
}

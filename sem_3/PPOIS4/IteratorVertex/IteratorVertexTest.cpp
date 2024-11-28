#include "gtest/gtest.h"
#include "IteratorVertex.h"

map<int, string> createVertexMap() 
{
    return {
        {0, "A"},
        {1, "B"},
        {2, "C"}
    };
}

TEST(IteratorVertexTest, IncrementAndDereference) 
{
    auto vertices = createVertexMap();

    IteratorVertex<string> it(vertices.begin(), vertices.end());
    IteratorVertex<string> end(vertices.end(), vertices.end());

    EXPECT_EQ(*it, "A");
    ++it;
    EXPECT_EQ(*it, "B");
    ++it;
    EXPECT_EQ(*it, "C");
    ++it;
    EXPECT_TRUE(it == end);
}

TEST(IteratorVertexTest, Comparison) 
{
    auto vertices = createVertexMap();

    IteratorVertex<string> it1(vertices.begin(), vertices.end());
    IteratorVertex<string> it2(vertices.begin(), vertices.end());
    IteratorVertex<string> it_end(vertices.end(), vertices.end());

    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);
    EXPECT_TRUE(it1 != it_end);
    ++it1;
    ++it1;
    EXPECT_TRUE(it1 == it_end);
}


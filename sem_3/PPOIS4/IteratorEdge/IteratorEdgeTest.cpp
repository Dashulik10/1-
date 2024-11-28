#include "gtest/gtest.h"
#include "IteratorEdge.h"

TEST(IteratorEdgeTest, IncDec) 
{
    vector<pair<int, int>> edges = { {0, 1}, {1, 2}, {2, 3} };
    IteratorEdge<int> it(edges.begin(), edges.end());

    EXPECT_EQ(*it, make_pair(0, 1));
    ++it;
    EXPECT_EQ(*it, make_pair(1, 2));
    --it;
    EXPECT_EQ(*it, make_pair(0, 1));
    ++it;
    ++it;
    EXPECT_EQ(*it, make_pair(2, 3));
}

TEST(IteratorEdgeTest, Comparison) {
    vector<pair<int, int>> edges = { {0, 1}, {1, 2}, {2, 3} };

    IteratorEdge<int> it1(edges.begin(), edges.end());
    IteratorEdge<int> it2(edges.begin(), edges.end());
    IteratorEdge<int> it_end(edges.end(), edges.end());

    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);
    EXPECT_TRUE(it_end != it2);
}

TEST(IteratorEdgeTest, EmptyContainer) 
{
    vector<pair<int, int>> edges;

    IteratorEdge<int> it(edges.begin(), edges.end());
    EXPECT_TRUE(it == IteratorEdge<int>(edges.end(), edges.end()));
}

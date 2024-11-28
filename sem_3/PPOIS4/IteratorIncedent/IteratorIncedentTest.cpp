#include "gtest/gtest.h"
#include "IteratorIncedent.h"

vector<vector<int>> createMatrix() 
{
    return 
    {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
}

vector<pair<int, int>> createEdges() 
{
    return 
    {
        {0, 1},
        {0, 2}, 
        {1, 2} 
    };
}

TEST(IteratorIncedentTest, IncrementAndDereference) 
{
    auto matrix = createMatrix();
    auto edges = createEdges();

    IteratorIncedent<int> it(matrix, edges, 0, 0);
    IteratorIncedent<int> end(matrix, edges, 0, edges.size());

    EXPECT_EQ(*it, make_pair(0, 1));
    ++it;
    EXPECT_EQ(*it, make_pair(0, 2));
    ++it;
    EXPECT_FALSE(it == end);
}

TEST(IteratorIncedentTest, Skip) 
{
    auto matrix = createMatrix();
    auto edges = createEdges();

    IteratorIncedent<int> it(matrix, edges, 1, 0);
    IteratorIncedent<int> end(matrix, edges, 1, edges.size());

    EXPECT_EQ(*it, make_pair(0, 1));
    ++it;
    EXPECT_FALSE(it == end);
}

TEST(IteratorIncedentTest, EqualityComparison) 
{
    auto matrix = createMatrix();
    auto edges = createEdges();

    IteratorIncedent<int> it1(matrix, edges, 0, 0);
    IteratorIncedent<int> it2(matrix, edges, 0, 0);
    IteratorIncedent<int> it_end(matrix, edges, 0, edges.size());

    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);
    ++it1;
    EXPECT_TRUE(it1 != it_end);
    ++it1;
    EXPECT_TRUE(it1 == it_end);
}

TEST(IteratorIncedentTest, EmptyGraph) 
{
    vector<vector<int>> empty_matrix;
    vector<pair<int, int>> empty_edges;

    IteratorIncedent<int> it(empty_matrix, empty_edges, 0, 0);
    IteratorIncedent<int> end(empty_matrix, empty_edges, 0, 0);

    EXPECT_TRUE(it == end);
}

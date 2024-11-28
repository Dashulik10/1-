#include "gtest/gtest.h"
#include "OrientedGraph.h"
#include "OrientedGraph.cpp"
#include "IteratorVertex.h"
#include "IteratorEdge.h"
#include "IteratorAdjacency.h"
#include "IteratorIncedent.h"

TEST(OrientedGraphTest, AddEdge) 
{
    OrientedGraph<string> graph;

    auto v1 = graph.AddVertex("A");
    auto v2 = graph.AddVertex("B");

    auto e1 = graph.AddEdge(v1, v2);  
    auto e2 = graph.AddEdge(v2, v1); 

    EXPECT_EQ(graph.EdgeCount(), 2);
    EXPECT_TRUE(graph.HasEdge(v1, v2));
    EXPECT_TRUE(graph.HasEdge(v2, v1));
}

TEST(OrientedGraphTest, Iterators) 
{
    OrientedGraph<string> graph;

    auto v1 = graph.AddVertex("A");
    auto v2 = graph.AddVertex("B");
    auto v3 = graph.AddVertex("C");

    auto e1 = graph.AddEdge(v1, v2);
    auto e2 = graph.AddEdge(v2, v3);
    auto e3 = graph.AddEdge(v1, v1);

    vector<string> vertexes;
    for (auto it = graph.begin(); it != graph.end(); ++it) 
    {
        vertexes.push_back(*it);
    }

    EXPECT_EQ(vertexes.size(), 3);
    EXPECT_EQ(vertexes[0], "A");
    EXPECT_EQ(vertexes[1], "B");
    EXPECT_EQ(vertexes[2], "C");

    vector<pair<int, int>> edges;
    for (auto it = graph.begin_edges(); it != graph.end_edges(); ++it) 
    {
        edges.push_back(*it);
    }

    EXPECT_EQ(edges.size(), 3);
    EXPECT_EQ(edges[0], make_pair(v1, v2));
    EXPECT_EQ(edges[1], make_pair(v2, v3));
    EXPECT_EQ(edges[2], make_pair(v1, v1));

    vector<int> neighbors;
    for (auto it = graph.adjacency_begin(v1); it != graph.adjacency_end(v1); ++it) 
    {
        neighbors.push_back(*it);
    }

    EXPECT_EQ(neighbors.size(), 2); 
    EXPECT_EQ(neighbors[0], v2);
    EXPECT_EQ(neighbors[1], v1);

    vector<pair<int, int>> incedent_edges;
    for (auto it = graph.incedent_begin("A"); it != graph.incedent_end("A"); ++it) 
    {
        incedent_edges.push_back(*it);
    }

    EXPECT_EQ(incedent_edges.size(), 2); 
    EXPECT_EQ(incedent_edges[0], make_pair(v1, v2));
    EXPECT_EQ(incedent_edges[1], make_pair(v1, v1));
}

TEST(OrientedGraphTest, RemoveEdge) 
{
    OrientedGraph<string> graph;

    auto v1 = graph.AddVertex("A");
    auto v2 = graph.AddVertex("B");

    auto e1 = graph.AddEdge(v1, v2);

    EXPECT_EQ(graph.EdgeCount(), 1);
    graph.RemoveEdge(0);
    EXPECT_EQ(graph.EdgeCount(), 0);
    EXPECT_FALSE(graph.HasEdge(v1, v2)); 
}

TEST(OrientedGraphTest, VertexDegree) 
{
    OrientedGraph<string> graph;

    auto v1 = graph.AddVertex("A");
    auto v2 = graph.AddVertex("B");

    graph.AddEdge(v1, v2); 
    graph.AddEdge(v2, v1);  

    EXPECT_EQ(graph.VertexDegree(v1), 2); 
    EXPECT_EQ(graph.VertexDegree(v2), 2);  
}
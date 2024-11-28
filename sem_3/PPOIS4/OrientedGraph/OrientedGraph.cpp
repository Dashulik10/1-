#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include "OrientedGraph.h"
#include "IteratorVertex.h"
#include "IteratorEdge.h"
#include "IteratorAdjacency.h"
#include "IteratorIncedent.h"
using namespace std;

template <typename T>
typename OrientedGraph<T>::vertex_id OrientedGraph<T>::AddVertex(const Vertex& vertex)
{
    vertexes[vertex_i] = vertex;
    matrix.push_back(vector<int>(edges.size(), 0));
    return vertex_i++;
}

template <typename T>
typename OrientedGraph<T>::edge_id OrientedGraph<T>::AddEdge(vertex_id from, vertex_id to)
{
    edges.push_back({ from, to });
    for (auto& row : matrix)
    {row.push_back(0);}

    if (from == to)
    {matrix[from][edge_i] = 2;}
    else
    {
        matrix[from][edge_i] = 1;
        matrix[to][edge_i] = -1;
    }
    return edge_i++;
}

template <typename T>
void OrientedGraph<T>::RemoveEdge(edge_id id)
{
    if (id < 0 || id >= edges.size()) {throw invalid_argument("Edge ID does not exist.");}

    edges.erase(edges.begin() + id);
    
    for (auto& row : matrix)
    {row.erase(row.begin() + id);}
}

template <typename T> 
typename OrientedGraph<T>::vertex_id OrientedGraph<T>::FindVertex_id(const Vertex& vertexx)
{
    for (const auto& vertex : vertexes)
    {
        if (vertex.second == vertexx)
        {return vertex.first;}
    }
    throw invalid_argument("Vertex not found");
}

template <typename T>
void OrientedGraph<T>::RemoveVertex(const Vertex& vertexremove)
{
    vertex_id id = FindVertex_id(vertexremove);

    vector<pair<vertex_id, vertex_id>> newEdges;
    for (size_t i = 0; i < edges.size(); ++i)
    {
        if (edges[i].first != id && edges[i].second != id)
        {newEdges.push_back(edges[i]);}
    }

    edges = newEdges;

    matrix.erase(matrix.begin() + id);
    for (size_t i = 0; i < matrix.size(); ++i)
    {matrix[i].erase(matrix[i].begin() + id);}
    vertexes.erase(id);

    map<vertex_id, Vertex> updated_vertexes;
    vertex_id new_id = 0;
    for (typename map<vertex_id, Vertex>::iterator it = vertexes.begin(); it != vertexes.end(); ++it)
    {
        updated_vertexes[new_id] = it->second;
        ++new_id;
    }
    vertexes = updated_vertexes;

    for (size_t i = 0; i < edges.size(); ++i)
    {
        if (edges[i].first > id) --edges[i].first;
        if (edges[i].second > id) --edges[i].second;
    }
}

template <typename T>
void OrientedGraph<T>::PrintMatrix() const
{
    for (const auto& pair : vertexes)
    {
        int vertex_id = pair.first;
        const auto& vertex = pair.second;

        for (const auto& value : matrix[vertex_id])
        {cout << value << "   ";}
        cout << endl;
    }
}

template <typename T>
bool OrientedGraph<T>::HasVertex(vertex_id id) const
{return vertexes.count(id) > 0;}

template <typename T>
bool OrientedGraph<T>::HasEdge(vertex_id from, vertex_id to) const
{
    for (size_t j = 0; j < edges.size(); ++j)
    {
        if (edges[j] == make_pair(from, to)) {return true;}
    }
    return false;
}

template <typename T>
int OrientedGraph<T>::VertexCount() const
{return vertexes.size();}

template <typename T>
int OrientedGraph<T>::EdgeCount() const
{return edges.size();}

template <typename T>
int OrientedGraph<T>::VertexDegree(vertex_id id) const
{
    if (!vertexes.count(id)) { throw runtime_error("Vertex not found"); }

    int in_degree = 0;
    int out_degree = 0;

    for (size_t j = 0; j < matrix[id].size(); ++j) {
        if (matrix[id][j] == 1)
        {
            ++out_degree;
        }
        else if (matrix[id][j] == -1)
        {
            ++in_degree;
        }
        else if (matrix[id][j] == 2)
        {
            ++in_degree;
            ++out_degree;
        }
    }
    return in_degree + out_degree;
}

template <typename T>
int OrientedGraph<T>::EdgeDegree(edge_id id) const
{
    if (id < 0 || id >= edges.size()) { throw runtime_error("Edge not found"); }

    int degree = 0;
    for (const auto& row : matrix)
    {
        if (row[id] != 0)
        {
            ++degree;
        }
    }
    return degree;
}


template <typename T>
IteratorVertex<T> OrientedGraph<T>::begin() {return IteratorVertex<T>(vertexes.begin(), vertexes.end());}
template <typename T>
IteratorVertex<T> OrientedGraph<T>::end() {return IteratorVertex<T>(vertexes.end(), vertexes.end());}

template <typename T>
IteratorEdge<T> OrientedGraph<T>::begin_edges() {return IteratorEdge<T>(edges.begin(), edges.end());}
template <typename T>
IteratorEdge<T> OrientedGraph<T>::end_edges() {return IteratorEdge<T>(edges.end(), edges.end());}

template <typename T>
vector<typename OrientedGraph<T>::vertex_id> OrientedGraph<T>::GetNeighbors(vertex_id id) const
{
    if (!HasVertex(id)) {throw out_of_range("Vertex not found");}

    vector<vertex_id> neighbors;
    for (size_t edge_idx = 0; edge_idx < edges.size(); ++edge_idx)
    {
        if (matrix[id][edge_idx] == 1)
        {
            neighbors.push_back(edges[edge_idx].second);
        }
        else if (matrix[id][edge_idx] == -1)
        {
            neighbors.push_back(edges[edge_idx].first);
        }
        else if (matrix[id][edge_idx] == 2)
        {
            neighbors.push_back(id);
        }
    }
    return neighbors;
}


template <typename T>
IteratorAdjacency<T> OrientedGraph<T>::adjacency_begin(vertex_id id)
{return IteratorAdjacency<T>(GetNeighbors(id), 0);}

template <typename T>
IteratorAdjacency<T> OrientedGraph<T>::adjacency_end(vertex_id id)
{
    auto neighbors = GetNeighbors(id);
    return IteratorAdjacency<T>(neighbors, neighbors.size());
}

template <typename T>
IteratorIncedent<T> OrientedGraph<T>::incedent_begin(const Vertex& vertex) 
{
    vertex_id vertex_index = FindVertex_id(vertex);
    return IteratorIncedent<T>(matrix, edges, vertex_index, 0);
}

template <typename T>
IteratorIncedent<T> OrientedGraph<T>::incedent_end(const Vertex& vertex)
{
    vertex_id vertex_index = FindVertex_id(vertex);
    return IteratorIncedent<T>(matrix, edges, vertex_index, edges.size());
}

#ifndef ORIENTED_GRAPH_H
#define ORIENTED_GRAPH_H

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include "IteratorVertex.h"
#include "IteratorEdge.h"
#include "IteratorAdjacency.h"
#include "IteratorIncedent.h"
using namespace std;

template <typename T>
class OrientedGraph
{
public:
	typedef int vertex_id;
	typedef int edge_id;
	typedef T Vertex;

	vertex_id AddVertex(const Vertex& vertex);
	bool HasEdge(vertex_id from, vertex_id to) const;
	bool HasVertex(vertex_id id) const;
	edge_id AddEdge(vertex_id from, vertex_id to);
	void RemoveEdge(edge_id id);
	void RemoveVertex(const Vertex& vertexremove);
	int VertexCount() const;
	int VertexDegree(vertex_id id) const;
	int EdgeCount() const;
	int EdgeDegree(edge_id id) const;
	void PrintMatrix() const;
	vertex_id FindVertex_id(const Vertex& vertex);
	IteratorVertex<T> begin();
	IteratorVertex<T> end();
	IteratorEdge<T> begin_edges();
	IteratorEdge<T> end_edges();
	IteratorAdjacency<T> adjacency_begin(vertex_id id);
	IteratorAdjacency<T> adjacency_end(vertex_id id);
	IteratorIncedent<T> incedent_begin(const Vertex& vertex);
	IteratorIncedent<T> incedent_end(const Vertex& vertex);

private:
	map <vertex_id, Vertex> vertexes;
	vector <pair<vertex_id, vertex_id>> edges;
	vector <vector<int>> matrix;
	vertex_id vertex_i = 0;
	edge_id edge_i = 0;

	vector<vertex_id> GetNeighbors(vertex_id id) const;
};

#endif
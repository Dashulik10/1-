#ifndef ITERATOR_INCEDENT_H
#define ITERATOR_INCEDENT_H

#include <vector>
#include <utility>
using namespace std;
template <typename T>
class IteratorIncedent 
{
private:
	const vector <vector<int>> matrix;
	const vector <pair<int, int>> edges;
	int vertex_id;
	size_t cur_edge_id;

public:
	IteratorIncedent(const vector <vector<int>> mat, vector<pair<int, int>> edg, int ver_id, size_t cur_id_edg) :
		matrix(mat), edges(edg), vertex_id (ver_id), cur_edge_id(cur_id_edg) {}

	IteratorIncedent& operator ++ ()
	{
		do { ++cur_edge_id; } while (cur_edge_id < edges.size() && matrix[vertex_id][cur_edge_id] == 0);
		return *this;
	}

	bool operator==(const IteratorIncedent& other)
	{
		return cur_edge_id == other.cur_edge_id;
	}

	bool operator!=(const IteratorIncedent& other)
	{
		return cur_edge_id != other.cur_edge_id;
	}
	pair <int, int> operator *() 
	{
		return edges[cur_edge_id];
	}
};

#endif
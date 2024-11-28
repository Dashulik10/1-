#ifndef ITERATOR_ADJACENCY_H
#define ITERATOR_ADJACENCY_H

#include <vector>
using namespace std;

template <typename T>
class IteratorAdjacency
{
public:
    using vertex_id = int;
    IteratorAdjacency(const vector<vertex_id>& neighbors, size_t position)
        : neighbors(neighbors), position(position) {}

    IteratorAdjacency& operator++()
    {
        if (position < neighbors.size())
        {++position;}

        return *this;
    }

    IteratorAdjacency& operator--()
    {
        if (position > 0)
        {--position;}
        
        return *this;
    }

    vertex_id operator*() const
    {
        if (position >= neighbors.size()) 
        {throw out_of_range("Iterator out of range");}

        return neighbors[position];
    }

    bool operator==(const IteratorAdjacency& other) const
    {return position == other.position && neighbors == other.neighbors;}

    bool operator!=(const IteratorAdjacency& other) const
    {return !(*this == other);}

private:
    vector<vertex_id> neighbors;
    size_t position;
};

#endif


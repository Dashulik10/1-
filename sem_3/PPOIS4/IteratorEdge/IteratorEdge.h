#ifndef EDGE_ITERATOR_H
#define EDGE_ITERATOR_H

#include <vector>
#include <utility>
#include <map>
#include <stdexcept>
#include <iostream>
#include <set>
using namespace std;


template <typename T>
class IteratorEdge
{
public:
    using Edge = pair<typename vector<pair<int, int>>::iterator, typename vector<pair<int, int>>::iterator>;
    
    IteratorEdge(typename vector<pair<int, int>>::iterator start, typename vector<pair<int, int>>::iterator end)
        : current_iterator(start), after_end(end) {}

    IteratorEdge& operator++()
    {
        if (current_iterator != after_end)
        {++current_iterator;}
        return *this;
    }

    IteratorEdge& operator--()
    {
        if (current_iterator != after_end)
        {--current_iterator;}
        return *this;
    }

    pair<int, int> operator*() const 
    {return *current_iterator;}

    bool operator==(const IteratorEdge& other) const 
    {return current_iterator == other.current_iterator;}

    bool operator!=(const IteratorEdge& other) const 
    {return current_iterator != other.current_iterator;}

private:
    typename vector<pair<int, int>>::iterator current_iterator;
    typename vector<pair<int, int>>::iterator after_end;
};

#endif

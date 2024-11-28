#ifndef VERTEX_ITERATOR_H
#define VERTEX_ITERATOR_H

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <set>
using namespace std;

template <typename T>
class IteratorVertex 
{
public:
	using VerIterator = typename map<int, T>::iterator;
	
	IteratorVertex(VerIterator start_it, VerIterator end_it) : current_iterator(start_it), after_end(end_it) {}

	IteratorVertex& operator++() 
	{
		if (current_iterator != after_end) {++current_iterator;}
		return *this;
	}

	IteratorVertex& operator--() 
	{
		if (current_iterator != after_end) 
		{--current_iterator;}
		return *this;
	}

	bool operator==(const IteratorVertex& other) const
	{return current_iterator == other.current_iterator;}

	bool operator!=(const IteratorVertex& other) const
	{return current_iterator != other.current_iterator;}

	T operator*() const 
	{return current_iterator->second;}

private:
	VerIterator current_iterator;
	VerIterator after_end;
};

#endif
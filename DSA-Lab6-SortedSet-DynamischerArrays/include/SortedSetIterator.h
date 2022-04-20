#pragma once
#include "SortedSet.h"
#include <stack>

//DO NOT CHANGE THIS PART
class SortedSetIterator
{
	friend class SortedSet;
private:
	const SortedSet& multime;
	SortedSetIterator(const SortedSet& m);
	//TODO - Representation
	//SortedSetIterator.h
	Node *current_node;
	//Node **stack;
	std::stack<Node*> node_stack; 

public:
	void first();
	void next();
	TElem getCurrent();
	bool valid() const;
	void setCurrent(TElem new_val);
};


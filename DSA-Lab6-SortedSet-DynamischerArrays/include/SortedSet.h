#pragma once
//DO NOT INCLUDE SETITERATOR

//DO NOT CHANGE THIS PART
typedef int TElem;
typedef TElem TComp;
typedef bool(*Relation)(TComp, TComp);
#define NULL_TELEM -11111
class SortedSetIterator;

struct Node{
	TElem val;
	Node *left,*right;
	//Node *parent;
};



class SortedSet {
	friend class SortedSetIterator;
private:
	//TODO - Representation
	//SortedSet.h
	Node *head;
	Relation rel;
	int NrElems;
	Node* recursive_add(Node* node, TComp elem, Relation rel);
	Node* recursive_remove(Node* node, TComp elem, Relation rel);
	Node* min_val(Node* node);
	bool recursive_search_unsorted(Node *node,TComp elem) const;
	void recursive_dealloc(Node *node);
	

public:
	//constructor
	SortedSet(Relation r);

	//adds an element to the sorted set
	//if the element was added, the operation returns true, otherwise (if the element was already in the set) 
	//it returns false
	bool add(TComp e);

	
	//removes an element from the sorted set
	//if the element was removed, it returns true, otherwise false
	bool remove(TComp e);

	//checks if an element is in the sorted set
	bool search(TElem elem) const;

	bool search_unsorted_tree(TElem elem) const;
	//returns the number of elements from the sorted set
	int size() const;

	//checks if the sorted set is empty
	bool isEmpty() const;

	//returns an iterator for the sorted set
	SortedSetIterator iterator() const;

	// destructor
	~SortedSet();


};

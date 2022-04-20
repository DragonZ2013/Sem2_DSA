#pragma once
#include<vector>
#include<utility>
//DO NOT INCLUDE MultiMapIterator

using namespace std;

//DO NOT CHANGE THIS PART
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<int,int>(-111111, -111111)
class MultiMapIterator;

struct Node
{
	TElem elem;
	Node* next;
};

class MultiMap
{
	friend class MultiMapIterator;

private:
	//TODO - Representation
	//MultiMap.h
	int hash(TKey k)const;
	int cap;
	int nrElems;
	Node** Elements;
	bool isPrime(int x);
	int firstPrime(int x_cap);
	void rehash(Node** old_arr,int old_nrElems);	

public:
	//constructor
	MultiMap();

	//adds a key value pair to the multimap
	void add(TKey c, TValue v);

	//removes a key value pair from the multimap
	//returns true if the pair was removed (if it was in the multimap) and false otherwise
	bool remove(TKey c, TValue v);

	//returns the vector of values associated to a key. If the key is not in the MultiMap, the vector is empty
	vector<TValue> search(TKey c) const;

	//returns the number of pairs from the multimap
	int size() const;

	//checks whether the multimap is empty
	bool isEmpty() const;

	//returns an iterator for the multimap
	MultiMapIterator iterator() const;

	int count_key(TKey c) const;
	//descturctor
	~MultiMap();


};


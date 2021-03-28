#include <exception>
#include "BagIterator.h"
#include "Bag.h"
#include <iostream>

using namespace std;


BagIterator::BagIterator(const Bag& c): bag(c)
{
	//DONE - Implementation
	//if (c.size() == 0)
	//	throw exception();
	//O(1)
	index = 0;
}

void BagIterator::first() {
	//DONE - Implementation
	//O(1)
	if (bag.size() == 0)
		throw exception();
	index = 0;
}


void BagIterator::next() {
	//DONE - Implementation
	//O(1)
	if (valid() == false)
		throw exception();
	index++;
}


bool BagIterator::valid() const {
	//DONE - Implementation
	//O(1)
	if (index < bag.size() && index >= 0)
		return true;
	return false;
}



TElem BagIterator::getCurrent() const
{
	//DONE - Implementation
	if(valid()==false)
		throw exception();
	int cont=0;
	for(int i=0;i<bag.current_elems;i++)
	{
		if(cont<=index&&cont+bag.elems[i].count>index)
			return bag.elems[i].elem_id;
		cont+=bag.elems[i].count;
		
	}
	return NULL_TELEM 
}

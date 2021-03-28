#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
//using namespace std;


Bag::Bag() {
	//DONE - Implementation
	max_elems = 5;
	current_elems = 0;
	elems = new pair_struct[max_elems];
}


void Bag::add(TElem elem) {
	//TODO - Implementation
	//O(n), Omega(n)
	int ok=0;
	for (int i = 0; i < current_elems; i++)
		if(elems[i].elem_id==elem)
		{
			ok=1;
			elems[i].count++;
		}
	if(ok==0)
		{if(current_elems>=max_elems)
			{max_elems=2*max_elems;
			pair_struct* newelems = new pair_struct[max_elems];
			for (int i = 0; i < current_elems; i++)
					newelems[i] = elems[i];
			delete[] &elems;
			elems=newelems;
			}
		elems[current_elems++]=pair_struct{elem,1};
		}
}


bool Bag::remove(TElem elem) {
	//TODO - Implementation
	//O(n)
	for (int i = 0; i < current_elems; i++)
		if(elems[i].elem_id==elem&&elems[i].count>0)//?
			{elems[i].count--;
			return true;}
	return false; 
}


bool Bag::search(TElem elem) const {
	//DONE - Implementation
	//O(n)
	for (int i = 0; i < current_elems; i++)
		if(elems[i].elem_id==elem&&elems[i].count!=0)
			return true;
	return false; 
}

int Bag::nrOccurrences(TElem elem) const {
	//DONE - Implementation
	//O(n)
	for (int i = 0; i < current_elems; i++)
		if(elems[i].elem_id==elem)
			return elems[i].count;
	return 0; 
}


int Bag::size() const {
	//DONE - Implementation
	//O(n)
	int size_el=0;
	for (int i = 0; i < current_elems; i++)
		size_el+=elems[i].count;
	return size_el;
	//return current_elems;
	//return 0;
}


bool Bag::isEmpty() const {
	//DONE - Implementation
	//O(n)
	if(size()==0)
		return true;
	return false;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

void Bag::diff_bag(Bag other){
	//O(n^2)
	BagIterator bi = other.iterator();
	while(bi.valid())
	{
		//std::cout<<bi.getCurrent();
		remove(bi.getCurrent());
		bi.next();
	}
}

Bag::~Bag() {//destructor
	//DONE - Implementation
	delete[] &elems;
}


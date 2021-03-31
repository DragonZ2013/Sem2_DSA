#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	//TODO - Implementation
	//O(1)
	start_it=map.start;
}

void SMIterator::first(){
	//TODO - Implementation
	//O(1)
	start_it=map.start;
}

void SMIterator::next(){
	//TODO - Implementation
	//O(1)
	if(!valid())
		throw exception();
	start_it=start_it->next;
}

bool SMIterator::valid() const{
	//TODO - Implementation
	//O(1)
	if(start_it!=nullptr)
		return true;
	return false;
}

TElem SMIterator::getCurrent() const{
	//TODO - Implementation
	//O(1)
	if(!valid())
		throw exception();
	TElem ret;
	ret.first=start_it->data.first;
	ret.second=start_it->data.second;
	return ret;

	//return NULL_TPAIR;
}



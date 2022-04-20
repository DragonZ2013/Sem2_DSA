#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	Node** temp=col.Elements;
	pos=0;
	while(temp[pos]==nullptr&&pos<col.cap)
		pos++;
	currentNode=temp[pos];
	//TODO - Implementation
}

TElem MultiMapIterator::getCurrent() const{
	//TODO - Implementation
	if(!valid())
		throw exception();
	if(valid())
		return currentNode->elem;
	return NULL_TELEM;
}

bool MultiMapIterator::valid() const {
	//TODO - Implementation
	if(currentNode==nullptr)
		return false;
	if(pos>=col.cap)
		return false;
	return true;
}

void MultiMapIterator::next() {
	//TODO - Implementation
	if(!valid())
		throw exception();
	if(currentNode->next!=nullptr)
	{
		currentNode=currentNode->next;
	}
	else
	{
		pos=pos+1;
		Node** temp=col.Elements;
		while(temp[pos]==nullptr&&pos<col.cap)
			pos++;
		currentNode=temp[pos];
	}
}

void MultiMapIterator::first() {
	//TODO - Implementation
	Node** temp=col.Elements;
	pos=0;
	while(temp[pos]==nullptr&&pos<col.cap)
		pos++;
	currentNode=temp[pos];
}


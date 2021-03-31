#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>
using namespace std;

SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
	//O(1)
	rel=r;
	start=nullptr;
}

TValue SortedMap::add(TKey k, TValue v) {
	//TODO - Implementation
	//O(n)
	if(start==nullptr)//no elems
	{
		start = new node;
		start->next=nullptr;
		start->data.first=k;
		start->data.second=v;
		return NULL_TVALUE;
	}
	node *cpos = start;
	while(cpos!=nullptr)//existing elems
		{if(cpos->data.first==k)
			{
				TValue temp=cpos->data.second;
				cpos->data.second=v;
				return temp;
			}
			cpos=cpos->next;
		}
	if(!rel(start->data.first,k))
	{
		node *temp=new node;
		temp->next=start;
		temp->data.first=k;
		temp->data.second=v;
		start=temp;
	}
	else{
		cpos=start;
		while(cpos->next!=nullptr&&rel(cpos->next->data.first,k))
		{
			cpos=cpos->next;
		}
		node *temp=new node;
		temp->next=cpos->next;
		temp->data.first=k;
		temp->data.second=v;
		cpos->next=temp;
	}
	return NULL_TVALUE;
}

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation
	//O(n)
	if(start==nullptr)
		return NULL_TVALUE;
	node *cpos = start;
	while(cpos!=nullptr)
		{
			if(cpos->data.first==k)
				return cpos->data.second;
			cpos=cpos->next;
		}
	return NULL_TVALUE;
}

TValue SortedMap::remove(TKey k) {
	//TODO - Implementation
	//O(n)
	if(start==nullptr)
		return NULL_TVALUE;
	if(start->data.first==k)
	{
		TValue ret = start->data.second;
		node *temp = start;
		start = start -> next;
		delete temp;
		return ret;
	}
	node *cpos = start;
	while(cpos->next!=nullptr)
		{
			if(cpos->next->data.first==k)
			{
				TValue ret=cpos->next->data.second;
				node *temp = cpos->next;
				cpos->next=cpos->next->next;
				delete temp;
				return ret;}
			cpos=cpos->next;
		}
	return NULL_TVALUE;
}

int SortedMap::size() const {
	//TODO - Implementation
	//O(n)
	if(start==nullptr)
		return 0;
	node *cpos = start;
	int cont=0;
	while(cpos!=nullptr)
		{
			cpos=cpos->next;
			cont++;
		}
	return cont;
}

bool SortedMap::isEmpty() const {
	//TODO - Implementation
	//O(n)
	if(size()==0)
		return true;
	return false;
}

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	//TODO - Implementation
	//O(n)
	node *cpos = start;
	while(cpos!=nullptr)
	{
		node *temp = cpos->next;
		delete cpos;
		cpos=temp;
	}
}

void SortedMap::Key_Mult(TKey* ret) const{
	//O(n)
	SMIterator it = this->iterator();
	//it.first();
	//TKey ret[size()];
	//TKey *ret;
	int i=0;
	while(it.valid())
	{
		ret[i++]=it.getCurrent().first;
		it.next();
	}
	//return ret;
}
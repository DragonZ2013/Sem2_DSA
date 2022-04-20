#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;

bool MultiMap::isPrime(int x)
{//O(n)
	if(x==0||x==1)
		return false;
	if(x==2)
		return true;
	if(x%2==0)
		return false;
	for(int i=3;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int MultiMap::firstPrime(int x_cap)
{//O(n)
	int ret_prime=x_cap+1;
	while(!isPrime(ret_prime))
	{
		ret_prime++;
	}
	return ret_prime;
}

int MultiMap::hash(TKey k) const
{//O(1)
	return std::abs(k)%cap;
}

void MultiMap::rehash(Node** old_arr,int old_nrElems)
{//O(n)
	int count=0;
	int i=0;
	while(count<old_nrElems)
	{
		if(old_arr[i]==nullptr)
			i++;
		else
		{
			Node* nodeCurrent=old_arr[i];
			while(nodeCurrent!=nullptr)
			{
				add(nodeCurrent->elem.first,nodeCurrent->elem.second);
				nodeCurrent=nodeCurrent->next;
				count++;
			}
			i++;
		}
	}
}

MultiMap::MultiMap() {
	//TODO - Implementation
	nrElems = 0;
	cap = 2;
	Elements = new Node* [cap];
	for(int i=0;i<cap;i++)
		Elements[i]=nullptr;
}


void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	//O(n)
	int pos=hash(c);
	if((float)nrElems/cap>1.5)
	{
		//int old_cap=cap;
		int old_nrElems=nrElems;
		Node** old_arr=Elements;
		cap=firstPrime(cap*2);
		nrElems=0;
		Elements = new Node* [cap];
		for(int i=0;i<cap;i++)
			Elements[i]=nullptr;
		rehash(old_arr,old_nrElems);
		delete old_arr;
	}
	if(Elements[pos]==nullptr)
	{
		Elements[pos] = new Node;
		Elements[pos]->elem.first=c;
		Elements[pos]->elem.second=v;
		Elements[pos]->next = nullptr;
	}
	else
	{
		Node *temp = new Node;
		temp->next = Elements[pos];
		temp->elem.first = c;
		temp->elem.second = v;
		Elements[pos]=temp;
	}
	nrElems++;
}


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	//O(n)
	int pos = hash(c);
	Node *currentNode= Elements[pos];
	if(currentNode==nullptr)
		return false;
	if(currentNode->elem.first==c&&currentNode->elem.second==v)
	{
		Elements[pos]=Elements[pos]->next;
		delete currentNode;
		nrElems--;
		return true;
	}
	else
	{
		Node *prev =currentNode;
		currentNode=currentNode->next;
		while(currentNode!=nullptr)
		{
			if(currentNode->elem.first==c&&currentNode->elem.second==v)
			{
				prev->next=currentNode->next;
				delete currentNode;
				nrElems--;
				return true;
			}
			prev=currentNode;
			currentNode=currentNode->next;
		}
	}
	return  false;
}


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	//O(n)
	int pos=hash(c);
	vector<TValue> ret;
	Node* currentNode = Elements[pos];
	while(currentNode!=nullptr)
	{
		if(currentNode->elem.first==c)
			ret.push_back(currentNode->elem.second);
		currentNode=currentNode->next;
	}
	return ret;
	//return vector<TValue>();
}


int MultiMap::size() const {
	//TODO - Implementation
	//O(1)
	return nrElems;
	//return 0;
}


bool MultiMap::isEmpty() const {
	//TODO - Implementation
	//O(1)
	if(nrElems==0)
		return true;
	return false;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

int MultiMap::count_key(TKey c) const
{//O(n)
	int ret=0;
	int pos=hash(c);
	Node* currentNode = Elements[pos];
	while(currentNode!=nullptr)
	{
		if(currentNode->elem.first==c)
			ret++;
		currentNode=currentNode->next;
	}
	return ret;

}

MultiMap::~MultiMap() {
	for(int i=0;i<cap;i++)
	{
		Node* head = Elements[i];
		while(head)
			{
			Node* tmp = head;
			head = head->next; 
			delete tmp;
			}
	}
	delete Elements;
	//TODO - Implementation
}


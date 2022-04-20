#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
	//TODO - Implementation
	//Theta(1)
	head = nullptr;
	NrElems=0;
	rel=r;
}

Node* SortedSet::recursive_add(Node* node, TComp elem, Relation rel)
{//O(log(n)) - O(n) for inbalanced bin tree
	if (node == nullptr)
	{
		node = new Node;
		node->val = elem;
		node->right = nullptr;
		node->left = nullptr;
	}
	else if (rel(node->val, elem))
	{
		node->right = recursive_add(node->right, elem, rel);
	}
	else
	{
		node->left = recursive_add(node->left, elem, rel);
	}
	return node;
}

bool SortedSet::add(TComp elem) {
	//TODO - Implementation
	//O(log(n))
	if (search(elem))
		return false;
	this->head = recursive_add(this->head, elem, this->rel);
	this->NrElems++;

	return true;
}

Node* SortedSet::min_val(Node* node)
{//O(log(n)) - O(n) for inbalanced bin tree
	if (node == nullptr)
	{
		return nullptr;
	}	
	else
	{
		Node* retNode = node;
		while (retNode->left != nullptr)
		{
			retNode = retNode->left;
		}
		return retNode;
	}
}

Node* SortedSet::recursive_remove(Node* node, TComp elem, Relation rel)
{//O(log(n))
	if (node == nullptr) 
		return nullptr;
	else if ( node->val == elem)
	{
		if (node->left == nullptr && node->right == nullptr)
		{
			delete node;
			return nullptr;
		}
		else if (node->left == nullptr)
			return node->right;
		
		else if (node->right == nullptr)
			return node->left;
		else
		{
			Node* min = min_val(node->right);//minimum of the values higher than the current node(could use maximum of the lower values/left)
			node->val = min->val;
			node->right = recursive_remove(node->right, min->val, rel);
			return node;
		}
	}
	else if (rel(node->val, elem))
	{
		node->right = recursive_remove(node->right, elem, rel);
		return node;
	}
	else if (!rel(node->val, elem))//should always be final else
	{
		node->left =  recursive_remove(node->left, elem, rel);
		return node;
	}
}

bool SortedSet::remove(TComp elem) {
	//TODO - Implementation
	//O(log(n))
	if (!search(elem))
		return false;
	
	this->head = recursive_remove(this->head,elem, this->rel);
	this->NrElems--;
	
	return true;
}


bool SortedSet::search(TComp elem) const {
	//TODO - Implementation
	//O(log(n)) - O(n) for inbalanced bin tree
	if (this->isEmpty())
		return false;
	Node* currentNode = head;
	while (currentNode != nullptr)
	{
		if (currentNode->val == elem)
			return true;

		else if (rel(currentNode->val, elem))
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left; 
	}
	return false;
}

bool SortedSet::recursive_search_unsorted(Node* node, TComp elem) const
{
	if(node==nullptr)
		return false;
	if(node->val==elem)
		return true;
	return(recursive_search_unsorted(node->left,elem)||recursive_search_unsorted(node->right,elem));
}

bool SortedSet::search_unsorted_tree(TComp elem) const {
	if(this->isEmpty())
		return false;
	return recursive_search_unsorted(head,elem);

}
int SortedSet::size() const {
	//TODO - Implementation
	//theta(1)
	return NrElems;
	return 0;
}



bool SortedSet::isEmpty() const {
	//TODO - Implementation
	//theta(1)
	if(NrElems==0)
		return true;
	return false;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}



void SortedSet::recursive_dealloc(Node* node)
{//O(n)

	if (node->left == nullptr&&node->right==nullptr)
	{
		delete node;
	}	
	else
	{
		if(node->left!=nullptr)
			recursive_dealloc(node->left);
		if(node->right!=nullptr)
			recursive_dealloc(node->right);
	}
}

SortedSet::~SortedSet() {
	//O(n)
	//TODO - Implementation
	if(head==nullptr)
		delete head;
	else
		recursive_dealloc(head);
}



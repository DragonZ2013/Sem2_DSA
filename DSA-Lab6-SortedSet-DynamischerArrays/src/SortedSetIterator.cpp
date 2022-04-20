#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	//TODO - Implementation
	//O(n/2) == O(n) (pushing half the tree(assumingly balanced) in stack)
	current_node=multime.head;
	while (current_node != nullptr)
	{
		this->node_stack.push(current_node);
		current_node = current_node->left;
	}
	if (this->node_stack.empty())
		this->current_node = nullptr;

	else 
		this->current_node = this->node_stack.top();
	
}


void SortedSetIterator::first() {
	//TODO - Implementation
	//O(n/2) == O(n) (Same as constructor) 
	current_node=multime.head;
	std::stack<Node*> empty_stack;
	node_stack = empty_stack;
	while (current_node != nullptr)
	{
		this->node_stack.push(current_node);
		current_node = current_node->left;
	}
	if (this->node_stack.empty())
		this->current_node = nullptr;

	else 
		this->current_node = this->node_stack.top();
}


void SortedSetIterator::next() {
	//TODO - Implementation
	//O(1) while elements in stack, O(n/2) (== O(n)) otherwise
	if (!this->valid())
		throw exception();
	Node* node = node_stack.top();	
	this->node_stack.pop();
	if (node->right != nullptr)
	{	
		node = node->right;

		//then pushes the whole left subtree of the right child onto the stack if possible
		while(node != nullptr)
		{
			this->node_stack.push(node);
			node = node->left;
		}
	}
	if (this->node_stack.empty())
		this->current_node = nullptr;

	else
		this->current_node = this->node_stack.top();
}


TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
	//Theta(1)
	if (!valid())
	throw exception();
else
	return current_node->val;
}

bool SortedSetIterator::valid() const {
	//TODO - Implementation
	//Theta(1)
	if (this->current_node == nullptr || this->node_stack.empty())
		return false;
	return true;
}

void SortedSetIterator::setCurrent(TElem new_val){
	//O(n)
	if(multime.search_unsorted_tree(new_val)==true)
		throw exception();
	if(!valid())
		throw exception();
	current_node->val=new_val;
}


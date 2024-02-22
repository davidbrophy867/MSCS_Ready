#include "LinkedHashNode.h"

/*
 * ETK - April 2023
 * LinkedHashNode class
 * provides a node suitable for the linked list
 * in a hash table with chaining
 * Nodes contain a pointer to a Stock and a pointer
 * to the next entry in the list.
 */


// constructors 
LinkedHashNode::LinkedHashNode(Stock *s): stock(s), next(nullptr){};

LinkedHashNode::LinkedHashNode(string n, string t, int q, double p):
	stock(new Stock(n,t, q, p)), next(nullptr){};

// destructor 
LinkedHashNode::~LinkedHashNode(){
	delete stock;
};

// mutators
void LinkedHashNode::setStock(Stock *s){
	this->stock = s;
};

void LinkedHashNode::setNext(LinkedHashNode *n){
	this->next = n;
};


// accessors
string LinkedHashNode::getKey(){
	if (stock != nullptr)
		return stock->getKey();
	else
		return nullptr;
};

Stock * LinkedHashNode::getStock(){
	return stock;
};	

LinkedHashNode * LinkedHashNode::getNext(){
	return next;
};


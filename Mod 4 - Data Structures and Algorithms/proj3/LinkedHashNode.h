#ifndef LINKED_HASH_NODE 
#define LINKED_HASH_NODE
#include <string>
#include "Stock.h"

/*
 * ETK - April 2023
 * LinkedHashNode class
 * provides a node suitable for the linked list
 * in a hash table with chaining
 * Nodes contain a pointer to a Stock and a pointer
 * to the next entry in the list.
 */


using namespace std;

class LinkedHashNode{

public:
	// constructors 
	LinkedHashNode(Stock *s);
	LinkedHashNode(string name, string ticker, int quantity, double price);

	// destructor
	~LinkedHashNode();

	// mutators
	void setStock(Stock *s);
	void setNext(LinkedHashNode *next);

	// accessors 	
	string getKey();
	Stock * getStock();	
	LinkedHashNode * getNext();
	
private:
	Stock * stock;
	LinkedHashNode *next;
};

#endif

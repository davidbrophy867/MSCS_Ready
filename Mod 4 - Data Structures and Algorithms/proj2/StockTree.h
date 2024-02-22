#ifndef STOCKTREE_H
#define STOCKTREE_H
#include <iostream>
#include <string>
#include "StockTreeNode.h"

using namespace std;


class StockTree{
//a binary search tree of nodes that container Stock pointers

public:
	// constructor
	StockTree();

	// destructor -- delete all the nodes in the tree
	~StockTree();

	// mutators
	void insert(Stock * val); // -------------------------------------------------- DONE

	void remove(Stock * val); //--------------------------------------------------- DONE
	bool remove(const string key); //---------------------------------------------- DONE

	// boolean methods
	bool contains(const string key) const; //-------------------------------------- DONE
	bool contains(Stock * val) const; //------------------------------------------- DONE

	// returns a pointer to the node containing the desired key value
	// or the point at which it would be found if there
	StockTreeNode*  find(const string key) const; //------------------------------- DONE

	// display methods
	void display() const; //------------------------------------------------------- DONE
	void printLevelOrder();
	void displayItemsInOrder() const; //------------------------------------------- DONE

private:
	StockTreeNode * root;

	//utility methods
  bool insertNode(StockTreeNode * newNode);	//----------------------------------- DONE

	void inOrder(StockTreeNode *v) const; //--------------------------------------- DONE
	void deleteTree(StockTreeNode *curr);
	int height(StockTreeNode* node);
	Stock *newNode(Stock *);
	void printLevelOrder(StockTreeNode *root);
	void printGivenLevel(StockTreeNode *root);
	void display(StockTreeNode *ptr, int level) const; //-------------------------- DONE

};


#endif

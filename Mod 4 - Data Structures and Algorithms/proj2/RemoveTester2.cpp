#include <iostream>
#include "StockTreeNode.h"
#include "StockTree.h"

/*
 * RemoveTester2.cpp
 * EK, March 2023
 * test cases:
 * 	4 - remove root from tree with one node, by stock pointer
 * 	5 - remove root with one child node (a leaf)
 *    6 - remove root with two child nodes (swap with a leaf node)
 */


int main(){
	// create an empty tree
	StockTree *myStockTree = new StockTree();

	// dynamically create some example stock objects to add later
	Stock *a = new Stock("AbbVie", "ABBV", 16.35, 1000);
	Stock *b = new Stock("Abbott Laboratories", "ABB", 35.17, 200);
	Stock *c = new Stock("Accenture", "ACN", 309.15, 1000);
	Stock *d = new Stock("3M Corp.", "MMM", 198.27, 1000);
	Stock *e = new Stock("AES Corp", "AES", 25.73, 1000);
	Stock *f = new Stock("Alliant Energy", "LNT", 56.67, 1000);
	Stock *g = new Stock("Plug Power Inc", "PLUG", 26.30, 1000);
	Stock *h = new Stock("Alphabet(Class A)", "GOOGL", 2510.37, 200);


	// case4a: build a tree with one node and display
	cout << "4: sample tree with one node: " << endl;
	myStockTree->insert(e);
	myStockTree->display();
	cout << endl;

	//test removing the root by pointer to stock object
	cout << "and then test removing the root, by pointer to Stock object: (AES): " 		<< endl << endl;
	myStockTree->remove(e);
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


	// case 5a: build a tree in which root has only one (left) child
	cout << "case 5a: sample tree in which root has one (left) child: " << endl;
	myStockTree->insert(e);
	myStockTree->insert(a);
	myStockTree->display();
	cout << endl;
	cout << "and then test removing the root, in one-child (left) case (AES): "
		 << endl  << endl;

	myStockTree->remove("AES");
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// case 5b: build a tree in which root has only one (right) child
	cout << "case 5b: sample tree in which root has one (right) child: " << endl;
	myStockTree->insert(e);
	myStockTree->display();
	cout << endl;
	cout << "and then test removing the root, in one-child (right) case (ABBV): "
		<< endl << endl;
	myStockTree->remove("ABBV");
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


	// case 5c: build a tree in which root has only one (left) child
	cout << "case 5c: sample tree in which root has one left child, not a leaf: " << endl;
	myStockTree->insert(a);
	myStockTree->insert(b);
	myStockTree->display();
	cout << endl;

	cout << "and then test removing the root, in one-child (left) case (AES):"
	<< endl << endl;
	myStockTree->remove("AES");
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// case 5d: build a tree in which root has only one (right) child
	cout << "case 5d: sample tree in which root has one right child, not a leaf "
		<< endl << endl;
	myStockTree->remove("ABBV");
	myStockTree->remove("ABB");
	myStockTree->insert(e);
	myStockTree->insert(d);
	myStockTree->insert(g);
	myStockTree->display();
	cout << endl;

	cout << "and then test removing the root, in one-child (right) case (AES): "
		<< endl << endl;
	myStockTree->remove("AES");
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	//case 6: build a tree in which root has 2 children, multiple nodes
	cout << "case 6: build a tree in which root has 2 children, multiple nodes " << endl;
	myStockTree->remove("MMM");
	myStockTree->remove("PLUG");
	myStockTree->insert(e);
	myStockTree->insert(a);
	myStockTree->insert(d);
	myStockTree->insert(b);
	myStockTree->insert(c);
	myStockTree->insert(f);
	myStockTree->insert(g);
	myStockTree->insert(h);
	myStockTree->display();
	cout << endl;

	cout << "and then : test removing a root node with two children, by key value (AES): " << endl;
	cout << "Note: we replace root with rightmost child of the left subtree."
		<< endl << endl;
	myStockTree->remove("AES");
	myStockTree->display();
   cout << "---- End of RemoveTester 2 -----------------------" << endl  << endl;

	return 0;
}

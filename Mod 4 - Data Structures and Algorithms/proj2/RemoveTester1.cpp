#include <iostream>
#include "StockTreeNode.h"
#include "StockTree.h"

/*
 * RemoveTester1.cpp
 * EK, March 2023
 * test cases:
 * 	1 - remove from an empty tree
 * 	2a - try to remove element not in tree from one-node tree
 * 	2b - remove element in tree from one-node tree
 * 	3 - try to remove element not in tree from multi-node tree
 */

int main(){
	// dynamically create some example stock objects to add later
	Stock *a = new Stock("AbbVie", "ABBV", 16.35, 1000);
   Stock *b = new Stock("Abbott Laboratories", "ABB", 35.17, 200);
   Stock *c = new Stock("Accenture", "ACN", 309.15, 1000);
   Stock *d = new Stock("3M Corp.", "MMM", 198.27, 1000);
   Stock *e = new Stock("AES Corp", "AES", 25.73, 1000);
   Stock *f = new Stock("Alliant Energy", "LNT", 56.67, 1000);
   Stock *g = new Stock("Plug Power Inc", "PLUG", 26.30, 1000);
   Stock *h = new Stock("Alphabet(Class A)", "GOOGL", 2510.37, 200);

  // create an empty tree
	StockTree *myStockTree = new StockTree();

	// step 0: display the empty tree
	cout << "first, display the empty tree: " << endl << endl;
	myStockTree->display();
	cout << endl;
	cout << "then: " << endl  << endl;

	// test case 1: empty tree
	cout << "case 1: attempt to remove from an empty tree by key value(AES): " 
		<< endl << endl;
	myStockTree->remove("AES");
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test case 2: a tree with one element
	cout << "create a tree with one element (AES): " << endl;
	myStockTree->insert(e);
	myStockTree->display();
	cout << endl;
	cout << "then: " << endl  << endl;

	cout << "case 2a: attempt to remove an element not found in the tree (UBX): " 
		<< endl << endl;
	myStockTree->remove("UBX");
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	cout << "case 2b: remove an element found in a one-node tree (AES), by key value: " 
		<< endl << endl;
	myStockTree->remove("AES");
	myStockTree->display();
	cout << endl;
   cout << "---- End of RemoveTester 1 -----------------------" << endl  << endl;


	return 0;	
}


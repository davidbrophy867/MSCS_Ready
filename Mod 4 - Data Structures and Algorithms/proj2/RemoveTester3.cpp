#include <iostream>
#include "StockTreeNode.h"
#include "StockTree.h"

/*
 * RemoveTester3.cpp
 * EK, March 2020
 * test cases:
 *  7 - remove leaf node
 *  8 - remove internal node with two children
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


	// test inserting and displaying one element passing the pointer to the stock
	cout << "sample tree: " << endl;
	myStockTree->insert(e);
	myStockTree->insert(d);
	myStockTree->insert(a);
	myStockTree->insert(c);
	myStockTree->insert(g);
	myStockTree->insert(f);
	myStockTree->insert(b);
	myStockTree->insert(h);
	myStockTree->display();			
	cout << endl;


	//test removing another node with two children
	cout << "7a: and then test removing a leaf node (GOOGL): " 
		<< endl << endl;
	myStockTree->remove("GOOGL");
	myStockTree->display();			
	cout << endl;	
	cout << "----------------------------------------------------" << endl  << endl;

	cout << "7b: and then test removing another leaf node (ACN): " 
		<< endl << endl;
	myStockTree->remove("ACN");
	myStockTree->display();			
	cout << endl;	
	cout << "----------------------------------------------------" << endl  << endl;

	cout << "8:and then test removing an internal node with 2 children (MMM) " 
		<< endl << endl;
	myStockTree->remove("MMM");
	myStockTree->display();			
	cout << endl;	
   cout << "---- End of RemoveTester 3 -----------------------" << endl  << endl;



	return 0;	
}


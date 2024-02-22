#include <iostream>
#include "StockTreeNode.h"
#include "StockTree.h"

/*
 * RemoveTester4.cpp
 * EK, March 2020
 *  9 - remove internal node with one child
 *   a: remove node that is left child of parent and has a left child
 *   b: remove node that is left child of parent and has a right child
 *   c: remove node that is right child of parent and has a left child
 *   d: remove node that is right child of parent and has a right child
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


	cout << "sample tree a : " << endl;
	myStockTree->insert(e);
	myStockTree->insert(a);
	myStockTree->insert(b);
	myStockTree->insert(d);
	myStockTree->display();
	cout << endl;


	//test removing a node with one child
	cout << "9a: and then test removing a left child with a left child (ABBV):" << endl;
	myStockTree->remove("ABBV");
	myStockTree->display();			
	cout << endl;	
	cout << "----------------------------------------------------" << endl  << endl;

	cout << "sample tree b: " << endl;
	myStockTree->insert(c);
	myStockTree->display();
	cout << endl;

	cout << "9b:and then test removing a left child with a right child(ABB):  " << endl;
	myStockTree->remove("ABB");
	myStockTree->display();			
	cout << endl;	
	cout << "----------------------------------------------------" << endl  << endl;


	cout << "sample tree c: " << endl;
	myStockTree->insert(g);
	myStockTree->display();
	cout << endl;

	cout << "9c:and then test removing a right child with a right child(MMM):  " << endl;
	myStockTree->remove("MMM");
	myStockTree->display();			
	cout << endl;	
	cout << "----------------------------------------------------" << endl  << endl;


	cout << "sample tree d: " << endl;
	myStockTree->insert(f);
	myStockTree->insert(h);
	myStockTree->display();
	cout << endl;

	cout << "9d:and then test removing a right child with a left child(LNT):  " << endl;
	myStockTree->remove("LNT");
	myStockTree->display();			
	cout << endl;	
	cout << "---- End of RemoveTester 4 -----------------------" << endl  << endl;

	return 0;

}


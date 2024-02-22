#include <iostream>
#include "StockTreeNode.h"
#include "StockTree.h"

/*
 * StockTreeTester1.cpp
 * EK, March 2023
 * This tester program exercises the "displayInOrder()" method
 * as well as "insert", "contains" and "find" methods
 * see StockTreeTester2.cpp to exercise the display() method as well
 */

int main(){
	// create a list of nodes that contain a Stock
	// as the value portion of the node
	StockTree *myStockTree = new StockTree();
	// dynamically create some example stock objects
	Stock *a = new Stock("AbbVie", "ABBV", 16.35, 1000);
	Stock *b = new Stock("Abbott Laboratories", "ABB", 35.17, 200);
	Stock *c = new Stock("Accenture", "ACN", 309.15, 1000);
	Stock *d = new Stock("3M Corp.", "MMM", 198.27, 1000);
	Stock *e = new Stock("AES Corp", "AES", 25.73, 1000);
	Stock *f = new Stock("Alliant Energy", "LNT", 56.67, 1000);
	Stock *g = new Stock("Plug Power Inc", "PLUG", 26.30, 1000);
	Stock *h = new Stock("Alphabet(Class A)", "GOOGL", 2510.37, 200);
	StockTreeNode *foundPtr;

	// test displaying an empty tree:
	cout << "1. test displaying an empty tree: " << endl;
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test inserting the first element into the tree
	cout << "2.test inserting one element(AES)" << endl;
	myStockTree->insert(e);
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test displaying a tree with one element
	cout << "3.test displaying a tree with one element(AES):" << endl;
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test inserting and displaying an element before head, passing a pointer to the stock
	cout << "4. test inserting a right child(MMM) and a left child(ABBV): " << endl;
	myStockTree->insert(d);
	myStockTree->insert(a);
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// try a few more
	cout << "5. and then a right child of the left child(ACN):" << endl;
	myStockTree->insert(c);
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

   cout << "6. and then a right child of the right child(PLUG):" << endl;
	myStockTree->insert(g);
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

   cout << "7. and then a few more(LNT and ABB):" << endl;
	myStockTree->insert(f);
	myStockTree->insert(b);
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


   cout << "8. and finally,(GOOGL):" << endl;
	myStockTree->insert(h);
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	//test the contains method
	cout << "9. test the contains method: " << endl;
	if (myStockTree->contains("MMM"))
		cout << "MMM is in myStockTree" << endl;
	else
		cout << "MMM is NOT in myStockTree" << endl;

	if (myStockTree->contains("AMD"))
		cout << "AMD is in myStockTree" << endl;
	else
		cout << "AMD is NOT in myStockTree" << endl;
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


	// test inserting repeated elements
	// Do we allow repeat elements in a list?  Generally, yes.
   // But we'd like this to be a list implementation that has some set properties (no repeats).
	// How can you adapt your code to handle this?
	cout << "10. test inserting a repeat element: (MMM again) " << endl;
	myStockTree->insert(d);
	myStockTree->displayItemsInOrder();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test finding the node containing a given ticker symbol
	cout << "11. test finding the node containing a given ticker symble (MMM)" << endl;
	cout << "Note: 'find' would normally be a private method. " << endl;
	cout << "It is only public here so that we can test it from the tester program." << endl;
	foundPtr = myStockTree->find("MMM");
	if (foundPtr == nullptr){
		cout << "the tree was empty! " << endl;
	}
	else if (foundPtr->getStockPtr()->getKey() == "MMM"){
		cout << "found: " << foundPtr->getStockPtr()->getKey() << endl;
	}
	else{
		cout << "MMM not found, but it would be added here:"
			  << foundPtr->getStockPtr()->getKey() << endl;
	}
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test finding a node NOT in the list
	cout << "12. test finding the node containing a given ticker symble (UBX)" << endl;
	cout << "Note: 'find' would normally be a private method. " << endl;
	cout << "It is only public here so that we can test it from the tester program." << endl;
	foundPtr = myStockTree->find("UBX");
	if (foundPtr == nullptr){
		cout << "the tree was empty! " << endl;
	}
	else if (foundPtr->getStockPtr()->getKey() == "UBX"){
		cout << "found: " << foundPtr->getStockPtr()->getKey() << endl;
	}
	else{
		cout << "UBX not found, but it would be added here:"
			  << foundPtr->getStockPtr()->getKey() << endl;
	}
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	return 0;
}

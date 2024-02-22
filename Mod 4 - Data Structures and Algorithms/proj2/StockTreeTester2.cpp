#include <iostream>
#include "StockTreeNode.h"
#include "StockTree.h"

/*
 * StockTreeTester2.cpp
 * EK, March 2023
 * This tester program exercises the insert method as in StockTester1.cpp
 * but exercises the display() method, which provides a tree-shaped display of the BST
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
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


	// test inserting the first element into the tree
	cout << "2.test inserting one element(AES)" << endl;
	myStockTree->insert(e);
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test displaying a tree with one element
	cout << "3.test displaying a tree with one element(AES):" << endl;
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// test inserting and displaying an element before head, passing a pointer to the stock
	cout << "4. test inserting a right child(MMM) and a left child(ABBV): " << endl;
	myStockTree->insert(d);
	myStockTree->insert(a);
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

	// try a few more
	cout << "5. and then a right child of the left child(ACN):" << endl;
	myStockTree->insert(c);
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;

   cout << "6. and then a right child of the right child(PLUG):" << endl;
	myStockTree->insert(g);
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


   cout << "7. and then a few more(LNT and ABB):" << endl;
	myStockTree->insert(f);
	myStockTree->insert(b);
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


   cout << "8. and finally,(GOOGL):" << endl;
	myStockTree->insert(h);
	myStockTree->display();
	cout << endl;
	cout << "----------------------------------------------------" << endl  << endl;


	return 0;
}

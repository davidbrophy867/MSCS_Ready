#include <iostream>
#include "StockList.h"
#include "Stock.h"

int main(){
	// create a list of nodes that contain a Stock
	// as the value portion of the node
	StockList *myStockList = new StockList();

	// dynamically create some example stock objects
	Stock *a = new Stock("AbbVie", "ABBV", 1000, 116.35);
	Stock *b = new Stock("Abbott Laboratories", "ABB", 200, 35.17);
	Stock *c = new Stock("Accenture", "ACN", 1000, 309.15);
	Stock *d = new Stock("3M Corp.", "MMM", 1000, 198.27);
	Stock *e = new Stock("AES Corp", "AES", 1000, 25.73);
	Stock *f = new Stock("Alliant Energy", "LNT", 1000, 56.67);

	// test inserting and displaying one element passing the pointer to the stock
	cout << "test inserting one element: " << endl;
	myStockList->insert(a);
	myStockList->display();
	cout << endl;

	// test inserting and displaying an element before head, passing a pointer to the stock
	cout << "test inserting an element before head: " << endl;
	myStockList->insert(b);
	myStockList->display();
	cout << endl;

	// test inserting and displaying a new element at the end of the list
	cout << "test inserting a new element at the end of the list " << endl;
	myStockList->insert(c);
	myStockList->display();
	cout << endl;

	// try a few more
	cout << "try a few more " << endl;
	myStockList->insert(e);
	myStockList->insert(d);
	myStockList->display();
	cout << endl;

	//test the contains method
	cout << "test the contains method: " << endl;
	if (myStockList->contains("MMM"))
		cout << "MMM is in the myStockList" << endl;
	else
		cout << "MMM is NOT in the myStockList" << endl;


	if (myStockList->contains("AMD"))
		cout << "AMD is in the myStockList" << endl;
	else
		cout << "AMD is NOT in the myStockList" << endl;
	cout << endl;


	// test inserting repeated elements
	// Do we allow repeat elements?  Generally, yes.
   // But we'd like this to be a list implementation
   // that has some set properties (no repeats).
	// How can you adapt your code to handle this?
	cout << "test inserting a repeat element: (MMM again) " << endl;
	myStockList->insert(d);
	myStockList->display();
	cout << endl;

	// test finding the node containing a given ticker symbol
	StockNode * foundPtr = myStockList->find("MMM");
	if (foundPtr == nullptr){
		cout << "MMM not found" << endl;
	}
	else{
		cout << "found: " << foundPtr->getStock() << endl;
	}
	cout << endl;

	//test removing the first element
	cout << "test removing the first element, by pointer to Stock object: (ABB) " << endl;
	myStockList->remove(b);
	myStockList->display();
	cout << endl;


	//test removing the first element
	cout << "test removing the first element, by key value (ABBV ) : " << endl;
	myStockList->remove("ABBV");
	myStockList->display();
	cout << endl;

	//test removing the element at the tail of the list
	cout << "test removing the tail element, by pointer to Stock object (MMM)  " << endl;
	myStockList->remove(d);
	myStockList->display();
	cout << endl;

	//test removing the element at the tail of the list
	cout << "test removing the tail element, by ticker symbol (AES): " << endl;
	myStockList->remove(e);
	myStockList->display();
	cout << endl;

	// try removing an element not in the list
	// should do nothing
   // do you need to adapt your code to handle this?
	// how??
	cout << "test removing an element not in the list: (LNT) " << endl;
	myStockList->remove(f);
	myStockList->display();
	cout << endl;

	// test removing the last element to create an empty list
	cout << "test removing the last element (ACN) to create an empty list " << endl;
	myStockList->remove("ACN");
	myStockList->display();

	foundPtr = myStockList->find("T");
	if (foundPtr == nullptr){
		cout << "T not found" << endl;
	}
	else{
		cout << "found: " << foundPtr->getStock() << endl;
	}
	cout << endl;

	return 0;
}

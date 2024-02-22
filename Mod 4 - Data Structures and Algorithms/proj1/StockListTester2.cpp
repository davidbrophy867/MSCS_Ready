#include <iostream>
#include "StockList.h"
#include "Stock.h"

int main(){
	// create a list of nodes that contain a Stock
	// as the value portion of the node
	StockList *myStockList = new StockList();

	// test inserting and displaying one element passing the pointer to the stock
	cout << "test inserting one element: " << endl;
	// dynamically create and insert an anonymous stock object
	// a = ABBV
	myStockList->insert(new Stock("AbbVie", "ABBV", 1000, 116.35));
	myStockList->display();
	cout << endl;

	// test inserting and displaying an element before head,
	cout << "test inserting an element before head: " << endl;
	// b = ABB
	myStockList->insert(new Stock("Abbott Laboratories", "ABB", 200, 35.17));
	myStockList->display();
	cout << endl;


	Stock *f = new Stock("Alliant Energy", "LNT", 1000, 56.67);



	// test inserting and displaying a new element at the end of the list
	cout << "test inserting a new element at the end of the list " << endl;
	// c = ACN
	myStockList->insert(new Stock("Accenture", "ACN", 1000, 309.15));
	myStockList->display();
	cout << endl;

	// try a few more
	cout << "try a few more " << endl;
	// e = AEX
	myStockList->insert(new Stock("AES Corp", "AES", 1000, 25.73));
	// d = MMM
	myStockList->insert(new Stock("3M Corp.", "MMM", 1000, 198.27));
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
	// Note: this may cause a memory leak if not handled properly in insert
	myStockList->insert(new Stock("3M Corp.", "MMM", 1000, 198.27));
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
	cout << "test removing the first element, by key (ABB): " << endl;
	myStockList->remove("ABB");
	myStockList->display();
	cout << endl;


	//test removing the first element
	cout << "test removing the first element, by key value (ABBV) : " << endl;
	myStockList->remove("ABBV");
	myStockList->display();
	cout << endl;

	//test removing the element at the tail of the list
	cout << "test removing the tail element, by key value (MMM)  " << endl;
	myStockList->remove("MMM");
	myStockList->display();
	cout << endl;

	//test removing the element at the tail of the list
	cout << "test removing the tail element, by key value (AES): " << endl;
	myStockList->remove("AES");
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

#include <iostream>
#include "HashMap.h"
#include "Stock.h"

const int MAP_SIZE = 11;

int main(){
	// create a list of nodes that contain a Stock as the value portion of the node
	HashMap  *stockMap = new HashMap(MAP_SIZE);
	// dynamically create some example stock objects
	Stock *a = new Stock("AbbVie", "ABBV", 1000, 116.35);
	Stock *b = new Stock("Abbott Laboratories", "ABB", 200, 35.17);
	Stock *c = new Stock("Accenture", "ACN", 1000, 309.15);
	Stock *d = new Stock("3M Corp.", "MMM", 1000, 198.27);
	Stock *e = new Stock("AES Corp", "AES", 1000, 25.73);
	Stock *f = new Stock("Sony Group Corp", "SONY", 100, 85.60);
   Stock *g = new Stock("Tesla Inc ", "TSLA", 100, 1005.05);
   Stock *h = new Stock("Molson Coors Beverage Co", "TAP", 100, 53.77);
	Stock *i = new Stock("Align Technology", "ALGN",1000, 627.19);
	Stock *j = new Stock("Alaska Air Group", "ALK", 1000, 59.38);
	Stock *k = new Stock("Allstate Corp","ALL", 1000, 133.47);
	Stock *l = new Stock("Allegion","ALLE", 500, 138.27);


	// test inserting and displaying one element
	cout << "---------------------------------------" << endl << endl;
	cout << "case 1: insert one element (ABBV) " << endl;
	stockMap->insert(a);
	stockMap->display();
	cout << endl;

	// add additional elements
	cout << "---------------------------------------" << endl << endl;
	cout << "case 2: insert additional elements(ABB, ACN, MMM): " << endl;
	stockMap->insert(b);
	stockMap->insert(c);
	stockMap->insert(d);
	stockMap->display();
	cout << endl;

	cout << "---------------------------------------" << endl << endl;
	cout << "case 3: insert anonymous stock object (ALXN): " << endl;
	stockMap->insert("Alexion Pharmaceuticals","ALXN",1000,184.2);
	stockMap->display();
	cout << endl;


	// add even more elements
	cout << "---------------------------------------" << endl << endl;
	cout << "case 4: insert AES, SONY, TSLA, TAP, ALGN, ALK, ALL, ALLE: "<< endl;
	stockMap->insert(e);
	stockMap->insert(f);
	stockMap->insert(g);
	stockMap->insert(h);
	stockMap->insert(i);
	stockMap->insert(j);
	stockMap->insert(k);
	stockMap->insert(l);
	stockMap->display();
	cout << endl;

	//test the find  method
	cout << "---------------------------------------" << endl << endl;
	cout << "case 5: test find  method (MMM and AMD) " << endl;
	Stock *tempStock;
	tempStock = stockMap->find("MMM");
	if (tempStock == nullptr)
		cout << "MMM is not in the table " << endl;
	else
		cout << "found: " << tempStock << endl;

	tempStock = stockMap->find("AMD");
	if (tempStock == nullptr)
		cout << "AMD is not in the table " << endl;
	else
		cout << "found: " << tempStock << endl;


	// test inserting repeated elements
	// How can you adapt your code to handle this?
	cout << "---------------------------------------" << endl << endl;
	cout << "case 6: test insert of repeat element: (MMM again) " << endl;
	stockMap->insert(d);
	stockMap->display();
	cout << endl;


	//test removing an element
	cout << " ---------------------------------------" << endl << endl;
	cout << "case 7: test removal of by key value (ABBV) : " << endl;
	stockMap->remove("ABBV");
	stockMap->display();
	cout << endl;

	//test removing the element in the middle of a bucket list
	cout << "---------------------------------------" << endl << endl;
	cout << "case 8: test removal of middle element in list (SONY)  " << endl;
	stockMap->remove("SONY");
	stockMap->display();
	cout << endl;

	//test removing the element at the end of a bucket list
	cout << "---------------------------------------" << endl << endl;
	cout << "case 9: test removal of tail element in list (ALLE) " << endl;
	stockMap->remove("ALLE");
	stockMap->display();
	cout << endl;

	//test removing the element at the front of a bucket list
	cout << "---------------------------------------" << endl << endl;
	cout << "case 10: test removal of front element in list (ALL) " << endl;
	stockMap->remove("ALL");
	stockMap->display();
	cout << endl;

	// try removing an element not in the list
	// should do nothing
	cout << " ---------------------------------------" << endl << endl;
	cout << "case 11: test removal of element not in the list: (LNT) " << endl;
	stockMap->remove("LNT");
	stockMap->display();
	cout << endl;

	return 0;

}

#include "Stock.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

	// locally allocated stock object (on the stack)
	// no parameters provided
	Stock stock1;
 	cout << "stock 1: name: " << stock1.getName()
		  << " , ticker: " << stock1.getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock1.getPrice()
		  << " , quantity: " << stock1.getQuantity()
		  << endl << endl;

	// parameters provided
	Stock stock2("Abbott Laboratories", "ABB", 33.63, 200);
	cout << "stock 2: name: " << stock2.getName()
		  << " , ticker: " << stock2.getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock2.getPrice()
		  << " , quantity: " << stock2.getQuantity()
		  << endl << endl;

	// set methods called to change data attributes
	stock2.setName("ABBVie");
	stock2.setTicker("ABBV");
	stock2.setPrice(152.05);
	stock2.setQuantity(1000);

	cout << "But now we've changed stock 2, as seen here:  " << endl;
	cout << "stock 2: name: " << stock2.getName()
		  << " , ticker: " << stock2.getTicker()
	  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock2.getPrice()
		  << " , quantity: " << stock2.getQuantity()
		  << endl << endl;

	// dynamically allocated stock
	// no argument constructor causes default values to be set
	Stock * stockPtr3 = new Stock();
	cout << "*stockPtr3: name: " << stockPtr3->getName()
		  << " , ticker: " << stockPtr3->getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr3->getPrice()
		  << " , quantity: " << stockPtr3->getQuantity()
		  << endl << endl;

	// dynamically allocated stock
	// passes all 4 arguments
	Stock * stockPtr4 = new Stock("Activision Blizzard", "ATVI",75.45, 1000 );
	cout << "*stockPtr4: name: " << stockPtr4->getName()
		  << " , ticker: " << stockPtr4->getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr4->getPrice()
		  << " , quantity: " << stockPtr4->getQuantity()
		  << endl << endl;

	stockPtr4->setName("Amazon");
	stockPtr4->setTicker("AMZN");
	stockPtr4->setPrice(97.61);
	stockPtr4->setQuantity(1000);

	cout << "But now we've changed stock 4, as seen here:  " << endl;
	cout << "stock 4: name: " << stockPtr4->getName()
		  << " , ticker: " << stockPtr4->getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr4->getPrice()
		  << " , quantity: " << stockPtr4->getQuantity()
		  << endl << endl;

	Stock stock6(stock2);
	cout << "stock 6 is a copy of stock 2: name: " << stock6.getName()
		  << " , ticker: " << stock6.getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock6.getPrice()
		  << " , quantity: " << stock6.getQuantity()
		  << endl << endl;

	cout << "Now we change the price of stock 6." << endl;
	stock6.setPrice(126.44);
	cout << "stock 6: "
		  << stock6.getName() << "," << stock6.getTicker() << ","
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock6.getPrice() << "," << stock6.getQuantity() << endl;
	cout << "and see that stock 2 is unchanged -- 6 is a separate copy " << endl;
	cout << "stock 2: "
		  << stock2.getName() << "," << stock2.getTicker() << ","
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock2.getPrice() << "," << stock2.getQuantity() << endl;

	cout << "This is also true with dynamically allocated Stock objects."
		  << endl;
	Stock *stockPtr5 = new Stock(*stockPtr4);
	cout << "*stockPtr5 is a copy of *stockPtr4 " << endl;
	cout << "*stockPtr5: " << stockPtr5->getName() << ", "
		  << stockPtr5->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr5->getPrice() << " , "
		  << stockPtr5->getQuantity() << endl << endl;

	cout << "*stockPtr4: " << stockPtr4->getName() << ", "
		  << stockPtr4->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr4->getPrice() << " , "
		  << stockPtr4->getQuantity() << endl << endl;

	cout << "And if we make a change to *stock5Ptr, *stock4Ptr is unaffected."
		  << endl;
	stockPtr5->setPrice(101.44);
	cout << "*stockPtr5: " << stockPtr5->getName() << ", "
		  << stockPtr5->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr5->getPrice() << " , "
		  << stockPtr5->getQuantity() << endl << endl;

	cout << "*stockPtr4: " << stockPtr4->getName() << ", "
		  << stockPtr4->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr4->getPrice() << " , "
		  << stockPtr4->getQuantity() << endl << endl;

	cout << "But notice that if two pointer point to the same thing," << endl;
	cout << "then changes through one pointer affect the object, " << endl;
	cout << "which is also referred to by the second pointer" << endl << endl;
	Stock *stockPtr7 = new Stock("Allstate Corp", "ALL", 135.41, 1000);
	Stock *stockPtr8 = stockPtr7;
	cout << "Before: *stockPtr7: " << stockPtr7->getName() << ", "
		  << stockPtr7->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr7->getPrice() << " , "
		  << stockPtr7->getQuantity() << endl;
	cout << "Before: *stockPtr8: " << stockPtr8->getName() << ", "
		  << stockPtr8->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr8->getPrice() << " , "
		  << stockPtr8->getQuantity() << endl << endl;

	stockPtr7->setPrice(188.88);

	cout << "After: *stockPtr7: " << stockPtr7->getName() << ", "
		  << stockPtr7->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr7->getPrice() << " , "
		  << stockPtr7->getQuantity() << endl;
	cout << "After: *stockPtr8: " << stockPtr8->getName() << ", "
		  << stockPtr8->getTicker() << " , "
 		  << fixed << setprecision(2) << setw(5) << right
		  << stockPtr8->getPrice() << " , "
		  << stockPtr8->getQuantity() << endl << endl;

	return 0;

}

#include "Stock.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

	Stock stock1("Akamai Technologies", "AKAM", 122.086, 500);
	Stock stock2("Alaska Air Group", "ALK", 61.4898, 1000);
	Stock stock3(stock1);

	cout << "stock 1: name: " << stock1.getName()
		  << " , ticker: " << stock1.getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock1.getPrice()
		  << " , quantity: " << stock1.getQuantity()
		  << endl;

	cout << "The key value for stock 1 is:" << stock1.getKey() << endl;

	cout << "stock 2: name: " << stock2.getName()
		  << " , ticker: " << stock2.getTicker()
		  << " , price: $"
 		  << fixed << setprecision(2) << setw(5) << right
		  << stock2.getPrice()
		  << " , quantity: " << stock2.getQuantity()
		  << endl;

	cout << "The key value for stock 2 is:" << stock2.getKey() << endl;


	if (stock1 < stock2)
		cout << "stock 1 is less than stock 2" << endl;
	else
		cout << "stock 1 is not less than stock 2" << endl;

	if (stock1 <= stock2)
		cout << "stock 1 is less than or equal to stock 2" << endl;
	else
		cout << "stock 1 is not less than or equal to stock 2" << endl;

	if (stock1 > stock2)
		cout << "stock 1 is greater than stock 2" << endl;
	else
		cout << "stock 1 is not greater than stock 2" << endl;

	if (stock1 >= stock2)
		cout << "stock 1 is greater than or equal to stock 2" << endl;
	else
		cout << "stock 1 is not greater than or equal to stock 2" << endl;

	if (stock1 == stock2)
		cout << "stock 1 is equal to stock 2" << endl;
	else
		cout << "stock 1 is not equal to stock 2" << endl;

	if (stock1 == stock3)
		cout << "stock 1 is equal to stock 3" << endl;
	else
		cout << "stock 1 is not equal to stock 3" << endl;


	if (stock1 == "AKAM")
		cout << "stock 1 has key value AKAM" << endl;
	else
		cout << "stock 1 does not have key value AKAM" << endl;

	if (stock2 == "AKAM")
		cout << "stock 2 has key value AKAM" << endl;
	else
		cout << "stock 2 does not have key value AKAM" << endl;
	

	return 0;



}

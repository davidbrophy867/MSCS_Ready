#include <iostream>
#include "Market.h"
using namespace std;

int main(){
	// test the 3 types of constructors
	cout << "creating 3 market objects " << endl;
	Market m1;
	Market m2("EKSE");
	Market m3("MSCS",3);
	cout << "----------------------" << endl; 

	//read in and display a stockfile
	//using current day number for the market
	cout << "reading in file Default.0.txt & displaying m1: " << endl << endl;
	m1.readStockFile();
	m1.showStocks();
	cout << "----------------------" << endl;

	//read in and display a stockfile
	//using a specified day number
	cout << "reading in EKSE.0.txt & displaying m2: " << endl << endl;
	m2.readStockFile(0);
	m2.showStocks();
	cout << "----------------------" << endl;

	//take a step of the market
	//update the day
	//write to a file using current day number for the market
	cout << "m1 updates one step and a day passes " << endl;
	cout << "m1 written to new day numbered file (Default.1.txt):  " << endl << endl;
	//m1.step();
	m1.nextDay();
	m1.writeStockFile(m1.getDay());
	cout << "----------------------" << endl;

	//take a  series of steps
	//go to the next day
	//write a new stock file using a specified day number
	cout << "m2 updates 10 steps and a day passes " << endl;
	cout << "m2 written to new day numbered file (EKSE.1.txt)" << endl << endl;
	for (unsigned int i{0}; i < 10; i++){
		m2.step();
	}
	m2.nextDay();
	m2.writeStockFile(m2.getDay());
	cout << "----------------------" << endl;

	//create a new Stock
	//add the new Stock to the market's stockList
	//display the updated stock list
	cout << "new stock PLUG created and added to market" << endl;
	cout << "and demonstrated via stock display: " << endl << endl;
	m2.addStock(new Stock("Plug Power Inc", "PLUG", 26.30 , 1000));
	m2.showStocks();
	cout << "----------------------" << endl;

	//delete a Stock from the market's stockList
	//display the updated stock list
	cout << "stock AOS removed from market" << endl;
	cout << "and demonstrated via stock display: " << endl << endl;
	m2.removeStock("AOS");
	m2.showStocks();
	cout << "----------------------" << endl;

	cout << "stock PLUG retrieved from market" << endl;
	cout << "price updated to 27.50 " << endl;
	cout << "and demonstrated via stock display: " << endl << endl;
	m2.getStockPtr("PLUG")->setPrice(27.50);
	m2.showStocks();
	cout << "----------------------" << endl;

	cout << "That's all, folks!" << endl;

	return 0;

}

#include "Market.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


Market::Market():name("Default"),currentDay(0),
	stockMap(new HashMap(HASHMAP_SIZE)), keyList(new StringList()) { } 
Market::Market(string mname):name(mname), currentDay(0),
	stockMap(new HashMap(HASHMAP_SIZE)), keyList(new StringList()) { } 
Market::Market(string mname, int dayNum):name(mname), currentDay(dayNum),
	stockMap(new HashMap(HASHMAP_SIZE)), keyList(new StringList()) { } 


void Market::readStockFile(){
	cout << "calling readStockFile with currentDay = " << currentDay << endl;
	this->readStockFile(currentDay);
}

void Market::writeStockFile(){
	this->writeStockFile(currentDay);
}

void Market::writeStockFile(int dayNum){
	// build the file name
	string fname = this->name;
	fname.append(".");
	string dayWord = to_string(dayNum);
	fname.append(dayWord);
	fname.append(".txt");

	// create an input file stream
	ofstream outfile(fname, ios::out);
	
	// check that we can open it
   if (!outfile){
      cerr << "Could not open file "<< fname << endl;
      exit(EXIT_FAILURE);
   }

	// get a pointer to the start of the list of keys
	Node<string> * cursor = keyList->getHead();
	Stock * found;
	string key;
 
	while (cursor != nullptr){
		// get the key from the list of keys
		key = cursor->getValue();
		// get the stock associated with that key
   	found = stockMap->find(key);
		outfile << found->getTicker() << ",";
		outfile << found->getName() << ",";
		outfile << found->getPrice() << ",";
		outfile << found->getQuantity() << endl;
		// go on to the next node in the list of keys
		cursor = cursor->getNext();
	}

	outfile.close();
}

void Market::readStockFile(int dayNum){
	// build the file name
	cout << "calling readStockFile with dayNum = " << dayNum << endl;
	string fname = this->name;
	fname.append(".");
	string dayWord = to_string(dayNum);
	fname.append(dayWord);
	fname.append(".txt");

	// create an input file stream
	ifstream infile(fname, ios::in);
	
	// check that we can open it
   if (!infile){
      cerr << "Could not open file "<< fname << endl;
      exit(EXIT_FAILURE);
   }

  string ticker;
   string name;
   double price;
   int quantity;

   // temp variable to hold one line of text from the file
   string line;

   // temp variable to hold one character version of price & quantity
   string temp_word;

// read one line at time from the file of stock info
   while (getline(infile, line)){
      if (line.size() > 1){

         //treat the string containing line as a stream named words
         istringstream words(line);

         //read from words into ticker until we see a comma
         getline(words, ticker, ',');

         //continuing reading, now into name, until we see a comma
         getline(words, name, ',');

         //continuing reading, now into temp_word, until we see a comma
         // and assign to price
         getline(words, temp_word, ',');
         price = stod(temp_word);

         //continuing reading, now into temp_word, until we see a comma
         // and assign to quantity
         getline(words, temp_word, '\n');
         quantity = stoi(temp_word);

         Stock *s = new Stock(name, ticker, quantity, price);

			// ... add the stock the Market object's HashMap of stocks 
			stockMap->insert(s);
			// ... add the key to the object's list of keys
			keyList->insert(ticker);
      }
   }
	infile.close();
	return;

}

void Market::addStock(Stock *s){
	// add the stock to the stockMap
	stockMap->insert(s);
	// add the eky to the list of keys
	keyList->insert(s->getTicker());
	return;
};


void Market::removeStock(string sym){
	// remove the stock from the stockMap
	stockMap->remove(sym);
	// remove the key from the list of keys
	keyList->remove(sym);
	return;
};

Stock * Market::getStockBySymbol(string sym){
   return stockMap->find(sym);
};

void Market::showStocks() const {
	cout << "Stocks for Market: " << name << endl;
	Node<string> * cursor = keyList->getHead();
	Stock *found;
	string key;

	while (cursor != nullptr){
		key = cursor->getValue();
   	found = stockMap->find(key);
		cout << found << endl;
		cursor = cursor->getNext();
	}
	return;

};

int Market::getDay() const{
	return currentDay;
}

int Market::nextDay() {
	return ++currentDay;
}

void Market::step() {
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<float> distr(0,1);
	float max_range = 0.10;
	float shift = 0.05;
		
	float factor;

	Node<string> * cursor = keyList->getHead();
	Stock *found;
	string key;

	while (cursor != nullptr){
		// get the ticker symbol
		key = cursor->getValue();
		// get the stock associated with the ticker symbol
		found = stockMap->find(key);
		//produce a factor 
		factor = (distr(eng) * max_range) - shift;

		// get the stock's price
		double price = found->getPrice();

		//  update the stock's price 
		price =  price * (1 + factor);
		found->setPrice(price);;

		// move on to the next ticker symbol in the list
		cursor = cursor->getNext();
	}
};



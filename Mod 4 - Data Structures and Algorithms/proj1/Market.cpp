#include "Market.h"

Market::Market(){
  name = "Default"; //set market name to default
  day = 0;          //set current day to zero
  list = new StockList();
}

Market::Market(string n, int d){
  name = n;
  day = d;
  list = new StockList();
}

Market::Market(string n){
  name = n;
  day = 0;
  list = new StockList();
}

void Market::readStockFile(int dayNum){
  string filename = name + "." + to_string(dayNum) + ".txt";

  // insert file i o part -----------------------------------------------------------
  ifstream infile(filename, ios::in);

  if (!infile){
		cerr << "Could not open file " << filename << endl;
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

      Stock *s = new Stock(name, ticker, price, quantity);
      //cout << *s << endl;

      // ... add the stock the Market object's list of stocks
      list->insert(s);
    }
  }
  //--------------------------------------------------------------------------------
}

void Market::readStockFile(){
  readStockFile(day);
}

void Market::writeStockFile(int dayNum){
  string filename = name + "." + to_string(dayNum) + ".txt";

  ofstream outfile(filename, ios::out);

  if (!outfile){
		cerr << "Could not open file " << filename << endl;
		exit(EXIT_FAILURE);
	}

  StockNode* cursor = list->getHead();

  while(cursor!=nullptr){
    outfile << cursor->getStockPtr()->getTicker() << "," << cursor->getStockPtr()->getName();
    outfile << "," << cursor->getStockPtr()->getPrice() << "," << cursor->getStockPtr()->getQuantity() << endl;
    //ticker.name.price.quantity
    cursor = cursor->getNext();
  }

  outfile.close();
}

void Market::writeStockFile(){
  writeStockFile(day);
}

void Market::showStocks(){
  cout << "Stocks for Market: " << name << endl;
  list->display();
}

void Market::step(){
  constexpr int FLOAT_MIN = 0;
  constexpr int FLOAT_MAX  = 1;
  const int range = 0.10;

  random_device rd;
  default_random_engine eng(rd());
  uniform_real_distribution<float> distr(FLOAT_MIN,FLOAT_MAX);

  StockNode* cursor = list->getHead();

  double stepMultiplier;
  double oldPrice;
  double newPrice;

  //list->display();

  while(cursor!=nullptr){
    stepMultiplier = 1 + (range * distr(eng)) - 0.05;
    //price += (price*stepMultiplier);
    oldPrice = cursor->getStockPtr()->getPrice();
      //cout << "oldPrice for "<< cursor->getStockPtr()->getTicker() << " is " << oldPrice << endl;
    newPrice = oldPrice * stepMultiplier;
      //cout << "newPrice for " << cursor->getStockPtr()->getTicker() << " is " << newPrice << endl;
    cursor->getStockPtr()->setPrice(newPrice);

    cursor = cursor->getNext();
  }
}

int Market::nextDay(){
  return ++day;
}

int Market::getDay(){return day;}

void Market::addStock(Stock *s){
  //StockNode* newNode = new StockNode(s);
  list->insert(s);
}

void Market::removeStock(string t){
  list->remove(t);
}

Stock* Market::getStockPtr(string t){
  return list->find(t)->getStockPtr();
}

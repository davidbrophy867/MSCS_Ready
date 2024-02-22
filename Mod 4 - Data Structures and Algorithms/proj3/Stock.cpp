#include "Stock.h"
#include <iomanip>

using namespace std;

Stock::Stock(string n, string sym, int num, double pr):
	name(n), ticker(sym), quantity(num), price(pr) { };

Stock::Stock(const Stock& s):
	name(s.name), ticker(s.ticker), quantity(s.quantity), price(s.price) { };

const string Stock::getName() const{
	return name;
}

const string Stock::getKey()const {
	return ticker;
}

const string Stock::getTicker() const {
	return ticker;
}

double Stock::getPrice() const{
	return price;
};

int Stock::getQuantity() const{
	return quantity;
};

void Stock::setName(string s){
	name = s;
};

void Stock::setTicker(string s){
	ticker = s;
};

void Stock::setPrice(double p){
	price = p;
};

void Stock::setQuantity(int s){
	quantity = s;
};

bool Stock::operator>(const Stock other) const{ 
	return (getKey() > other.getKey()); 
};

bool Stock::operator<(const Stock other) const{ 
	return (getKey() < other.getKey()); 
};

bool Stock::operator==(string key) const{ 
	return (getKey() == key); 
};

bool Stock::operator==(const Stock other) const{ 
	return (getKey() == other.getKey());
};

bool Stock::operator>=(const Stock other) const{
	return (getKey() >= other.getKey());
};

bool Stock::operator<=(const Stock other) const{
	return (getKey() <= other.getKey());
};	

ostream& operator<<(ostream& os, const Stock& st) {
    os << std::left << std::setw(5) 
		 << st.ticker << ": "  
		 << std::setw(4)
		 << std::right 
		 << st.quantity 
		 << " @ $ " 
		 << std::fixed 
		 << std::setprecision(2) 
		 << std::setw(7) 
		 << std::right 
	    << st.price
		 << " (" << st.name << ")" ;
    return os;
}

ostream& operator<<(ostream& os, const Stock* st) {
    os << std::left << std::setw(5) 
		 << st->ticker << ": "  
		 << std::setw(4)
		 << std::right 
		 << st->quantity 
		 << " @ $ " 
		 << std::fixed 
		 << std::setprecision(2) 
		 << std::setw(7) 
		 << std::right 
	    << st->price
		 << " (" << st->name << ")" ;
    return os;
}



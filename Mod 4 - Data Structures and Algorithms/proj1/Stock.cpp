#include "Stock.h"

Stock::Stock(string n, string t, double p, int q){
  setTicker(t);
  setName(n);
  setPrice(p);
  setQuantity(q);
}

//getter methods
const string Stock::getKey() const{return ticker;} //is this right?

const string Stock::getName() const{return name;}

const string Stock::getTicker() const{return ticker;}

double Stock::getPrice() const{return price;}

int Stock::getQuantity() const{return quantity;}

//setter methods
void Stock::setTicker(string t){ticker = t;}

void Stock::setName(string n){name = n;}

void Stock::setPrice(double p){price = p;}

void Stock::setQuantity(int q){quantity = q;}

//overloading (test using stock tester 2)
bool Stock::operator<(const Stock &other) const{
  return(getKey() < other.getKey());
}

bool Stock::operator>(const Stock &other) const{
  return(getKey() > other.getKey());
}

bool Stock::operator==(const Stock &other) const{
  return(getKey() == other.getKey());
}

bool Stock::operator==(const string s) const{
  return(getKey() == s);
}

bool Stock::operator>=(const Stock &other) const{
  return(getKey() >= other.getKey());
}

bool Stock::operator<=(const Stock &other) const{
  return(getKey() <= other.getKey());
}

//<< overloading (DONE)
ostream& operator<<(ostream& os, const Stock& st){
  os << setw(5) << left << st.ticker << ":" << setw(5) << right << st.quantity << " @ $" << setw(8) << fixed << setprecision(2) << st.price << " (" << st.name << ")";
  return os;
}

#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class Stock{

friend ostream& operator<<(ostream&, const Stock&); //<< overloading

public:
    explicit Stock(string="null", string="nul", double=0.0, int=0);

    const string getKey() const;  //WHAT IS THIS
    const string getName() const;
    const string getTicker() const;
    double getPrice() const;
    int getQuantity() const;

    void setTicker(string);
    void setName(string);
    void setPrice(double);
    void setQuantity(int);

    bool operator<(const Stock &other) const;
    bool operator>(const Stock &other) const;
    bool operator==(const Stock &other) const;
    bool operator==(const string) const;
    bool operator>=(const Stock &other) const;
    bool operator<=(const Stock &other) const;

private:
    string ticker;
    string name;
    double price;
    int quantity;
};

#endif

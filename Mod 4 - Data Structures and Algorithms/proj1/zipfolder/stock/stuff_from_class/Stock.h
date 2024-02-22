#ifndef STOCK_H
#define STOCK_H
#include <iostream>
#include <string>
using namespace std;

//use project 3 from mod 2 as example
class Stock{
public:
    explicit Stock(string="null", string="nul", double=0.0, int=0);
private:
    string ticker;
    string name;
    double price;
    int quantity;
};
#endif

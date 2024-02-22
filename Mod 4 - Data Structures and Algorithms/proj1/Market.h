#ifndef MARKET_H
#define MARKET_H

#include "StockList.h"
#include <fstream>
#include <cstdlib>
#include <random>

class Market{ //when should i put const (figure this out for stocklist too)
  public:
    Market();
    Market(string, int);
    Market(string);

    void readStockFile(int);
    void readStockFile();

    void writeStockFile(int);
    void writeStockFile();

    void showStocks();
    void step();
    int nextDay();
    int getDay();
    void addStock(Stock*);
    void removeStock(string);
    Stock *getStockPtr(string);

  private:
    StockList* list;
    string name;
    int day;
};

#endif

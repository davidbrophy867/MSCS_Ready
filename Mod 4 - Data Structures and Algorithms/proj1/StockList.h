#ifndef STOCKLIST_H
#define STOCKLIST_H

#include "StockNode.h"

class StockList {
  public:
    StockList();
    ~StockList();

    StockNode* getHead() const;

    void insert(Stock*);
    void remove(Stock*);
    void remove(string);
    StockNode *find(string);
    bool contains(Stock*);
    bool contains(string);
    void display();

	private:
    StockNode* head; //head is a pointer but it is not a node in of itself, just a placeholder
};

#endif

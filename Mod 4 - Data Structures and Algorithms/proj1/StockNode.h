#ifndef NODE_H
#define NODE_H
#include "Stock.h"

class StockNode {
  public:
	StockNode():next(nullptr){};
	~StockNode(){ delete stkPtr; };
	StockNode(Stock *sPtr):stkPtr(sPtr), next(nullptr){};

	void setStock(Stock *sPtr){ stkPtr = sPtr; };
	void setNext(StockNode *n){ next = n; };
	StockNode * getNext() const{ return next; };
	Stock* getStockPtr() { return stkPtr; };
	Stock getStock() { return *stkPtr; };

	private:
		Stock* stkPtr;
		StockNode* next;
};
#endif

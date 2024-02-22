#ifndef STOCKTREE_NODE_H
#define STOCKTREE_NODE_H
#include "Stock.h"

class StockTreeNode {
  public:
	StockTreeNode():value(nullptr),left(nullptr),right(nullptr),parent(nullptr){};
	StockTreeNode(Stock *sPtr):value(sPtr), left(nullptr),right(nullptr),parent(nullptr){};

	Stock * getStockPtr() { return value; };
	const Stock &getStock() { return *value; };
	StockTreeNode * getLeft() const{ return left; };
	StockTreeNode * getRight() const{ return right; };
	StockTreeNode * getParent() const{ return parent; };

  void setStockPtr(Stock* sPtr){ value = sPtr; };
  void setStock(Stock s){ value = &s; };
	void setLeft(StockTreeNode *n){ left = n; };
	void setRight(StockTreeNode *n){ right = n; };
	void setParent(StockTreeNode *n){ parent = n; };

	private:
		Stock*	value;
		StockTreeNode * left;
		StockTreeNode * right;
		StockTreeNode * parent;

};
#endif

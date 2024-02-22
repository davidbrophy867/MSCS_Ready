#include "StockTreeNode.h"

using namespace std;

int main(){
	StockTreeNode *tnPtr1;
	tnPtr1 = new StockTreeNode();
	Stock *a = new Stock("AbbVie", "ABBV", 1000, 116.35);
	tnPtr1->setStockPtr(a);
	cout << "root is: ";
	cout << 	tnPtr1->getStockPtr()->getTicker() << " ";
	cout <<  tnPtr1->getStockPtr()->getName() << " ";
	cout << 	tnPtr1->getStockPtr()->getQuantity() << " ";
	cout << 	tnPtr1->getStockPtr()->getPrice() << endl;

	StockTreeNode *tnPtr2;
	tnPtr2 = new StockTreeNode();
   Stock *b = new Stock("Abbott Laboratories", "ABB", 200, 35.17);
	tnPtr2->setStockPtr(b);

	StockTreeNode *tnPtr3;
	tnPtr3 = new StockTreeNode();
   Stock *c = new Stock("Accenture", "ACN", 1000, 309.15);
	tnPtr3->setStockPtr(c);

	tnPtr1->setLeft(tnPtr2);
	tnPtr2->setParent(tnPtr1);

	tnPtr1->setRight(tnPtr3);
	tnPtr3->setParent(tnPtr1);

	cout << "the root's left child  is: ";
	cout << 	tnPtr1->getLeft()->getStockPtr()->getTicker() << " ";
	cout <<  tnPtr1->getLeft()->getStockPtr()->getName() << " ";
	cout << 	tnPtr1->getLeft()->getStockPtr()->getQuantity() << " ";
	cout << 	tnPtr1->getLeft()->getStockPtr()->getPrice() << endl;

	cout << "the root's right child  is: ";
	cout << 	tnPtr1->getRight()->getStockPtr()->getTicker() << " ";
	cout <<  tnPtr1->getRight()->getStockPtr()->getName() << " ";
	cout << 	tnPtr1->getRight()->getStockPtr()->getQuantity() << " ";
	cout << 	tnPtr1->getRight()->getStockPtr()->getPrice() << endl;


	cout << 	"ACN's parent is: " << tnPtr3->getParent()->getStockPtr()->getTicker() << endl;
	cout << 	"ABB's parent is: " << tnPtr2->getParent()->getStockPtr()->getTicker() << endl;



	return 0;
}

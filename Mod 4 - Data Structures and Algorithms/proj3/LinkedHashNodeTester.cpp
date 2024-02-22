#include <iostream>
#include <string>
#include "Stock.h"
#include "LinkedHashNode.h"
using namespace std;

int main(){

	Stock *s1 = new Stock("Sony Group Corp", "SONY", 100, 85.60);
	Stock *s2 = new Stock("Tesla Inc ", "TSLA", 100, 1005.05);
	Stock *s3 = new Stock("Molson Coors Beverage Co", "TAP", 100, 53.77);

	LinkedHashNode lhs1(s1);
	LinkedHashNode lhs2(s2);
	LinkedHashNode lhs3(s3);

	cout << "lsh1 contains stock with key " << lhs1.getKey() 
		  << "and stock: " << endl << lhs1.getStock() << endl;

	cout << endl;

	cout << "lsh2 contains stock with key " << lhs2.getKey() 
		  << "and stock: " << endl << *(lhs2.getStock()) << endl;
	cout << endl;

	cout << "lsh3 contains stock with key " << lhs3.getKey() 
		  << "and stock: " << endl << *(lhs3.getStock()) << endl;

	cout << endl;

}

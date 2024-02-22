#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <iostream>

/*
 * class Stock encapsulates a stock position
 * including name, ticker, price, and numshares 
 * Provides methods used by the stock_server to 
 * to support buying and selling of shares.
 * EK, Feb 2023
 */
using namespace std;


class Stock {

/*
 * This overloaded output stream operator:
 *	- displays the content of the Stock specified in the second parameter
 *	- to the output stream specified in the first parameter
 * - and returns a reference to the same output stream
 * The use of reference types (the &) prevents excess copying.
 * Making this a friend function permits the operator<< method
 * to directly access the private variables of the Stock class.
 */
friend ostream& operator<<(ostream& os, const Stock& st);
friend ostream& operator<<(ostream& os, Stock *stkPtr);

public:
	/* 
	 * The UML diagram initially called for 3 separate constructors,
	 * as did the description of the Stock class in the assignment.
	 * Let's talk first about the no-argument and 4 argument constructors:
	 */
	 //Stock();
	 //Stock(string n, string t, double p, int q);
	/*
	 * The instructions also say that the no-argument constructor 
	 * should set the default values to "null" for the name, "nul"
	 * for the ticker symbol, 0.0 for price, and 0 for quantity.
	 * Also we know that we can use a default argument constructor to 
	 * handle constructor calls of both types with a single constructor.
	 * Let's write that one first:
	 */
	
	explicit Stock(string="null", string="nul", double=0.0, int=0);

	/*
	 * A copy constructor takes a single argument: a object of the 
	 * same class.  The goal of the copy constructor is to 
	 * make an copy of the object passed in(labeled "other" below).
	 * The copied object (other) should not change, thus we use
	 * the const modifier.
	 * If we did not use the reference notation (&), then what
	 * would happen when this constructor is called would be:
	 * 1. a copy of the passed object is created
	 * 2. the constructor makes a new Stock object
	 * 3. the values in the object created in #1 are copied, element by 
	 *    element into the object created in #2.
	 * 4. When the constructor returns, the copy created in #1 is 
	 *    destroyed and the memory returned.
	 * With the use of the reference parameter (&) we avoid making
	 * the extra copy of step 1.
	 * Moral of story: use the & -- it is more efficient, and use
	 * const to ensure that the original is unchanged.
	 */

//	Stock(const Stock& other);


	const string getKey() const;
	const string getName() const;
	const string getTicker() const;
	double getPrice() const;
	int getQuantity() const;

	void setName(string s);
	void setTicker(string s);
	void setPrice(double p);
	void setQuantity(int s);


	// relational operators

	// we can implement the less-than operator as member function
	bool operator<(const Stock &other) const;
	bool operator<(const string key) const;


	bool operator>(const Stock &other) const;
	bool operator>=(const Stock &other) const;
	bool operator<=(const Stock &other) const;
	bool operator==(const Stock &other) const;

	bool operator==(const string key) const;

private:
	string name;
	string ticker;
	double price;
	int quantity;
};


#endif

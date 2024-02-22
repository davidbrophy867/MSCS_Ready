#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class StringList{

public:
	StringList();
	~StringList();
	void insert(string k);
	void remove(string k);
	bool contains(string k);
	void display();
	Node<string> * getHead();

private:
	Node<string> * head;

};

#endif


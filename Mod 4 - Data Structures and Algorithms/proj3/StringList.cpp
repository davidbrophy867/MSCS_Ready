#include "StringList.h"

StringList::StringList():head(nullptr){};

StringList::~StringList(){
	Node<string> *cursor = head;
	while (cursor != nullptr){
		cursor = cursor->getNext();
		delete head;
		head = cursor;
	}
};

Node<string> * StringList::getHead(){
	return head;
}

void StringList::insert(string k){
	if (contains(k))
		return;

	//make a new node
	Node<string> *newNode = new Node<string>;
	newNode->setValue(k);
	newNode->setNext(nullptr);

	//is the list empty?
	if (head == nullptr){
		head = newNode;
		return;
	}

	// are we comparing to the first element in the list?
	if (head->getValue() > newNode->getValue()){
		newNode->setNext(head);
		head = newNode;
	}
	else{ //find the right spot
		Node<string> *cursor = head;
		while ( (cursor->getNext() != nullptr) && (cursor->getNext()->getValue() < k)){
			cursor = cursor->getNext();
		}
		newNode->setNext(cursor->getNext());
		cursor->setNext(newNode);
	}

	return;

};

void StringList::remove(string k){
	if (!contains(k))
		return;

	Node<string> * cursor;
	Node<string> * temp;

	//is the list empty?
	if (head == nullptr){
		return;
	}

	// are we comparing to the first element in the list?
	if (head->getValue() == k){
		temp = head;
		head = head->getNext();
		delete temp;
	}
	else{ //find the right spot
		Node<string> *cursor = head;
		while ( (cursor->getNext() != nullptr) && (cursor->getNext()->getValue() < k)){
			cursor = cursor->getNext();
		}
		if (cursor->getNext()->getValue() == k){
			temp = cursor->getNext();
			cursor->setNext(cursor->getNext()->getNext());
			delete temp;
		}
	}

	return;
};

void StringList::display(){
	int counter = 0;
	Node<string> * cursor = head;
	if (head == nullptr) cout << "empty list " << endl;
	while (cursor != nullptr){
		if (counter > 0) cout << ", ";
		cout << cursor->getValue();
		cursor = cursor->getNext();
		counter++;
		if (counter % 10 == 0) cout << endl;
	}
	cout << endl;
};

bool StringList::contains(string k){

	Node<string> * cursor = head;
	while (cursor != nullptr){
		if (cursor->getValue() == k)
			return true;
		cursor = cursor->getNext();
	}
	return false;
};
	


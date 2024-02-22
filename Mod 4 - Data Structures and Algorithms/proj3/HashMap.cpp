#include "HashMap.h"
using namespace std;

/*
 * ETK - April 2023
 * HashMap class
 * implements hashing with chaining
 * where the nodes in the tables are of type LinkedHashNode,
 * which contains a pointer to a Stock and a pointer
 * to the next node in the hash chain
 */

// constructor initialize table size and counter
// then creates table of nullptr entries
HashMap::HashMap(int sz):table_size(sz),counter(0){
	table = new LinkedHashNode*[table_size];
	for (int i=0; i < table_size; i++){
		table[i] = nullptr;
	}
}

// destructor should iterate through the table
// and traverses each list, deleting the nodes in the list
// note that the LinkedHashNode destructor will delete the associated stock
// don't forget to delete the table of pointers to the chains too!
HashMap::~HashMap(){
	// for you to implement
	LinkedHashNode* cursor = nullptr;
	LinkedHashNode* next = nullptr;

	for(int i = 0; i<table_size; i++){
		if(table[i]->getNext() != nullptr){
			cursor = table[i];

			while(cursor!=nullptr){
				next = cursor->getNext();
				delete cursor;
				cursor = next;
			}
			//delete table[i];
		}
		else{
			delete table[i];
		}
	}

	delete table;
}

// returns number of entries in the hash table
int HashMap::size(){
	return counter;
}

// a reasonabe hash code function
int HashMap::myHashCode(const string &str){
	unsigned hash = HASH_SEED;
	int nchars = str.length();
	for (int i=0; i < nchars; i++){
		hash = HASH_MULTIPLIER * hash + str[i];
	}
	return (hash & HASH_MASK);
}

// for your debugging pleasure
void HashMap::display(){

	for (int i=0; i< table_size; i++){
		cout << i << ": ";
		if (table[i] == nullptr){
			cout << endl;
		}
		else {
			LinkedHashNode *stock = table[i];
			while (stock != nullptr){
				cout << stock->getKey() << " -> ";
				stock = stock->getNext();
			}
			cout << " nullptr" << endl;
		}
	}
}

// creates a new Stock and then invokes the other insert method
bool HashMap::insert(string n, string t, int q, double p){
	Stock* thisStock = new Stock(n,t,q,p);
	bool inserted = insert(thisStock);
	return inserted;
}

// inserts the stock into the HashMap
bool HashMap::insert(Stock *ent){
	// get the key from the stock
	string key = ent->getKey();
	LinkedHashNode* newNode = new LinkedHashNode(ent);

	// generate a hash code, recalling that it is two_step process
	// first turn the key into an integer
	// then place it in the range 0 ... table_size -1 (use mod operator)
	// ...
	int intKey = myHashCode(key);
	int hashKey = intKey % (table_size);

	if(table[hashKey] == nullptr){ // if that bucket is empty, just make it the first stock in the list
		 table[hashKey] = newNode;
	}
 	else{ // otherwise, iterate through that bucket's list checking to see if the key already exists in the list
	 	if(find(key)!=nullptr){ // if it already exists, delete the newly created entry and return false
		 	delete newNode;
		 	return false;
	 	}
	 	else{// otherwise, add a new LinkedHashNode containing that Stock at the end of the list
			LinkedHashNode* cursor = table[hashKey];
			while(cursor->getNext()!=nullptr){
				cursor = cursor->getNext();
			}
			cursor->setNext(newNode);
	 	}
 	}
	// don't forget to increment counter and return true
	counter++;
	return true;
}


// returns a pointer to the Stock if it is in the HashMap
// otherwise return nullptr
Stock* HashMap::find(string key){
	Stock* returnVal = nullptr;
	// generate the hash code, scaling it to table_size
	int intKey = myHashCode(key);
	int hashKey = intKey % (table_size);
	// if there's nothing in that bucket, return nullptr
	if(table[hashKey] == nullptr){
		//return nullptr;
	}
	else{
		// otherwise search the list and either return a pointerto the associated stock or nullptr if not found
		LinkedHashNode* cursor = table[hashKey];
		if(cursor->getNext() != nullptr){
			while(cursor!=nullptr){
				if(cursor->getKey() == key){
					returnVal = cursor->getStock();
					//return cursor->getStock();
				}
				cursor = cursor->getNext();
			}
		}
		else{
			if(cursor->getKey() == key){
				returnVal = cursor->getStock();
				//return cursor->getStock();
			}
		}
	}
	return returnVal;
}


void HashMap::remove(string key){
	// generatethe hash code, scaling it to table_size
	int intKey = myHashCode(key);
	int hashKey = intKey % (table_size);

	if(table[hashKey] != nullptr){// if entries are found for that bucket, search along the list looking for it
		LinkedHashNode* cursor = table[hashKey];
		LinkedHashNode* leadPtr = table[hashKey]->getNext();;
		LinkedHashNode* trailPtr = nullptr;

		while(cursor->getNext()!=nullptr){
			if(cursor->getKey() == key){ //found it, so end loop
				break;
			}

			trailPtr = cursor;
			cursor = cursor->getNext();
			leadPtr = cursor->getNext();
		}

		if(trailPtr==nullptr){ //cursor was the first node -- trailPtr==nullptr
			table[hashKey] = cursor->getNext();
		}
		else if(leadPtr==nullptr){ //cursor was the last node -- leadPtr==nullptr
			trailPtr->setNext(nullptr);
		}
		else{ //cursor was a middle node
			trailPtr->setNext(leadPtr);
		}

		delete cursor;
	}
}

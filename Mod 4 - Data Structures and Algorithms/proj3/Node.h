#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
  public:
	Node<T>():next(nullptr){};
	Node<T>(T v):value(v), next(nullptr){};

	void setValue(T val){ 
		value = val; 
	};

	void setNext(Node<T> *n){
		next = n;
	};

	Node<T> * getNext() const{
		return next;
	};

	T& getValue() {
		return value;
	};

	private:
		T	value;
		Node<T> * next;

};
#endif

#include "StockTree.h"
//David Brophy 

// constructor
StockTree::StockTree():root(nullptr){ }

// destructor
StockTree::~StockTree(){
	deleteTree(root);
}

void StockTree::deleteTree(StockTreeNode *curr){
	// ... for you to fill in
	// use recursion!
	if(curr->getLeft() != nullptr){deleteTree(curr->getLeft());}
	if(curr->getRight() != nullptr){deleteTree(curr->getRight());}
	//cout << "now deleting: " << curr->getStockPtr()->getKey() << endl;
	//delete curr;
	remove(curr->getStockPtr());
}


// mutators
void StockTree::insert(Stock *stk){
	// make a new node, fill in the value portion
	StockTreeNode * newNode;
	newNode = new StockTreeNode(stk);
	// call insertNode to place it into the tree
	insertNode(newNode);
}

// insert the new node at the appropriate place
// in the binary search tree
// hint: always a leaf!
bool StockTree::insertNode(StockTreeNode * newNode){

	// for you to fill in
	// use the newNode's key value to decide where
	// in the tree to place the new node
	// hint: you can make use of the find method!

	// ...
	if(root==nullptr){ //if the tree is empty, make newNode the root
		root = newNode;
		return true;
	}

	//if it is not empty - use find method
	StockTreeNode* parent = find(newNode->getStockPtr()->getKey());
	//cout << "find returns parent equal to " << parent->getStockPtr()->getKey() << endl;
 if(newNode->getStock() < parent->getStock()){ //left
	 	//cout << newNode->getStockPtr()->getKey() << " is the left child" << endl;
		parent->setLeft(newNode);
		newNode->setParent(parent);
		return true;
	}
	else if(newNode->getStock() > parent->getStock()){ //right
		//cout << newNode->getStockPtr()->getKey() << " is the right child" << endl;
		parent->setRight(newNode);
		newNode->setParent(parent);
		return true;
	}
	else{ //if they are duplicates
		cout << newNode->getStockPtr()->getKey() << " is a duplicate" << endl; //FORMAT ---------------------------
		return false;
	}
}


// returns a pointer to the node containing the desired key value
// or a pointer to the node that WOULD be the parent if the key were present
// if the tree is empty, it should return nullptr
StockTreeNode*  StockTree::find(const string key) const {
	if(root == nullptr){return nullptr;} // if the tree is empty, it should return nullptr

	StockTreeNode* cursor = root;
	bool found = false;

	while(found==false){
		//key equal to cursor -- WE FOUND IT
		//key less than cursor --> go left (check if nullptr)
		//key greater than cursor --> go right (check if nullptr)

		if(key == cursor->getStockPtr()->getKey()){
			found = true;
		}
		else if(key < cursor->getStockPtr()->getKey()){ //go left
			//first check if left is nullptr
			if(cursor->getLeft() != nullptr){
				//update cursor and iterate through the loop again
				cursor = cursor->getLeft();
			}
			else{ //if it is nullptr
				//return cursor because it points to the parent
				found = true;
			}
		}
		else if(key > cursor->getStockPtr()->getKey()){ //go right
			//first check if right is nullptr
			if(cursor->getRight() != nullptr){
				//update cursor and iterate through the loop again
				cursor = cursor->getRight();
			}
			else{ //if it is nullptr
				//return cursor because it points to the parent
				found = true;
			}
		}
	}

	return cursor;
}

void StockTree::display() const{
	// ... for you to fill in
	// this method is invoked on the tree
	// it the tree is empty, it should display "Emptry Tree"
	// otherwise, it should call display, passing in root and level = 1

	if(root==nullptr){
		cout << "Empty Tree" << endl;
	}
	else{
		display(root, 1);
	}

}

void StockTree::display(StockTreeNode *ptr, int level) const{
	// ... for you to fill in
	// this displays the binary tree, sideways
	// that it, if you turn your head sideways, you'll see the
	// root at the leftmost side of the screen
	// the rightmost values will display near the top of the display
	// and the left most values will display near the bottom of the display
	// the node's "level" should control how far to the right the node's vaue is displayed
	// hint: use recursion!  The nodes children should have a level one greater than the node.
	//cout << endl;
	if(ptr!=nullptr){

		display(ptr->getRight(),level+1);

		cout << endl;

		for(int i = 1; i < level; i++){
			cout << "\t";
		}
		//cout << "hello ";
		if(ptr==root){
			cout << "Root-->: ";
		}
		else{
			cout << "        ";
		}
		cout <<  ptr->getStockPtr()->getKey()<< endl;

		display(ptr->getLeft(), level+1);
		//cout << endl;
	}

}

bool StockTree::remove(string key){
	// ... for you to fill in

	// many cases to consider!
	//  - the tree is empty
	//  - the tree does not contain the key
	//  - the node to be removed is the root (and has no children, 1 child, 2 children)
	//  - the node to be removed is not the root (and has no children, 1 child, 2 children)
	// the RemoveTester programs will help you try out most of the possibilites
	// hint: use find!
	StockTreeNode* removeNode = find(key);

	if(root==nullptr){ //  - the tree is empty
		//do nothing
		return false; //???
	}
	else if(removeNode->getStockPtr()->getKey()!=key){ //  - the tree does not contain the key  --> if find() gives us the would-be parent
		//do nothing
		return false;
	}
	else if(removeNode==root){//  - the node to be removed is the root...
		if((removeNode->getLeft()==nullptr) && (removeNode->getRight()==nullptr)){// ...and has no children
			root=nullptr;

			//delete removeNode->getStockPtr(); //HERE IT IS
			delete removeNode;
			return true;
		}
		else if((removeNode->getLeft()!=nullptr) && (removeNode->getRight()!=nullptr)){// ...and has 2 children
			StockTreeNode* cursor = removeNode->getLeft(); //the new root value -- and the tbd node
			while(cursor->getRight()!=nullptr){
				cursor = cursor->getRight();
			}

			removeNode->setStockPtr(cursor->getStockPtr()); //copy the content of the new root (cursor) to the current root (removeNode)

			if(cursor->getLeft()!=nullptr){	 //if cursor has a left child, then make that child take cursor's old place
				cursor->getLeft()->setParent(cursor->getParent()); //change the child's parent pointer to point to cursor's parent

				if(cursor->getParent()->getRight() == cursor){ //if cursor is its parent's right pointer, then make its child the new right pointer
					cursor->getParent()->setRight(cursor->getLeft());
				}
				else if(cursor->getParent()->getLeft() == cursor){
					cursor->getParent()->setLeft(cursor->getLeft());//if cursor is its parent's left pointer, then make its child the new left pointer
				}
			}
			else{ //if cursor has no children
				if(cursor->getParent()->getRight() == cursor){ //if cursor is its parent's right pointer
					cursor->getParent()->setRight(nullptr);
				}
				else if(cursor->getParent()->getLeft() == cursor){
					cursor->getParent()->setLeft(nullptr);//if cursor is its parent's left pointer
				}
			}

			//delete cursor->getStockPtr(); //HERE IT IS
			delete cursor;
			return true;
		}
		else{// ...and has 1 child
			if(removeNode->getLeft()!=nullptr){//it has a left child
				removeNode->getLeft()->setParent(nullptr);
				root = removeNode->getLeft();

				//delete removeNode->getStockPtr(); //HERE IT IS
				delete removeNode;
				return true;
			}
			else{//it has a right child
				removeNode->getRight()->setParent(nullptr);
				root = removeNode->getRight();

				delete removeNode->getStockPtr(); //HERE IT IS
				delete removeNode;
				return true;
			}


		}
	}
	else{//  - the node to be removed is not the root...
		if((removeNode->getLeft()==nullptr) && (removeNode->getRight()==nullptr)){// ...and has no children
			if(removeNode->getStock() > removeNode->getParent()->getStock()){//if it is its parent's right child
				removeNode->getParent()->setRight(nullptr);
			}
			else{
				removeNode->getParent()->setLeft(nullptr);
			}

			//delete removeNode->getStockPtr(); //HERE IT IS
			delete removeNode;
			return true;
		}
		else if((removeNode->getLeft()!=nullptr) && (removeNode->getRight()!=nullptr)){// ... and it has 2 children
			StockTreeNode* cursor = removeNode->getLeft(); //the new value of the internal node -- and the tbd node
			while(cursor->getRight()!=nullptr){
				cursor = cursor->getRight();
			}

			removeNode->setStockPtr(cursor->getStockPtr()); //copy the content of the new root (cursor) to removeNode

			if(cursor->getLeft()!=nullptr){	 //if cursor has a left child, then make that child take cursor's old place
				cursor->getLeft()->setParent(cursor->getParent()); //change the child's parent pointer to point to cursor's parent

				if(cursor->getParent()->getStock() < cursor->getStock()){ //if cursor is its parent's right pointer, then make its child the new right pointer
					cursor->getParent()->setRight(cursor->getLeft());
				}
				else{
					cursor->getParent()->setLeft(cursor->getLeft());//if cursor is its parent's left pointer, then make its child the new left pointer
				}
			}
			else{ //if cursor has no children
				if(cursor->getParent()->getStock() < cursor->getStock()){ //if cursor is its parent's right pointer
					cursor->getParent()->setRight(nullptr);
				}
				else{
					cursor->getParent()->setLeft(nullptr);//if cursor is its parent's left pointer
				}
			}

			//delete cursor->getStockPtr(); //HERE IT IS
			delete cursor;
			return true;
		}
		else{// ... and it has ! child
			if(removeNode->getLeft()!=nullptr){//it has a left child
				removeNode->getLeft()->setParent(removeNode->getParent());

				if(removeNode->getParent()->getStock() < removeNode->getStock()){//if removeNode is its parent's right pointer
					removeNode->getParent()->setRight(removeNode->getLeft());
				}
				else{//if removeNode is its parent's left pointer
					removeNode->getParent()->setLeft(removeNode->getLeft());
				}

				//delete removeNode->getStockPtr(); //HERE IT IS
				delete removeNode;
				return true;
			}
			else{//it has a right child
				removeNode->getRight()->setParent(removeNode->getParent());

				if(removeNode->getParent()->getStock() < removeNode->getStock()){//if removeNode is its parent's right pointer
					removeNode->getParent()->setRight(removeNode->getRight());
				}
				else{//if removeNode is its parent's left pointer
					removeNode->getParent()->setLeft(removeNode->getRight());
				}

				//delete removeNode->getStockPtr(); //HERE IT IS
				delete removeNode;
				return true;
		}
	}


	//return true;//delete later--------------------------
	}
}

void StockTree::remove(Stock * val){
	// use the current stock's key to call the other remove method
	remove(val->getKey());
}

bool StockTree::contains(const string key) const{
	// ... for you to fill in
	// return false if the key is not in the tree
	// otherwise return true
 if(find(key)!=nullptr){ //tree is not empty
	 if(find(key)->getStockPtr()->getKey() == key){ //find() found that exact key value in the tree
 		return true;
 	}
 }
 return false;

 /*
 if(find(key)==nullptr){ //if the tree is empty
		return false;
	}
	else if(find(key)->getStockPtr()->getKey() == key){ //find() found that exact key value in the tree
		return true;
	}
	else{ //find() found the parent of that key value
		return false;
	}
	*/
}

bool StockTree::contains(Stock * val) const{
	// ... for you to fill in
	// return false if val's key is not in the tree
	// otherwise return true
	// can just invoke contains using val's key value

	return contains(val->getKey());
}


void StockTree::displayItemsInOrder() const{
	// ... for you to fill in
	// this method is invoked on the stocktree
	// display "Empty" if empty
	// otherwise, call inOrder, passing root as a parameter
	// and a blank line at the end

	if(root==nullptr){
		cout << "Empty";
	}
	else{
		inOrder(root);
	}

	cout << endl;
}

void StockTree::inOrder(StockTreeNode *v) const{
	// ... for you to fill in
	// if there's anything to display
	// - display the left subtree
	// - display node's key value
	// - display the right subtree

	//recursively invoke inOrder(left)
	//cout root
	//recursively invoke inOrder(right)

	if(v != nullptr){
		inOrder(v->getLeft());
		cout << v->getStockPtr()->getKey() << " "; //format
		inOrder(v->getRight());
	}

}

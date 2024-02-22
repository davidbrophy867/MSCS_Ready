#include "StockList.h"

StockList::StockList(){head = nullptr;}

StockList::~StockList(){
  StockNode* cursor = head;

  while(cursor!=nullptr){
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
}

StockNode* StockList::getHead() const{return head;}

void StockList::insert(Stock* sPtr){ //---------------------------
  if(!contains(sPtr)){
    StockNode* newNode = new StockNode(sPtr);
    StockNode* cursor = head;

    if(head==nullptr){ //checks to make sure list is not empty
      head = newNode;
    }
    else{               //if it is not empty
      while(cursor!=nullptr){
        if((cursor == head) && (cursor->getStock() > newNode->getStock())){ //if cursor == head and newNode goes before it
          newNode->setNext(cursor);
          head = newNode;
        }
        else if(cursor->getStock() < newNode->getStock()){ //if newNode goes some place after cursor

          if(cursor->getNext() != nullptr){ //if there is another node after cursor
            if(cursor->getNext()->getStock() > newNode->getStock()){//if newNode goes in between cursor and the next node
              //add newNode after cursor
              newNode->setNext(cursor->getNext()); //make n->next point to next nodes
              cursor->setNext(newNode);            //make prevnode->next point to n
            }
            /*else if(cursor->getNext()->getStock() < newNode->getStock()){//if newNode goes some place after the next node, repeat process
               //repeat loop
            }*/
          }
          else{ //if there is not another node after cursor
            //add newNode to the end of the list
            cursor->setNext(newNode);            //make prevnode->next point to n
          }

        }//

        cursor = cursor->getNext();
      }

    }
  }
}




void StockList::remove(Stock* sPtr){
  remove(sPtr->getKey());
}

void StockList::remove(string key){
  StockNode* thisNode = find(key);
  StockNode* cursor = head;

  if(thisNode == head){
    head = thisNode->getNext();
    delete thisNode;
  }
  else if(thisNode!=nullptr){
    while(cursor!=nullptr){
      if(cursor->getNext() == thisNode){
        cursor->setNext(thisNode->getNext());
        //do I need to call a destructor? //--------------------------------
        delete thisNode;
      }
      cursor = cursor->getNext();
    }
  }
}

StockNode* StockList::find(string key){
  StockNode* cursor = head;

  if(contains(key)){
    //is there a way to consolidate this loop with the contains function?
    while(cursor!=nullptr){
      if(cursor->getStockPtr()->getKey() == key){return cursor;}
      cursor = cursor->getNext();
    }
  }
  //else{
  return nullptr;
  //}
}

bool StockList::contains(Stock* sPtr){
  return contains(sPtr->getKey());
}

bool StockList::contains(string key){
    StockNode* cursor = head;

    while(cursor!=nullptr){
      if(cursor->getStockPtr()->getKey() == key){return true;}
      cursor = cursor->getNext();
    }

  return false;
}

void StockList::display(){
  StockNode* cursor = head;

  if(head == nullptr){
    cout << "empty list" << endl; //may need new line?
  }
  else{
    while(cursor!=nullptr){
      cout << cursor->getStock() << endl; //may need new line?
      cursor = cursor->getNext();
    }
    cout << endl;
  }

}

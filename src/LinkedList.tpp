#include "LinkedList.h"
#include <iostream>

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
   this->head = nullptr;
   this->tail = nullptr;
   this->count = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const T& value) {
   this->count = 1;
   this->head = new Node<T>(value);
   this->tail = head;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), count(0) {
    Node<T>* curr = other.head;
    while (curr) {
        push_back(curr->getData()); // Assuming Node has a proper copy mechanism
        curr = curr->getNext();
    }
}

// Assignment Operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
    if (this == &rhs) {
        return *this; // Handle self-assignment
    }

    clear(); // Clear existing data

    Node<T>* curr = rhs.head;
    while (curr) {
        push_back(curr->getData()); // Assuming Node has a proper copy mechanism
        curr = curr->getNext();
    }

    return *this;
}


template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = head;
   
    while (curr) {
        Node<T>* temp = curr;
        curr = curr->getNext();
      
        delete temp; // dealloc each consecutive node
    }
   
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <typename T> 
void LinkedList<T>::clear() {
   Node<T>* curr = head;
   
    while (curr) {
        Node<T>* temp = curr;
        curr = curr->getNext();
        delete temp;
    }

   head = nullptr;
   tail = nullptr;
   count = 0;
}

template <typename T>
bool LinkedList<T>::remove(const T& rmName) {
   Node<T>* curr = this->getHead();
   
   while (curr) {
      if (curr->getData().getName() == rmName.getName()) {   
         this->remove(curr);
         cout << rmName.getName() << " has been deleted." << endl;
         
         return true;
      }
      curr = curr->getNext();
   }

   return false;
}

template <typename T>
void LinkedList<T>::remove(Node<T>* rmNode) {
   Node<T>* toDelete = rmNode;

   if (rmNode == head) {         // DELETE HEAD
      this->setHead(rmNode->getNext());
           
      if (this->head != nullptr) {
         (this->head)->setPrev(nullptr);
      } else {
         this->setTail(nullptr); // creates empty list after deletion 
      }
   }   
   else if (rmNode == this->tail) {    // DELETE TAIL
      this->setTail(rmNode->getPrev());
            
      if (this->tail != nullptr) {
         (this->tail)->setNext(nullptr);
      } 
   }    
   else {                              // DELETE MIDDLE
      Node<T>* prevNode = rmNode->getPrev();
      Node<T>* nextNode = rmNode->getNext();
      if (prevNode) { prevNode->setNext(nextNode); }
      if (nextNode) { nextNode->setPrev(prevNode); }
   }

   rmNode = rmNode->getNext(); // move to next before deleting
   delete toDelete;
   count--;
}

template <typename T>
void LinkedList<T>::mergeSort() {
   if (this->count <= 1) {
      return;
   }
   
   mergeSort(this);
}

template <typename T>
void LinkedList<T>::mergeLists(LinkedList<T>* listB) {
   Node<T>* currA = this->head;
   Node<T>* currB = listB->head;

   Node<T>* mergedHead = nullptr;
   Node<T>* mergedTail = nullptr;
   int newCount = 0;

   while (currA != nullptr && currB != nullptr) {
      Node<T>* nextA = currA->getNext();
      Node<T>* nextB = currB->getNext();

      if (*currA < *currB) {       // inserting currA first
         currA->setPrev(nullptr);
         currA->setNext(nullptr);

         if (mergedHead == nullptr) { // merging to empty list
            mergedHead = mergedTail = currA;
         } 
         else {
            mergedTail->setNext(currA);
            currA->setPrev(mergedTail);
            
            mergedTail = currA;
         }

         newCount++;
         currA = nextA;
      }

      else if (*currA > *currB) {  // inserting currB first
         currB->setPrev(nullptr);
         currB->setNext(nullptr);

         if (mergedHead == nullptr) {        // merging to empty list
            mergedHead = mergedTail = currB;
         }
         else {
            mergedTail->setNext(currB);
            currB->setPrev(mergedTail);
            
            mergedTail = currB;
         }

         newCount++;
         currB = nextB;
      }

      else {                      // for duplicate word; keep currA & delete currB
         currA->setPrev(nullptr);
         currA->setNext(nullptr);

         if (mergedHead == nullptr) {        // merging to empty list
            mergedHead = mergedTail = currA;
         } 
         else {
            mergedTail->setNext(currA);
            currA->setPrev(mergedTail);
            
            mergedTail = currA;
         }

         newCount++;
         delete currB;
         
         currA = nextA;
         currB = nextB;
      }
   } // end 1st while()

   while (currA != nullptr) {       // append all remaining nodes from listA
      Node<T>* next = currA->getNext();

      currA->setPrev(nullptr);
      currA->setNext(nullptr);

      if (mergedHead == nullptr) {        // merging to empty list
         mergedHead = mergedTail = currA;
      } 
      else {
         mergedTail->setNext(currA);
         currA->setPrev(mergedTail);
         
         mergedTail = currA;
      }

      newCount++;
      currA = next;
   }

   while (currB != nullptr) {      // append all remaining nodes from listB
     Node<T>* next = currB->getNext();

      currB->setPrev(nullptr);
      currB->setNext(nullptr);

      if (mergedHead == nullptr) {        // merging to empty list
         mergedHead = mergedTail = currB;
      } 
      else {
         mergedTail->setNext(currB);
         currB->setPrev(mergedTail);
         
         mergedTail = currB;
      }

      newCount++;
      currB = next;
   }

   // setting new head, tail, and size for listA
   this->head = mergedHead;
   this->tail = mergedTail;
   this->count = newCount;

   // clearing listB
   listB->head = nullptr;
   listB->tail = nullptr;
   listB->count = 0;
}

template <typename T>
void LinkedList<T>::mergeSort(LinkedList<T>* topListPtr) {
   if (topListPtr->count <= 1) {
      return;
   }
   
   LinkedList<T>* left = new LinkedList<T>();
   LinkedList<T>* right = new LinkedList<T>();
   int midPt = topListPtr->count / 2;
   
   Node<T>* curr = topListPtr->getHead();
   
   for (int i = 0; i < midPt; i++) {     // populating left side
      Node<T>* next = curr->getNext();
      curr->setPrev(nullptr);
      curr->setNext(nullptr);
      
      left->push_back(curr);
      
      curr = next;
   }
   
   while (curr) {                      // populating right side
      Node<T>* next = curr->getNext();
      curr->setPrev(nullptr);
      curr->setNext(nullptr);
      
      right->push_back(curr);
      
      curr = next;
   }
   
   mergeSort(left);
   mergeSort(right);
   
   topListPtr->head = nullptr;
   topListPtr->tail = nullptr;
   topListPtr->count = 0;
   
   // append all sorted nodes ...
   topListPtr->mergeLists(left);   
   topListPtr->mergeLists(right);
   
   delete left;
   delete right;
}

template <typename T>
Node<T>* LinkedList<T>::insert_before(const T& value, Node<T>* knownNode) {
   Node<T>* toInsert = new Node<T>(value);
   
   if (knownNode == this->head) {
      this->head = toInsert;
   } else {
      toInsert->setPrev(knownNode->prev);
      (knownNode->prev)->setNext(toInsert);
   }

   toInsert->setNext(knownNode);
   knownNode->setPrev(toInsert);
   
   this->count++;
   return toInsert;
}

template <typename T>
void LinkedList<T>::push_back(const T& value) {
   this->push_back(new Node<T>(value));
}
template <typename T>
void LinkedList<T>::push_back(Node<T>* addNode) {
   if (this->tail == nullptr) { // if empty list
      this->head = addNode;
      this->tail = addNode;
      
      addNode->setPrev(nullptr);
      addNode->setNext(nullptr);
   }
   else {
      addNode->setPrev(this->tail);
      addNode->setNext(nullptr);
      
      this->tail->setNext(addNode);
      this->setTail(addNode);
   }

   count++;
}

// GETTERS
template <typename T>
int LinkedList<T>::size() const { return count; }
template <typename T>
Node<T>* LinkedList<T>::getHead() const { return head; }
template <typename T>
Node<T>* LinkedList<T>::getTail() const { return tail; }

template <typename T>
Node<T>* LinkedList<T>::search(const T& value) const {

   Node<T>* curr = this->head;
   if(curr == nullptr) {
      cout << "list empty" << endl;
      return nullptr;
   }
   
   while (curr) {
      if (curr->getData().getName() == value.getName()) {
         return curr;
      }
      curr = curr->getNext();
   }
   
   return nullptr;
}

// search using name (str)
template <typename T>
Node<T>* LinkedList<T>::search(const string str) const {
   Node<T>* curr = this->head;
   if(curr == nullptr) {
      cout << "list empty" << endl;
      return nullptr;
   }
   
   while (curr != nullptr) {
      if (curr->getData().getName() == str) {
         return curr;
      }
      curr = curr->getNext();
   }
   
   return nullptr;
}

// SETTERS
template <typename T>
void LinkedList<T>::setHead (Node<T>* newHead) {
   this->head = newHead;
}
template <typename T>
void LinkedList<T>::setTail (Node<T>* newTail) {
   this->tail = newTail;
}

template <typename T>
void LinkedList<T>::print(bool reverse) { 
   Node<T>* curr = this->head;
   
   if (reverse) {
      curr = this->tail;
      while (curr) {
         cout << curr->getData().getName() << ", ";
         curr = curr->getPrev();
      }
   }
   else {
      while (curr) {
         cout << curr->getData().getName() << ", ";
         curr = curr->getNext();
      }
   }
   cout << endl;
}

template <typename T>
void to_json(nlohmann::json &j, const LinkedList<T> &ll)
{
   Node<T> *curr = ll.getHead();
   while (curr)
   {
      j.push_back(*curr);
      curr = curr->getNext();
   }
}

template <typename T>
void from_json(const nlohmann::json &j, LinkedList<T> &ll)
{
   Node<T> node;
   for (unsigned int i = 0; i < j.size(); ++i)
   {
      node = j.at(i).template get<Node<T>>();
      ll.push_back(node.getData()); // FIXME: This is making new nodes twice.
                                    // Removing .getData() causes memory issues
   }
}

template <typename T>
void to_json(nlohmann::json &j, const LinkedList<T> *ll) {
   to_json(j, *ll);
}
template <typename T>
void from_json(const nlohmann::json &j, LinkedList<T> *ll) {
   from_json(j, *ll);
}

template <typename T>
ostream& operator<<(ostream &os, const LinkedList<T> &toPrint) {
   Node<T>* temp = toPrint.getHead();
   while(temp) {
      os << temp->getData();
      if(temp->getNext() != nullptr) { os << ", "; }
      temp = temp->getNext();
   }
   return os;
}
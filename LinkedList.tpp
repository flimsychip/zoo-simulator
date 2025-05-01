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
   this->head = new Node<T>(word);
   this->tail = head;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = head;
   
    while (curr) {
        Node<T>* temp = curr;
        curr = curr->next;
      
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
        curr = curr->next;
        delete temp;
    }

   head = nullptr;
   tail = nullptr;
   count = 0;
}

template <typename T>
void LinkedList<T>::remove(Node<T>* rmNode) {
        Node<T>* toDelete = curr;

        if (curr == this->head) {        // DELETE HEAD
            this->setHead(curr->next);
            
            if (this->head != nullptr) {
               (this->head)->setPrev(nullptr);
            } else {
                this->setTail(nullptr); // creates empty list after deletion 
            }
        }
         
        else if (curr == this->tail) {   // DELETE TAIL
            this->setTail(curr->prev);
            
            if (this->tail != nullptr) {
               (this->tail)->setNext(nullptr);
            } 
        } 
         
        else {                     // DELETE MIDDLE
            (curr->prev)->setNext(curr->next);
            (curr->next)->setPrev(curr->prev);
        }

        curr = curr->next; // move to next before deleting
         delete toDelete;
         count--;
}
   
/*template <typename T>
void LinkedList<T>::mergeDicts(LinkedList<T>* listB) {  // JUST IN CASE; MERGING 2 LISTS IN ALPHA ORDER
   Node* currA = this->head;
   Node* currB = listB->head;

   Node* mergedHead = nullptr;
   Node* mergedTail = nullptr;
   int newCount = 0;

   while (currA != nullptr && currB != nullptr) {
      Node* nextA = currA->getNext();
      Node* nextB = currB->getNext();

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
     Node* next = currB->getNext();

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
}*/

template <typename T>
void LinkedList<T>::mergeSort() {
   if (this->count <= 1) {
      return;
   }
   
   mergeSort(this);
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
   topListPtr->mergeDicts(left);   
   topListPtr->mergeDicts(right);
   
   delete left;
   delete right;
}

template <typename T>
Node<T>* LinkedList<T>::insert_before(const std::string& data, Node<T>* knownNode) {
   Node<T>* toInsert = new Node<T>(data);
   
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
void LinkedList<T>::push_back(const std::string& value) {
   Node<T>* newNode = new Node<T>(word);
   if (!head) {
      head = tail = newNode;
   }
   else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
   }
   
   count++;
}
template <typename T>
void LinkedList<T>::push_back(Node<T>* addNode) {
   if (this->tail == nullptr) { // if empty list
      this->head = this->tail = addNode;
      
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

/*
void LinkedList::operator+= (LinkedList& list2) {
   // head of list2 now points to tail of [this]
   if (list2.head == nullptr) { return; } // nothing to add

   Node* list2Head = list2.head;

   if (this->tail == nullptr) {
      // this list is empty — adopt list2 directly
      this->head = list2Head;
      this->tail = list2.tail;
   } else {
      // link this list's tail to list2's head
      this->tail->setNext(list2Head);
      list2Head->setPrev(this->tail);
      this->tail = list2.tail;
   }

   this->count += list2.size();

   // clear list2 without deleting nodes
   list2.setHead(nullptr);
   list2.setTail(nullptr);
   list2.count = 0;
}
*/

// GETTERS
template <typename T>
int LinkedList<T>::size() const { return count; }
template <typename T>
Node<T>* LinkedList<T>::getHead() const { return head; }
template <typename T>
Node<T>* LinkedList<T>::getTail() const { return tail; }

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
void LinkedList<T>::print(bool reverse) const { 
   Node<T>* curr = head;
   
   if (reverse) {
      curr = tail;
      while (curr) {
         cout << curr->getData() << endl;
         curr = curr->prev;
      }
   }
   else {
      while (curr) {
         cout << curr->getData() << endl;
         curr = curr->next;
      }
   }
}

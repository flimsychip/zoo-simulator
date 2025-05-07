/* 
COPY-PASTE FROM LAB
CHANGE TO FIT NODE.TPP
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
struct LinkedList {
   template<typename U> //
   friend struct Node; // FIXME: replace 
   public:
      LinkedList();
      LinkedList(const T& value);
      // FIXME: Rule of three: missing assignment operator and copy constructor
        
      LinkedList(const LinkedList<T>& other);            // Copy constructor
      LinkedList<T>& operator=(const LinkedList<T>& rhs); // Copy assignment
      
      ~LinkedList();
      
      void push_back(const T& value);
      void push_back(Node<T>* addNode);
      Node<T>* insert_before(const T& value, Node<T>* knownNode);

      void mergeLists(LinkedList<T>* listB);
      void mergeSort(LinkedList<T>* topListPtr);
      void mergeSort();

      bool remove(const T& rmName);
      void remove(Node<T>* rmNode);
      void clear();
      
      // Getters
      int size() const;
      Node<T>* getHead() const;
      Node<T>* getTail() const;

      // Setters
      void setTail(Node<T> *newTail);
      void setHead(Node<T> *newHead);
      
      void print(bool reverse = false);
      
   private:
      // Members
      int count;
      Node<T>* head;
      Node<T>* tail;
};

#include "LinkedList.tpp"
#endif
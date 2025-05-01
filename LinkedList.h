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
   public:
      LinkedList();
      LinkedList(const T& value);
      // FIXME: Rule of three: missing assignment operator and copy constructor
      
      ~LinkedList();
      
      void push_back(const std::string& value);
      void push_back(Node<T>* addNode);
      Node<T>* insert_before(const std::string& data, Node<T>* knownNode);

      void mergeSort(LinkedList<T>* topListPtr);
      void mergeSort();

      void remove(const T& rmValue);
      void remove(Node<T>* rmNode);
      void clear();
      
      // Getters
      int size() const;
      Node<T>* getHead() const;
      Node<T>* getTail() const;
      
      void print(bool reverse = false) const;
      
   private:
      // Members
      int count;
      Node<T>* head;
      Node<T>* tail;

      // Setters
      void setTail(Node<T> *newTail);
      void setHead(Node<T> *newHead);
};

#include "LinkedList.tpp"
#endif
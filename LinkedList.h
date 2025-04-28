/* 
COPY-PASTE FROM LAB
CHANGE TO FIT NODE.TPP
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <string>

template <typename T>
struct LinkedList {
   public:
      LinkedList();
      LinkedList(const std::string& word);
      
      ~LinkedList();
      
      void deleteWord(Node<T>* curr);
      void push_back(const std::string& word);
      Node<T>* insert_before (std::string addWord, Node<T>* knownNode);
      void clear();
      
      int size() const;
      Node<T>* getHead() const;
      Node<T>* getTail() const;
      
      void setTail(Node<T>* newTail);
      void setHead(Node<T>* newHead);
      
      void print(bool reverse = false) const;
      
   private:
      int count;
      Node<T>* head;
      Node<T>* tail;
};

#endif
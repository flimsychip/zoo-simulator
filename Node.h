/*
COPY-PASTE OF NODE.H
CHANGE TO TEMPLATE CLASS
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

template <typename T> 
struct Node {
   private:
      std::string name;
      Node<T>* next;
      Node<T>* prev;
      
   public:
      Node(const std::string& word);
      Node();
      
      void setData(const std::string& word);
      void setNext(Node<T>* node);
      void setPrev(Node<T>* node);
      
      std::string getData() const;
      Node<T>* getNext() const;
      Node<T>* getPrev() const;
};

// OPERATORS: ==, <, >, <=, >=, and !=
template <typename T>
bool operator==(const T& lhs, const T& rhs);

template <typename T>
bool operator!=(const T& lhs, const T& rhs);

template <typename T>
bool operator<(const T& lhs, const T& rhs);

template <typename T>
bool operator>(const T& lhs, const T& rhs);

template <typename T>
bool operator<=(const T& lhs, const T& rhs);

template <typename T>
bool operator>=(const T& lhs, const T& rhs);

#include "Node.tpp"

#endif
/*
COPY-PASTE OF NODE.H
CHANGE TO TEMPLATE CLASS
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T> 
struct Node {
   private:
      T data;
      Node<T>* next;
      Node<T>* prev;
      
   public:
      Node(const T& value);
      Node();
      
      void setName(const T& value);
      void setNext(Node<T>* node);
      void setPrev(Node<T>* node);
      
      T getName() const;
      Node<T>* getNext() const;
      Node<T>* getPrev() const;

      template<typename U> 
      friend struct LinkedList;
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
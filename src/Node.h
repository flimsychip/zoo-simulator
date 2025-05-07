/*
COPY-PASTE OF NODE.H
CHANGE TO TEMPLATE CLASS
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T> 
struct Node {
   private:    // FIXME: change to protected?
      T data;
      Node<T>* next;
      Node<T>* prev;
      
   public:
      Node();
      Node(const T& value);
      
      void setName(const T& value);
      void setNext(Node<T>* node);
      void setPrev(Node<T>* node);
      
      T getName() const;
      Node<T>* getNext() const;
      Node<T>* getPrev() const;

      template <typename U>
      friend struct LinkedList;  // FIXME: change LL.tpp and others so this is no longer necessary
};

// OPERATORS: ==, <, >, <=, >=, and !=
template <typename T>
bool operator==(const Node<T>& lhs, const Node<T>& rhs);

template <typename T>
bool operator!=(const Node<T>& lhs, const Node<T>& rhs);

template <typename T>
bool operator<(const Node<T>& lhs, const Node<T>& rhs);

template <typename T>
bool operator>(const Node<T>& lhs, const Node<T>& rhs);

template <typename T>
bool operator<=(const Node<T>& lhs, const Node<T>& rhs);

template <typename T>
bool operator>=(const Node<T>& lhs, const Node<T>& rhs);

#include "Node.tpp"
#endif
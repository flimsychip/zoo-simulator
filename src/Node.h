#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "../deps/nlohmann/json.hpp"

template <typename T> 
struct Node {
   private: 
      T data;
      Node<T>* next;
      Node<T>* prev;
      
   public:
      Node();
      Node(const T& value);
      Node(const Node<T>& copyNode);
      
      void setData(const T& value);
      void setNext(Node<T>* node);
      void setPrev(Node<T>* node);
      
      T& getData(); // sometimes we be modify :shrug:
      const T& getData() const; // needed bc other const funcs call getData()
      Node<T>* getNext() const;
      Node<T>* getPrev() const;
      
      // MACRO to convert/actuate object to/from json
      NLOHMANN_DEFINE_TYPE_INTRUSIVE(Node, data)
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

template<typename T>
std::ostream& operator<<(std::ostream& os, const Node<T>& toPrint);

#include "Node.tpp"
#endif
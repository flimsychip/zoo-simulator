/*
COPY-PASTE OF NODE.H
CHANGE TO TEMPLATE CLASS
*/

#ifndef NODE_H
#define NODE_H

// #include <iostream>
//#include <string>

template <typename T, typename Tstr> 
struct Node {
   private:
      //std::string data;
      Tstr name;
      Node<T>* next;
      Node<T>* prev;
      
   public:
      Node(const Tstr& word);
      Node();
      
      void setData(const Tstr& word);
      void setNext(Node<T>* node);
      void setPrev(Node<T>* node);
      
      Tstr getData() const;
      Node<T>* getNext() const;
      Node<T>* getPrev() const;
      
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

#endif
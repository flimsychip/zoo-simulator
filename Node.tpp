/*
COPY-PASTE OF NODE.H
CHANGE TO TEMPLATE CLASS
*/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

struct Node {
   private:
      std::string data;
      Node* next;
      Node* prev;
      
   public:
      Node(const std::string& word);
      Node();
      
      void setData(const std::string& word);
      void setNext(Node* node);
      void setPrev(Node* node);
      
      std::string getData() const;
      Node* getNext() const;
      Node* getPrev() const;
      
      friend struct LinkedList;
};

// OPERATORS: ==, <, >, <=, >=, and !=
bool operator==(const Node& lhs, const Node& rhs);
bool operator!=(const Node& lhs, const Node& rhs);

bool operator<(const Node& lhs, const Node& rhs);
bool operator>(const Node& lhs, const Node& rhs);

bool operator<=(const Node& lhs, const Node& rhs);
bool operator>=(const Node& lhs, const Node& rhs);

#endif
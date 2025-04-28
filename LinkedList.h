/* 
COPY-PASTE FROM LAB
CHANGE TO FIT NODE.TPP
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.tpp"
#include <string>

struct LinkedList {
   public:
      LinkedList();
      LinkedList(const std::string& word);
      
      ~LinkedList();
      
      void deleteWord(Node* curr);
      void push_back(const std::string& word);
      Node* insert_before (std::string addWord, Node* knownNode);
      void clear();
      
      int size() const;
      Node* getHead() const;
      Node* getTail() const;
      
      void setTail(Node* newTail);
      void setHead(Node* newHead);
      
      void print(bool reverse = false) const;
      
   private:
      int count;
      Node* head;
      Node* tail;
};

#endif
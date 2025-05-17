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

      Node<T>* search(const T& value) const; // linear search
      Node<T>* search(const string str) const;

      // Setters
      void setTail(Node<T> *newTail);
      void setHead(Node<T> *newHead);
      
      void print(bool reverse = false);

   private:
      // Members
      Node<T>* head;
      Node<T>* tail;
      int count;
};

// THESE COULD HAVE BEEN FRIENDS. god I should have realized
template <typename T>
void to_json(nlohmann::json &j, const LinkedList<T> &ll);
template <typename T>
void from_json(const nlohmann::json &j, LinkedList<T> &ll);
template <typename T>
// Overloaded with pointers as well
void to_json(nlohmann::json &j, const LinkedList<T> *ll);
template <typename T>
void from_json(const nlohmann::json &j, LinkedList<T> *ll);

template <typename T>
ostream& operator<<(ostream &os, const LinkedList<T> &toPrint);

#include "LinkedList.tpp"
#endif
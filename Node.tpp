#pragma once   // prevent 'overlap' of libraries
#include "Node.h"

using namespace std;

template <typename T>
Node<T>::Node() {
   this->next = nullptr;
   this->prev = nullptr;
}
template <typename T>
Node<T>::Node(const T& value) {
   this->data = value;
   this->next = nullptr;
   this->prev = nullptr;
}

// SETTERS
template <typename T>
void Node<T>::setName(const T& value) { this->data = value; }
template <typename T>
void Node<T>::setNext(Node<T>* node) { this->next = node; }
template <typename T>
void Node<T>::setPrev(Node<T>* node) { this->prev = node; }

// GETTERS
template <typename T>
T Node<T>::getName() const { return data; }
template <typename T>
Node<T>* Node<T>::getNext() const { return next; }
template <typename T>
Node<T>* Node<T>::getPrev() const { return prev; }


// OPERATORS: ==, <, >, <=, >=, and !=
template <typename T>
bool operator==(const Node<T>& lhs, const Node<T>& rhs) {
   return lhs.getData() == rhs.getData();
}
template <typename T>
bool operator!=(const Node<T>& lhs, const Node<T>& rhs) {
   return !(lhs == rhs);
}
template <typename T>
bool operator<(const Node<T>& lhs, const Node<T>& rhs) {
   return lhs.getData() < rhs.getData();
}
template <typename T>
bool operator>(const Node<T>& lhs, const Node<T>& rhs) {
   return lhs.getData() > rhs.getData();
}
template <typename T>
bool operator<=(const Node<T>& lhs, const Node<T>& rhs) {
   return !(lhs > rhs);
}
template <typename T>
bool operator>=(const Node<T>& lhs, const Node<T>& rhs) {
   return !(lhs < rhs);
}


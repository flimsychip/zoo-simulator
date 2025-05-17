#pragma once   // prevent 'overlap' of libraries
#include "Node.h"

using namespace std;

template <typename T>
Node<T>::Node() {
   // FIXME: this->data does not have a default value. Can accidentally access invalid memory
   this->next = nullptr;
   this->prev = nullptr;
}
template <typename T>
Node<T>::Node(const T& value) {
   this->data = value;
   this->next = nullptr;
   this->prev = nullptr;
}

template<typename T>
Node<T>::Node(const Node<T>& copyNode) {
   this->data = copyNode.getData();
   this->next = copyNode.getNext();
   this->prev = copyNode.getPrev();
}

// SETTERS
template <typename T>
void Node<T>::setData(const T& value) {
   this->data = value;
}
template <typename T>
void Node<T>::setNext(Node<T>* node) { this->next = node; }
template <typename T>
void Node<T>::setPrev(Node<T>* node) { this->prev = node; }

// GETTERS
template <typename T>
T& Node<T>::getData() { return this->data; }
template <typename T>
const T& Node<T>::getData() const { return this->data; }
template <typename T>
Node<T>* Node<T>::getNext() const { return next; }
template <typename T>
Node<T>* Node<T>::getPrev() const { return prev; }


// OPERATORS: ==, <, >, <=, >=, and !=
template <typename T>
bool operator==(const Node<T>& lhs, const Node<T>& rhs) {
   return lhs.getData().getName() == rhs.getData().getName();
}
template <typename T>
bool operator!=(const Node<T>& lhs, const Node<T>& rhs) {
   return !(lhs == rhs);
}
template <typename T>
bool operator<(const Node<T>& lhs, const Node<T>& rhs) {
   return lhs.getData().getName() < rhs.getData().getName();
}
template <typename T>
bool operator>(const Node<T>& lhs, const Node<T>& rhs) {
   return lhs.getData().getName() > rhs.getData().getName();
}
template <typename T>
bool operator<=(const Node<T>& lhs, const Node<T>& rhs) {
   return !(lhs > rhs);
}
template <typename T>
bool operator>=(const Node<T>& lhs, const Node<T>& rhs) {
   return !(lhs < rhs);
}

template<typename T>
ostream& operator<<(ostream& os, const Node<T>& toPrint) {
   os << toPrint.getData();
   return os;
}
#ifndef linkedlist
#define linkedlist

#include <iostream>
#include <vector>
using namespace std;

namespace LinkedList {
/**
    A Node Class
*/
template <class T> class Node {
public:
  Node<T> *next;
  T value;
  Node(T &value) {
    this->value = value;
    this->next = nullptr;
  }
};

/**
Linked List Class
*/
template <class T> class LinkedList {
public:
  Node<T> *head;
  LinkedList() { this->head = nullptr; }
  ~LinkedList() {
    // Delete All Nodes
    Node<T> *current = head;
    while (current != nullptr) {
      Node<T> *temp = current;
      current = current->next;
      delete temp;
    }
  }
  void printList() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      if (temp->next != nullptr) {
        cout << temp->value << "->";
      } else {
        cout << temp->value << endl;
      }
      temp = temp->next;
    }
    delete temp;
  }
  int totalListItems() {
    uint count = 0;
    Node<T> *temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->next;
    }
    delete temp;
    return count;
  }
  void insertNode(Node<T> *node) {
    if (this->head == nullptr) {
      this->head = node;
      return;
    }
    // Insert it at end
    Node<T> *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = node;
    return;
  }
  vector<uint> findNodesPositionWithValues(T &findValue) {
    vector<uint> foundPositions;
    Node<T> *temp = head;
    uint position = 0;
    while (temp != nullptr) {
      position++;
      if (temp->value == findValue) {
        foundPositions.push_back(position);
      }
    }
    delete temp;
    return foundPositions;
  }
};
}

#endif // MY_HEADER_FILE_H
/*
	LinkedList.h - V1.1 - Generic LinkedList implementation
	Works better with FIFO, because LIFO will need to
	search the entire List to find the last one;

	For instructions, go to https://github.com/ivanseidel/LinkedList

	Created by Ivan Seidel Gomes, March, 2013.
	Released into the public domain.
*/

#ifndef DLinkedList_h
#define DLinkedList_h

#include <stddef.h>

template <class T>
struct DListNode {
    T data;
    DListNode<T>* next;
};

template <typename T>
class DLinkedList {
protected:
    int _size;
    DListNode<T>* root;
    DListNode<T>* last;

    DListNode<T>* getNode(int index);

public:
    DLinkedList();
    ~DLinkedList();

    int size() const;
    bool add(int index, T value);
    bool add(T value);
    bool unshift(T value);
    bool set(int index, T value);
    T remove(int index);
    T pop();
    T shift();
    T get(int index);
    void clear();
};

// Initialize LinkedList with default values
template <typename T>
DLinkedList<T>::DLinkedList() : _size(0), root(NULL), last(NULL) {}

// Clear Nodes and free Memory
template <typename T>
DLinkedList<T>::~DLinkedList() {
    clear();
}

// Get node at specific index
template <typename T>
DListNode<T>* DLinkedList<T>::getNode(int index) {
    if (index < 0 || index >= _size) return NULL;
    DListNode<T>* current = root;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

template <typename T>
int DLinkedList<T>::size() const {
    return _size;
}

// Add a node at the specific index
template <typename T>
bool DLinkedList<T>::add(int index, T value) {
    if (index < 0 || index > _size) return false;
    if (index == 0) return unshift(value);
    if (index == _size) return add(value);

    DListNode<T>* prevNode = getNode(index - 1);
    if (!prevNode) return false;

    DListNode<T>* newNode = new DListNode<T>;
    newNode->data = value;
    newNode->next = prevNode->next;

    prevNode->next = newNode;

    _size++;
    return true;
}

// Add a node at the end
template <typename T>
bool DLinkedList<T>::add(T value) {
    DListNode<T>* newNode = new DListNode<T>;
    newNode->data = value;
    newNode->next = NULL;

    if (last) {
        last->next = newNode;
    } else {
        root = newNode;
    }
    last = newNode;
    _size++;
    return true;
}

// Add a node at the beginning
template <typename T>
bool DLinkedList<T>::unshift(T value) {
    DListNode<T>* newNode = new DListNode<T>;
    newNode->data = value;
    newNode->next = root;

    root = newNode;
    if (_size == 0) last = newNode;
    _size++;
    return true;
}

// Set a node's value at the specific index
template <typename T>
bool DLinkedList<T>::set(int index, T value) {
    DListNode<T>* node = getNode(index);
    if (!node) return false;
    node->data = value;
    return true;
}

// Remove a node at the specific index
template <typename T>
T DLinkedList<T>::remove(int index) {
    if (index < 0 || index >= _size) return T();
    if (index == 0) return shift();

    DListNode<T>* prevNode = getNode(index - 1);
    DListNode<T>* nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    if (nodeToDelete == last) last = prevNode;

    T value = nodeToDelete->data;
    delete nodeToDelete;
    _size--;
    return value;
}

// Remove the last node
template <typename T>
T DLinkedList<T>::pop() {
    if (_size == 0) return T();
    return remove(_size - 1);
}

// Remove the first node
template <typename T>
T DLinkedList<T>::shift() {
    if (_size == 0) return T();

    DListNode<T>* nodeToDelete = root;
    root = root->next;
    if (root == NULL) last = NULL;

    T value = nodeToDelete->data;
    delete nodeToDelete;
    _size--;
    return value;
}

// Get the value at the specific index
template <typename T>
T DLinkedList<T>::get(int index) {
    DListNode<T>* node = getNode(index);
    return node ? node->data : T();
}

// Clear the list
template <typename T>
void DLinkedList<T>::clear() {
    while (_size > 0) shift();
}

#endif

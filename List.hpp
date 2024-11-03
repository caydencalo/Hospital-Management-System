#pragma once

#include "Node.hpp"

/**************************************************************************************************
 * List class implements the singly linked list data structure to support
 * all operations to store patient records.
 **************************************************************************************************/
template<class T>
class List {
public:
    List<T>(); //Constructor
    List(const List& copyList); //Copy Constructor Needed?
    ~List<T>(); //Destructor

    ////////Getters////////////////////////////
    Node<T> *getHeadPtr() const;

    ////////Setters////////////////////////////
    void setHeadPtr(Node<T> *newHeadPtr);

    ////////Singly list operations/////////////
    void insert(const T &newData);
    bool removeAtFront(T &removedData);
    bool isEmpty();
    T dequeue();

private:
    Node<T> *mpHead;
    void deleteList();
};

template <class T>
List<T>::List() {
    mpHead = nullptr;
}

template <class T>
List<T>::List(const List& copyList) {
    setHeadPtr(makeNode<T>(copyList.getHeadPtr()->getData()));
    builder(copyList->getHeadPtr()->getNextPtr());
}

template <class T>
List<T>::~List() {
    deleteList();
}

////////Getters////////////////////////////
template<class T>
Node<T>* List<T>::getHeadPtr() const {
    return mpHead;
}

////////Setters////////////////////////////
template<class T>
void List<T>::setHeadPtr(Node<T> *newHeadPtr) {
    this->mpHead = newHeadPtr;
}

////////Singly list operations/////////////
template<class T>
void List<T>::insert(const T &newData) { //insert at tail
    Node<T> *pMem = new Node<T>(newData); //Creates a new node

    if (this->mpHead == nullptr) {
        // If the list is empty, make the new node the head
        mpHead = pMem;
    } else {
        // Traverse to the end of the list
        Node<T> *current = mpHead;
        while (current->getNextPtr() != nullptr) {
            current = current->getNextPtr();
        }
        // Append the new node
        current->setNextPtr(pMem);
    }
    /*if (this->mpHead == nullptr) {
        mpHead = pMem;
    } else {
        pMem->setNextPtr(mpHead);
        mpHead = pMem;
    }*/
}

template<class T>
void List<T>::deleteList() {
    while (!this->isEmpty()) {
        this->dequeue();
    }
}

template<class T>
bool List<T>::isEmpty() {
    return this->mpHead == nullptr;
}

template <class T>
bool List<T>::removeAtFront(T &removedData) {
    if (isEmpty()) {
        return false;
    } else {
        Node<T>* temp = mpHead;
        removedData = mpHead->getData();
        mpHead = mpHead->getNextPtr();
        delete temp;
        return true;
    }
}

template<class T>
T List<T>::dequeue() {
    T data;
    Node<T>* temp = mpHead;
    data = temp->getData();
    mpHead = mpHead->getNextPtr();
    delete temp;
    return data;
}

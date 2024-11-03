#pragma once

#include "header.hpp"

/**************************************************************************************************
 * Node class represents nodes in a singly linked list
 **************************************************************************************************/
template <class T> //using templates
class Node {
public:
    Node(const T &newData); //Constructor
    ~Node(); //Destructor

    /////////////////Getters////////////////
    Node<T> *getNextPtr() const;
    T &getData();

    /////////////////Setters////////////////
    void setNextPtr(Node<T> *pMem);

private:
    Node<T> *mpNext;
    T mData;
};

template <class T>
Node<T>::Node(const T &newData) { //Constructor
    this->mpNext = nullptr; //initializes next ptr
    this->mData = newData; //<--- Not properly inserting the data in the node (mData)
}

template <class T>
Node<T>::~Node() { //Destructor
}

/////////////////Getters////////////////
template <class T>
Node<T> *Node<T>::getNextPtr() const{
    return this->mpNext;
}

template <class T>
T& Node<T>::getData() {
    return this->mData;
}

/////////////////Setters////////////////
template<class T>
void Node<T>::setNextPtr(Node<T> *pMem) {
    mpNext = pMem;
}



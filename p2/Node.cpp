// Node class to hold the data for each individual node of a LinkedList. Created by Logan Brennaman on 9/25/21

#include <iostream>

#include "Node.h"

using namespace std;

// Constructor to initialize a node with a given input, setting its next pointer to null
template<class T> Node<T>::Node(T input)
{
    value = input;
    next = nullptr;
}

// Destructor that prints a message to show that the node was deleted as planned
template<class T> Node<T>::~Node()
{
    // cout << "Deleted node" << endl; // Debugging
}

// Set method to set the value
template<class T> void Node<T>::setValue(T val)
{
    value = val;
}

// Set method to set the next pointer to the next node in the list
template<class T> void Node<T>::setNext(Node<T>* node)
{
    next = node;
}

// Get method for when the next node needs to be returned
template<class T> Node<T>* Node<T>::getNext()
{
    return next;
}

// Get method to return the value of a node
template<class T> T Node<T>::getValue()
{
    return value;
}
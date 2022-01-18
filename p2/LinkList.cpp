// LinkList class made by Logan Brennaman on 9/25/21

#include <iostream>

#include "LinkList.h"

using namespace std;

// Initialize the linked list
template<class T> LinkList<T>::LinkList()
{
    // Initialize the head and tail nodes as null pointers
    head = nullptr;
    tail = nullptr;
}

// Deconstructor to handle deleting the node objects of a LinkList
template<class T> LinkList<T>::~LinkList()
{
    // Start at the head
    Node<T>* current = head;

    // Do this while not looking at a nullptr
    while (current != nullptr)
    {
        // Create a variable to store the next of current while deleting current
        Node<T>* rem = current->getNext();

        // Delete the current node
        delete current;

        // Go to the next node
        current = rem;
    }
    // cout << "Deleted list" << endl; // Debugging
}

// Add the node to the end of the linked list
template<class T> void LinkList<T>::add(T element)
{
    // Create a node and store the value into it
    Node<T>* node = new Node<T>(element);

    // If the head and tail pointers are null, the list is empty
    if (head == nullptr && tail == nullptr)
    {
        // Set head and tail to point to the new node because that is the first node in the list
        head = node;
        tail = node;
    }
    else // Otherwise, it is known that the list has at least 1 element in it already.
    {
        // Look at the tail pointer. Set the tail pointer to the new node
        tail->setNext(node);
        tail = node;
    }
}

// Print the list in order
template<class T> void LinkList<T>::print()
{
    // Start at head and progress through the list printing values of nodes until a null pointer is reached.
    Node<T>* current = head;

    // Do this while not looking at a nullptr
    while (current != nullptr)
    {
        // Print the value of the current node
        cout << current->getValue() << " ";

        // Go to the next node
        current = current->getNext();
    }
    cout << endl;

}

// Set the head of the list
template<class T> void LinkList<T>::setHead(Node<T>* node)
{
    head = node;
}

// Set the tail of the list
template<class T> void LinkList<T>::setTail(Node<T>* node)
{
    tail = node;
}

// Get the head of the list
template<class T> Node<T>* LinkList<T>::getHead()
{
    return head;
}

// Get the tail of the list
template<class T> Node<T>* LinkList<T>::getTail()
{
    return tail;
}

// A convienient method to return the number of elements in a list
template<class T> int LinkList<T>::getSize()
{
    // Counter starts at 1 to count the head
    int counter = 0;

    // Start at head and progress through the list printing values of nodes until a null pointer is reached.
    Node<T>* current = head;

    // Do this while not looking at a nullptr
    while (current != nullptr)
    {
        // Count this node
        counter++;

        // Go to the next node
        current = current->getNext();
    }

    return counter;
}
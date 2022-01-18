#ifndef LINKLIST_H
#define LINKLIST_H

#include "Node.h"
#include "Node.cpp"

// A LinkList(LinkedList) is a class that stores a value and a pointer to the next node

/* The LinkList library, created by Logan Brennaman on 9/25/21
 * -----------------------------------------------------------
 * This library implements a LinkedList of a template type
 * 
 * Requires other personal library:
 *          - Node.h
 * -----------------------------------------------------------
 */

template<class T> class LinkList
{
    private:
        // Pointers to the head and tail of the LinkedList
        Node<T>* head;
        Node<T>* tail;

    public:
        // Constructor and Destructor
        LinkList();
        ~LinkList();
        
        // Two basic methods: add and print
        void add(T);
        void print();
        
        // Two set methods in case they are ever necessary
        void setHead(Node<T>*);
        void setTail(Node<T>*);
        
        // Two get methods in case they are ever necessary
        Node<T>* getHead();
        Node<T>* getTail();
        
        // A getSize method because it comes in handy sometimes
        int getSize();
};

#endif
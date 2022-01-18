#ifndef NODE_H
#define NODE_H

/* Node library created by Logan Brennaman on 9/25/21
 * --------------------------------------------------
 * Node library to create one node of a LinkedList
 * Used by LinkList.h
 * --------------------------------------------------
 */

template<class T> class Node
{
    private:
        // One node stores a value of a template type and a pointer to the next node in the list
        T value;
        Node<T>* next;

    public:
        // Constructor and Destructor
        Node(T);
        ~Node();
        
        // Two set methods for fields
        void setValue(T val);
        void setNext(Node<T>*);
        
        // Two get methods for fields
        Node<T>* getNext();
        T getValue();
};

#endif
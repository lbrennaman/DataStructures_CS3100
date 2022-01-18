#ifndef GTREE_H
#define GTREE_H

#include <string>

#include "LinkList.cpp"

/* gTree library created by Logan Brennaman on 9/25/21
 * -----------------------------------------------------
 * This library contains all of the methods needed to
 * create a basic general tree of a template type.
 * 
 * General tree structure: linked list
 * Requires other two personal libraries:
 *      - LinkList.h, implements a basic LinkedList
 *      - Node.h, implements a basic node of a LinkedList
 * ------------------------------------------------------
 */

template<class T> class gTree
{
    // Fields of a gTree
    private:
        T value;
        gTree<T>* parent;
        LinkList<gTree<T>*>* childPtrs;

    // Methods of a gTree
    public:
        // Initialization/Destruction
        gTree(T); // Constructor
        ~gTree(); // Destructor
        void del(); // Method to assist the destructor in deleting lists

        // Get methods to retrieve values that might be necessary
        T getValue();
        gTree<T>* getParent();
        LinkList<gTree<T>*>* getList();

        // Set methods to retrieve any values that might be necessary
        void setParent(gTree<T>*);

        // Ubuntu commands
        string pwd();
        void ls();
        bool exists(T dir);
        gTree<T>* cd(T);
        void mkdir(T);
        void rmdir(T);
        int countdir();
        void showtree(int);

        // Overrides
        template<class U> friend ostream& operator<<(ostream& os, const gTree<U>& t);
};

#endif
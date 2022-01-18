#ifndef BINTREE_H
#define BINTREE_H

template <class T> class BinTree {

    private:
        // A binary tree will have its value to store
        T value;

        // But also its two pointers
        BinTree<T>* left;
        BinTree<T>* right;

    public:
        // Constructor/Destructor
        BinTree(T); // Set the fields. Value = some value of type T. Left and right childs are set to nullptr
        ~BinTree(); // Deletes all child nodes and current node when delete is called

        // Return value of this node
        T getValue();   // Return the value stored in a node

        // Return the address of each child node
        BinTree<T>* getRight(); // Return the address of the right child
        BinTree<T>* getLeft();  // Return the address of the left child

        // Set each child node
        void setRight(BinTree<T>*); // Set the right child of a node
        void setLeft(BinTree<T>*);  // Set the left child of a node

        // Three versions of traversals
        void preOT();       // Preorder Traversal
        void postOT();      // Postorder Traversal
        void inOT();        // In order traversal
        void showtree(int);    // Print tree with tabs

        // Add method for a binary tree
        //void add(BinTree<T>*, int*);


};

#endif
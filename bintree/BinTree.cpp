#include <iostream>

#include "BinTree.h"

using namespace std;

template<class T> BinTree<T>::BinTree(T that)
{
    value = that;
    left = nullptr;
    right = nullptr;
}

template<class T> BinTree<T>::~BinTree()
{
    delete left;
    delete right;
    cout << "\nDeleted: " << this->getValue() << endl;
}

template<class T> T BinTree<T>::getValue()
{
    return value;
}

template<class T> BinTree<T>* BinTree<T>::getRight()
{
    return right;
}

template<class T> BinTree<T>* BinTree<T>::getLeft()
{
    return left;
}

template<class T> void BinTree<T>::setRight(BinTree<T>* rChild)
{
    right = rChild;
}

template<class T> void BinTree<T>::setLeft(BinTree<T>* lChild)
{
    left = lChild;
}

template<class T> void BinTree<T>::preOT()
{
    // Print out from root to rightmost leaf
    // Print root, if has left, go left.
    // If has right, go right
    cout << value << " ";
    if (left != NULL)
    {
        left->preOT();
    }
    if (right != NULL)
    {
        right->preOT();
    }
}

template<class T> void BinTree<T>::postOT()
{
    if (left != NULL)
    {
        left->postOT();
    }
    if (right != NULL)
    {
        right->postOT();
    }
    cout << value << " ";
}

template<class T> void BinTree<T>::inOT()
{
    if (left != NULL)
    {
        left->inOT();
    }
    cout << value << " ";
    if (right != NULL)
    {
        right->inOT();
    }
}

template<class T> void BinTree<T>::showtree(int tabNum)
{
    for (int i = 0; i < tabNum; i++) {
        cout << "\t";
    }
    cout << value << endl;
    if (left != NULL)
    {
        left->showtree(tabNum+1);
    }
    if (right != NULL)
    {
        right->showtree(tabNum+1);
    }
}
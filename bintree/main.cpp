#include <iostream>

#include "BinTree.h"
#include "BinTree.cpp"

using namespace std;

int main(void)
{
    // Program to test the BinTree<T> class
    BinTree<int>* net = new BinTree<int>(0);
    BinTree<int>* one = new BinTree<int>(1);
    BinTree<int>* two = new BinTree<int>(2);
    BinTree<int>* three = new BinTree<int>(3);
    BinTree<int>* four = new BinTree<int>(4);
    BinTree<int>* five = new BinTree<int>(5);

    net->setLeft(one);
    net->setRight(two);
    one->setLeft(three);
    two->setLeft(four);
    two->setRight(five);

    // Tree:
    //      0
    //    1   2
    //  3    4 5

    net->preOT();
    cout << endl << endl;
    net->postOT();
    cout << endl << endl;
    net->inOT();

    cout << endl << "Showtree: \n";
    net->showtree(0);

    // Creating more BinTrees
    BinTree<int>* s = new BinTree<int>(6);
    BinTree<int>* sv = new BinTree<int>(7);
    BinTree<int>* e = new BinTree<int>(8);
    BinTree<int>* f = new BinTree<int>(9);
    BinTree<int>* t = new BinTree<int>(10);
    BinTree<int>* ee = new BinTree<int>(11);
    BinTree<int>* tw = new BinTree<int>(12);
    BinTree<int>* abc = new BinTree<int>(13);

    // Tree:
    //      0
    //    1   2
    //  3    4 5

    // Adding them to tree
    one->setRight(tw);
    three->setLeft(s);
    three->setRight(sv);
    s->setLeft(e);
    e->setLeft(f);
    f->setRight(t);
    five->setRight(ee);
    ee->setRight(abc);

    // Showtree again
    cout << "Showtree2: \n";
    net->showtree(0);

    // Tree:
    //           0
    //         1    2
    //       3  12  4 5
    //      6 7        11
    //    8             13
    //   9
    // 10

    // Deletes current node and all of its children
    delete net;

/* Exam's traversal
    BinTree<int>* a = new BinTree<int>(1);
    BinTree<int>* b = new BinTree<int>(2);
    BinTree<int>* c = new BinTree<int>(3);
    BinTree<int>* d = new BinTree<int>(4);
    BinTree<int>* ea = new BinTree<int>(5);
    BinTree<int>* fa = new BinTree<int>(6);
    BinTree<int>* g = new BinTree<int>(7);
    a->setLeft(b);
    b->setLeft(c);
    b->setRight(ea);
    e->setLeft(d);
    d->setLeft(fa);
    d->setRight(g);
    a->inOT();
    delete a;
    */

}
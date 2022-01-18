#include <iostream>
#include <string>

#include "gTree.h"

using namespace std;

// Initialize a gTree node with an input
template<class T> gTree<T>::gTree(T input)
{
    value = input;
    parent = nullptr;
    childPtrs = new LinkList<gTree<T>*>();
}

// Takes care of clearing the heap when done
template<class T> gTree<T>::~gTree()
{
    // Parent can be deleted first
    delete parent;

    // Use del() to recursively go through each linked list in the tree and delete them
    del();
}

// Assists with the destruction of the linked list
template<class T> void gTree<T>::del()
{
    // Now to delete the linked list, iterate through the linked list recursively by using del() to delete the list
    Node<gTree<T>*>* current = getList()->getHead();

    while (current != nullptr)
    {
        current->getValue()->del();
        current = current->getNext();
    }

    delete getList();
}

// Returns the value (name of the current node in gTree)
template<class T> T gTree<T>::getValue()
{
    return value;
}

// Returns the parent of the current node in gTree
template<class T> gTree<T>* gTree<T>::getParent()
{
    return parent;
}

// Return the address of the first item in a LinkedList. Used for operations involving the LinkedList
template<class T> LinkList<gTree<T>*>* gTree<T>::getList()
{
    return childPtrs;
}

// Set the parent of the current node
template<class T> void gTree<T>::setParent(gTree<T>* par)
{
    parent = par;
}

// pwd - prints current PATH
/*
 * WORST CASE TIME COMPLEXITY: Linear time, O(n)
 * EXPLANATION:
 *      The pwd method's worst case time complexity is linear time.
 *      The pwd method contains 1 comparison but cannot be constant time because the method is also recursive.
 *      The method must go to the root node of the tree (1 comparison each time) and then fall back down the tree (no comparisons made when falling)
 *      For the worst case scenario, the size of the tree is n, meaning the tree contains a total of n nodes.
 *      If this were a binary tree of size n, then it would take log n operations to get to the root from a leaf, but this is a general tree.
 *      The worst case for a general tree is that all nodes are childs of another
 *      This would look like: root -> childOfRoot -> childOfChild -> childOfChild -> ... -> nth childOfChild (nth node)
 *      To get back to the root would thus take n operations from the nth node in the worst case scenario.
 *      Because it takes n comparisons in the worst case scenario, the worst case time complexity of pwd() is linear time
 */
template<class T> string gTree<T>::pwd()
{
    // Make sure the node has a parent
    if (parent != nullptr) // Comparison
    {
        return parent->pwd() + this->getValue() + "/" ;
    }
    return this->getValue() + "/";
}

// ls - prints all children of current node in gTree
/*
 * WORST CASE TIME COMPLEXITY: Linear time, O(n)
 * Explanation:
 *      The worst case time complexity for ls is linear time.
 *      The very first thing ls does is that it makes 1 comparison to make sure that the node has a parent because if a node has no parent --
 *          then that node cannot have a child
 *      In the worst case scenario the code would move past this and make it into the while loop.
 *      The while loop prints out the value stored in a linked list for as many nodes there are in the list.
 *      The worst case scenario will have a large linked list of size n where n is a number like 1,000,000
 *      Nothing changes the fact that for a list of size n the while loop will repeat n times.
 *      This means that the worst case time complexity for ls is O(n+1), or O(n), which is linear time.
 */
template<class T> void gTree<T>::ls()
{
    // Cycle through linked list and print children if possible
    if (this->getList()->getHead() == nullptr)  // Comparison x1
        cout << "This directory is empty" << endl;
    else
    {
        // Print items in list
        Node<gTree<T>*>* current = getList()->getHead();
        while (current != nullptr)  // Comparison x(size of list) [in worst case is n]
        {
            // Look at the gTree value held in the LinkedList
            cout << *(current->getValue()) << endl;
            current = current->getNext();
        }
    }
}

// exists [arg] - tells user if the given arg exists in the gTree
/*
 * WORST CASE TIME COMPLEXITY: Quadratic time, O(n^2)
 * Explanation:
 *      The worst case time complexity for the exists method is quadratic time, O(n^2).
 *      The first thing this method does if that it makes a comparison.
 *      Because this method is recursive, this single comparison happens n times in the worst case.
 *      The function then moves to iterate through the linked list of the node.
 *      Cycling through a linked list will result in n number of operations just like as in ls.
 *      The difference here is that the method recursively calls itself within the loop.
 *      This cycle of recursive calls will occur for as many linked lists there are in the tree. That number is n in the worst case
 *      This means that the while loop will occur a total of n * n times. (n^2)
 *      (There's actually an if statement in the while loop so there are actually 2n^2 operations in the loop but the constant doesn't matter.)
 *      So the time complexity of the whole method is n + 2n^2, which is just n^2 (quadratic time complexity)
 */
template<class T> bool gTree<T>::exists(T dir)
{
    // Setup a return value to store the value to return if there is one
    bool returnValue = 0;

    // If the value in this node is the given parameter, that means the directory has been found. Return 1 to show this
    if (getValue() == dir) // Comparison (occurs once per each time this function is called), so occurs n times for n nodes in tree
        return 1;
    else
    {
        // Search through the node's children (if able) to search for the parameter. Do this recursively
        Node<gTree<T>*>* current = getList()->getHead();
        while (current != nullptr) // Comparison x(size of list), recursively for as many linked lists there are in the tree (n lists)
        {
            // Look at the gTree value held in the LinkedList
            returnValue = current->getValue()->exists(dir);

            // If a 1 has already been found, return it before it gets overwritten
            if (returnValue == 1) { // Comparison x(size of list)
                return returnValue;
            }

            current = current->getNext();
        }
    }
    return returnValue;
}

// cd [arg] - progress to the next directory if that directory [arg] exists
/*
 * WORST CASE TIME COMPLEXITY: Linear time, O(n)
 * Explanation:
 *      The worst case time complexity for cd() is linear time, O(n).
 *      The first thing that happens is an if statement to make 1 comparison.
 *      In the worst case, the code will not enter the if statement because the most operations that could occur in that if statement is 2.
 *      The code will make it to the else and then loop through a while loop to iterate through the linked list of the current node
 *      This loop will occur n times and also contains an if statement that will occur n times.
 *      After exiting the if-else statement, there is 1 more comparison to make before returning but that 1 operation is insignificant
 *      The worst case time will take 1 + n + n + 1 operations, which means that it takes n operations and is linear time.
 */
template<class T> gTree<T>* gTree<T>::cd(T arg)
{
    // Check for the special case first
    if (arg == "..") // Comparison. Only happens once
    {
        // Make sure that the user isn't already in the root directory
        if (parent == nullptr) // Must be "if parent is null" because more than one "root" can theoretically be created
        {
            // If there is no parent, then the user is in root. Cannot go back a directory
            cout << "You are already in the root directory" << endl;
        }
        else // User can go back a directory, so go back
        {
            return this->getParent();
        }
    }
    else // It was not the special case. Check if [arg] is a child of this. If so, return the child's address
    {
        // Iterate through this->getList() in search of [arg].
        Node<gTree<T>*>* current = getList()->getHead();
        while (current != nullptr) // Comparison. Repeats n times. Will come here on worst case
        {
            // Look at the gTree value held in the LinkedList
            if ((current->getValue())->getValue() == arg) // Comparison. Function is not recursive so this occurs n times
            {
                return current->getValue();
            }

            // If the current's value wasn't [arg], progress to next node
            current = current->getNext();
        }
    }

    // If a value hasn't been returned yet, then [arg] was not a child of this node.
    // Print that the child does not exist
    if (arg != "..") // Comparison. Theoretically reaches this in the worst case. 1 comparison here.
        cout << arg << " does not exist." << endl;

    // Return the same node to do nothing
    return this;
}

// mkdir - creates a new sub-directory for the current node
/*
 * WORST CASE TIME COMPLEXITY: Constant time, O(1)
 *      The worst case time complexity for mkdir() is constant time, O(1)
 *      The worst case for mkdir() is = the worst case time for a LinkList's add method.
 *      The reason is because there are no comparisons in mkdir, but there are in add, a method used by mkdir
 *      add() has two comparisons, meaning that the add method for a linked list is constant time
 *      That means that mkdir for a gTree is also constant time, O(1)
 */
template<class T> void gTree<T>::mkdir(T arg)
{
    // Create a new gTree<T>* for the arg
    gTree<T>* newNode = new gTree<T>(arg);

    // Set the node's parent
    newNode->setParent(this);

    // Use the add method of this node's linked list
    this->getList()->add(newNode);
}

// rmdir - Removing a node from the gTree (removing a directory)
/*
 * WORST CASE TIME COMPLEXITY: Linear time, O(n)
 * Explanation:
 *      The worst case time complexity for rmdir is linear time, O(n)
 *      The first comparison to be made is the while loop that iterates through the linked list of a node.
 *      It will take n comparisons to loop through the linked list and make n comparisons every time due to the if-statement inside
 *      The program will never make it inside the if-statement in the worst case
 *      Instead, the value of a node will never equal the parameter [arg], meaning [arg] doesn't exist in the tree
 *      The method will thus finish after n+n operations, which is n operations: linear time, O(n)
 */
template<class T> void gTree<T>::rmdir(T arg)
{
    // Cycle through linked list and look for [arg]
    Node<gTree<T>*>* current = getList()->getHead();

    // Keep track of previous node as well as the current node
    Node<gTree<T>*>* previous = current;

    // Look through list until a null pointer is reached
    while (current != nullptr) // Comparison. Method is not recursive so occurs n times
    {
        // Look at the gTree value held in the LinkedList
        if (current->getValue()->getValue() == arg) // Comparison. Occurs n times
        {
            // The node must be deleted, but pointers must be changed to keep the list intact.
            // Set previous's pointer to current's next
            if (previous != current) // Comparison
            {
                previous->setNext(current->getNext());

                // Current node can now be deleted
                delete current;
            }
            else if (previous == current) // If they were both the same, that means the head/tail was deleted. Reset head and tail      //Comparison
            {
                getList()->setHead(nullptr);
                getList()->setTail(nullptr);
            }

            // Can return after hitting one of these
            return;
        }
        else
        {
            // If the current's value wasn't [arg], progress to next node
            previous = current;
            current = current->getNext();
        }
    }

    // If it made it here, [arg] is not a child of the current node. Display this fact
    cout << arg << " not found" << endl;
}

// countdir - Return the number of descendents + 1 of the current node
/*
 * WORST CASE TIME COMPLEXITY: Quadratic time, O(n^2)
 * Explanation:
 *      The worst case time complexity for countdir() is quadratic time, O(n^2)
 *      The reason is because of its one comparison: the while loop
 *      The loop will iterate over a LinkedList n times but also contains a recursive call to the function that will happen n times
 *      The time complexity is therefore n*n: quadratic time, O(n^2)
 */
template<class T> int gTree<T>::countdir()
{
    // Progress through each tree and add the totals of their list's count method
    int count = 0; // Start by counting the current node

    // Iterate through this->getList() to get the total number of descendents in a node
    Node<gTree<T>*>* current = getList()->getHead();
    while (current != nullptr) // Comparison, occurs n times recursively n times. n^2
    {
        // Look at the gTree value held in the LinkedList
        count += current->getValue()->countdir();

        // Progress to the next child for their totals
        current = current->getNext();
    }

    // The extra one will be added to this total in main
    return count + getList()->getSize();
}

// showtree - using the current node in a gTree, print all nodes (with tabs showing levels)
/*
 * WORST CASE TIME COMPLEXITY: Cubic time, O(n^3)
 * Explanation:
 *      The worst case time complexity for showtree will be cubic time, O(n^3)
 *      The first comparison is a for loop that will occur tabNum number of times. 
 *      When there are n subdirectories, each recursive call will use the for loop to print a number of tabs
 *      For example, starting from root:
 *          0 tabs, 1 tab, 2, 3, 4, 5, ..., n - 5, n-4, n-3, n-2, n-1, n tabs for the nth subdirectory
 *          (If I'm off by 1 it doesn't matter because n-1! is still n!)
 *      The amount of operations used by the for loop is therefore the sum of all these terms: Sigma(n) and this will happen n times
 *      Sigma(n) = (n(n-1))/2 and multiply that by n to get the number of operations for the for loop: n((n(n-1))/2)
 *      Traversing through the linked list will take n^2 comparisons so the total amount of operations in this method is: n((n(n-1))/2) + n^2
 *      That becomes the time complexity: O(n^3), cubic time
 *      
 */
template<class T> void gTree<T>::showtree(int tabNum)
{
    // Preorder traversal
    // First thing that happens is that the node is printed
    // Depending on level, controlled by the param tabNum, print the appropriate number of tabs before the node
    for (int i = 0; i < tabNum; i++) // Comparison. Occurs tabNum times but is recursive so tabNum will be n in the worst case (n subdirectories)
    {
        cout << "\t";
    }

    // Print node
    cout << this->getValue() << endl;

    // Traversal
    // Traversing a linked list through iteration
    Node<gTree<T>*>* current = getList()->getHead();
    while (current != nullptr) // Comparison. Occurs n times, recursively, so n^2 times
    {
        // Going down a level. Pass tabNum+1
        current->getValue()->showtree(tabNum+1);

        // Progress to next node
        current = current->getNext();
    }
}

// Overriding the << operator to print the value of a gTree when attempting to print a gTree (used in ls)
template<class U> ostream& operator<<(ostream& os, const gTree<U>& t)
{
    os << t.value;
    return os;
}

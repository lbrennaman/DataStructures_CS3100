#include <list>
#include <iostream>

using namespace std;

int main(void)
{
    // Definition of an empty linked list on the stack
    list<int> linList;

    // How to initialize the iterator for a list
    list<int>::iterator it;

    // _______________________________________________________________________________________________________________________________________

    // Insertion at FRONT and BACK testing
    cout << "Insertion at FRONT and BACK testing" << endl << "______________________" << endl << endl;

    // Method to ADD something to the BACK (end) of the linked list
    linList.push_back(1);
    linList.push_back(2);
    linList.push_back(3);

    // _______________________________________________________________________________________________________________________________________

    // Methods to ACCESS elements in beginning and end positions of list
    cout << "In the front: " << linList.front() << ", and in the back: " << linList.back() << endl;

    // Method to ADD something to the FRONT (beginning) of the linked list
    linList.push_front(0);
    linList.push_front(-1);
    linList.push_front(-2);
    linList.push_front(-3);

    // Printing out the list
    cout << "PRINTING THE LIST" << endl << "_________________" << endl << endl;
    for (it = linList.begin(); it != linList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;


    // _______________________________________________________________________________________________________________________________________

    // Methods to ACCESS elements in beginning and end positions of list
    cout << "In the front: " << linList.front() << ", and in the back: " << linList.back() << endl;

    cout << endl << "Size/Capacity testing" << endl << "______________________" << endl << endl;

    // Methods to test capacity/size;
    cout << "Is list empty: " << linList.empty() << endl;
    cout << "What is the size of the list? " << linList.size() << endl;
    cout << "What is the MAX size of the list? " << linList.max_size() << endl << endl;

    // Printing out the list
    cout << "PRINTING THE LIST" << endl << "_________________" << endl << endl;
    for (it = linList.begin(); it != linList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    // _______________________________________________________________________________________________________________________________________

    // INSERTING INTO A CERTAIN POSITION
    // iterator insert(iterator, value);                       // Given a value, inserts value into position iterator - 1
    // void insert(iterator, n, value);                        // Same as first, but inserts value into position n times
    // void insert(iterator, InputIterator, InputIterator);    // Insert values from (InputIterators) begin to end in position iterator - 1

    cout << "INSERTION TESTING" << endl << "___________________" << endl << endl;

    // Create index to insert item before
    int index = 5;

    // Set the iterator to start at the beginning of the list
    it = linList.begin();

    // Move iterator over to index
    for (int i = 0; i < index; i++)
    {
        it++;
    }

    // Insert value in between index -1 and index, so index and everything to its right is pushed right. Value becomes element in index
    linList.insert(it, 10);

    // Printing out the list
    cout << "PRINTING THE LIST" << endl << "_________________" << endl << endl;
    for (it = linList.begin(); it != linList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;

    // TEST REMOVAL
    // Does not use the remove() method; that would be bad
    // iterator erase(iterator);               // Delete element in this exact position
    // iterator erase(iterator, iterator);     // Delete element in range: [begin, end)
    cout << "REMOVAL TEST" << endl << "_________________" << endl << endl;
    
    // Create index to insert item before
    index = 4;

    // Set the iterator to start at the beginning of the list
    it = linList.begin();

    // Move iterator over to index
    for (int i = 0; i < index; i++)
    {
        it++;
    }
    
    // ERASE the value at the index
    linList.erase(it);

    // Printing out the list
    cout << "PRINTING THE LIST" << endl << "_________________" << endl << endl;
    for (it = linList.begin(); it != linList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl << endl;
}

/*
    THIS CLASS CONTAINS EXAMPLES OF HOW TO USE ITERATORS BY USING LIST, the cpp version of a LINKED LIST

    Explanation of LIST class methods because THE DOCUMENTATION SUCKS
    _____________________________________________________________________________________________________________________________________________
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    Constructors
    _________________________________

    list(void);                 // EMPTY: No elements
    list(n, element);           // Fill: n nodes filled with copies of element
    list(iterator, iterator);   // Iterate: creates a new list by using the iterators of another list
    list(listToCopy);           // Copy: creates a copy of a given list


    OVERIDES
    _________________________________

    operator=();    // Equals operator has been overriden so that list first = list second, will copy the elements of second into first


    ITERATORS
    _________________________________

    begin();        // Set iterator to beginning
    end();          // Set iterator to end
    ^^^^^^^^
    Add r to beginning of these to get reverse iterators: rbegin and rend
    ^^^^^^^^
    Add c to beginning of these to get constant versions: cbegin, crbegin


    CAPACITY/SIZE
    _________________________________

    empty();        // Return 1 if the list is empty, 0 if the list contains an element
    size()          // Returns the size of the list
    max_size();     // Returns the max possible size of the list


    ASSIGN
    _________________________________

    void assign(InputIterator first, InputIterator end);    // Recreates linked list using elements from [first, end]
    void assign(numberOfElements, valueToAdd);              // Changes list to new size filled with values to add


    EMPLACE_FRONT
    _________________________________

    void emplace_front(args);    // Given a number of args, puts them all into the first node of list, all as ONE ELEMENT
        cout << "mylist contains:";
        for (auto& x: mylist)
            cout << " (" << x.first << "," << x.second << ")";


    PUSH_FRONT
    _________________________________

    void push_front(element);    // Puts given element into the first position in the linked list


    PUSH_BACK
    _________________________________

    void push_back(element);     // Puts given element into the end position of the linked list


    EMPLACE_BACK
    _________________________________

    void emplace_back(args);     // Given a number of args, puts them all into the last node of list, all as ONE ELEMENT


    POP_FRONT
    _________________________________

    void pop_front();       // Remove first element in list (DOES NOT RETURN)


    POP_BACK
    _________________________________

    void pop_back();        // Remove last element in list (DOES NOT RETURN)


    EMPLACE
    _________________________________

    iterator<type> emplace(iterator, args); // Perform emplacement (SEE EMPLACE_BACK) at the place provided by iterator


    INSERT
    _________________________________

    iterator insert(iterator, value);                       // Given a value, inserts value into position iterator - 1
    void insert(iterator, n, value);                        // Same as first, but inserts value into position n times
    void insert(iterator, InputIterator, InputIterator);    // Insert values from (InputIterators) begin to end in position iterator - 1


    ERASE
    _________________________________

    iterator erase(iterator);               // Delete element in this exact position
    iterator erase(iterator, iterator);     // Delete element in range: [begin, end)


    SWAP
    _________________________________

    void swap(list&);   // Given another list, this list exchanges all nodes with the other list


    RESIZE
    _________________________________

    void resize(n);             // If n < size, changes size to n and destroys all elements that were popped from list
                                // If n > size, initializes all new values somehow
    void resize(n, value);      // When initializing new values, if value is given, uses a copy of value to initialize those new values


    CLEAR
    _________________________________

    void clear();       // Returns list to a size 0 with no nodes


    SPLICE
    _________________________________

    TAKES ELEMENTS FROM ONE LIST AND THROWS THEM IN ANOTHER

    void splice(iterator pos, list&);                                       // Stores all elements into this list at position
    void splice(iterator pos, list&, iterator i);                           // Only stores elements pointed to by i at position
    void splice(iterator pos, list&, iterator first, iterator last);        // Stores all elements from [first, last) at position


    REMOVE
    _________________________________

    remove(value);      // Removes ALL elements in list that are EQUAL TO VALUE


    REMOVE_IF
    _________________________________

    remove_if(Predicate);   // Removes all elements from the list that make the PREDICATE TRUE


    UNIQUE
    _________________________________

    void unique();                  // Remove all duplicate elements from the list
    void unique(BinaryPredicate);   // Removes an element from the list when condition returns true


    MERGE
    _________________________________

    void merge(list&);              // Removes all elements from given list and stores them into this list by SORTING THEM IN
    void merge(list&, Compare);     // Does the above by using a COMPARATOR


    SORT
    _________________________________

    void sort();                    // Sorts list
    void sort(Compare);             // Sorts list based off of a COMPARATOR


    REVERSE
    _________________________________

    void reverse();                 // Reverses the order of the list


*/
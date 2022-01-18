// HashTable class created by Logan Brennaman on 10/18/21

// A HashTable is an array of Records that is sorted based off of a hashing function
// A hashing function, h(k), takes a key, k, and provides an index in the array that the key corresponds to
// The resulting index can allow the user to perform a variety of actions on the respective Record stored in that index of the array
// The actions in this class are: insertion, deletion, and searching

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "Record.cpp"

using namespace std;

template<class T> class HashTable
{
    // Private fields of the HashTable class
    private:
        Record<T>* hashTable;

    // Public methods of the HashTable class
    public:
        // Empty constructor to initialize hashTable
        HashTable();

        // Methods to insert, remove, or find things in the HashTable
        bool insert(int, T, int&);
        bool remove(int, T&);
        bool find(int, T&);

        // Method to calculate the number of spaces occupied / the total spaces in the HashTable (MAXHASH which is set to 1000)
        float alpha();

        // getSize() method to make it easier to calculate alpha. Returns the number of occupied spaces in the HashTable to be used in alpha()
        int getSize();

        // Three different hash methods
        int hashOne(int); // Returns the key & MAXHASH
        int hashTwo(int); // Returns
        int hashThree(int); // Used by doubleHashProbe() to calculate a different offset

        // Two different probing methods
        int linearProbe(int, int); // Using a key and a counter, return an offset from the current k
        int doubleHashProbe(int, int); // Returns the offset of linear probing multiplied by the value returned by a hash funtion

        // Override the << operator to print all indeces of the HashTable that contain records
        template<class U> friend ostream& operator<<(ostream& os, const HashTable<U>& hash);
};

#endif
// HashTable.cpp file containing methods of the HashTable.h class
// Created by Logan Brennaman on 10/18/21

#define MAXHASH 1000

#include <iostream>
#include "HashTable.h"

using namespace std;

// Constructor to initialize the hashTable with Records. Will be size of #define MAXHASH
template<class T> HashTable<T>::HashTable()
{
    hashTable = new Record<T>[MAXHASH]();
}

/*
 *   INSERT
 *       A hash will be applied to the given key to store the given value into the resulting index provided by the hash function.
 *       Any collisions that occur will be reported back to the user ONLY IF the value can be successfully inserted
 *       Duplicates are not allowed, and the function also cannot insert if the table is full (getSize() == MAXHASH)
 *       IF GRAVESTONE = 1, set GRAVESTONE = -1 if INSERT IS SUCCESSFUL
 */
template<class T> bool HashTable<T>::insert(int key, T value, int& collisions)
{
    // THIS IS THE CODE FOR INSERTING WITH HASHTWO, LINEARPROBE
    // CHECK IF CAN BE INSERTED INTO: IF GETSIZE < MAXHASH -1: ELSE, GETSIZE >= MAXHASH -1, do not insert
    if (getSize() >= MAXHASH - 1)
    {
        return false;
    }

    // Create new Record(key, value)
    Record<T> record(key, value);

    // See if newRecord already exists in hashTable
    for (int i = 0; i < MAXHASH; i++)
    {
        // Only check if this Record's values have been initialized
        if (hashTable[i].initTrue())
        {
            // If they are both the same, return false
            if (hashTable[i].getKey() == record.getKey() && hashTable[i].getValue() == record.getValue())
            {
                return false;
            }
        }
    }

    // If not:
    // See if home position is empty (If it is ! initialized)
    if (!hashTable[hashTwo(key)].initTrue())
    {
        // IF YES:
        // hashTable[h(k)] = newRecord (using overriden = operator)
        hashTable[hashTwo(key)] = record;

        // check if gravestone = 1. If so, set it to -1
        if (hashTable[hashTwo(key)].getGrave() == 1)
        {
            hashTable[hashTwo(key)].setGrave(-1);
        }

        // return true;
        return true;
    }

    // IF NO:
    // Probe function must be called

    // collisions counter is set to 1
    int cc = 1;

    // isTrue = true;
    bool isTrue = true;

    // probe attempts = 0
    int i = 0;

    // initialize the offset
    int offset = 0;

    // LOOP(isTrue):
    while (isTrue)
    {
        // Get an offset from probe function
        offset = linearProbe(key, i);

        // Hash(key) + offset is the index. Index ranges from 0 - 999. Must be less than MAXHASH
        // If hash + offset >= MAXHASH, subtract MAXHASH from it
        while (hashTwo(key) + offset >= MAXHASH)
        {
            offset -= MAXHASH;
        }

        // If offset landed on a blank space
        if (!hashTable[hashTwo(key) + offset].initTrue())
        {
            // hashTable[h(k) + offset] = newRecord
            hashTable[hashTwo(key) + offset] = record;

            // check if gravestone = 1. If so, set it to -1
            if (hashTable[hashTwo(key) + offset].getGrave() == 1)
            {
                hashTable[hashTwo(key) + offset].setGrave(-1);
            }

            // isTrue = false
            isTrue = false;
        }
        else // IF NOT:
        {
            // cc++;
            cc++;

            // attempts++;
            i++;
        }
    }

    // True is going to be returned. First set collisions equals to the collisions counter
    collisions = cc;

    // return true if it made it here
    return true;
}

/*
 *   REMOVE
 *       A hash will be applied to the given key, allowing for the user to check if there is a RECORD in that location.
 *       If a RECORD is found, set value = to that RECORD, REMOVE THAT RECORD, and return True
 *       Else, return false
 *       SET GRAVESTONE = 1 upon SUCCESSFUL REMOVAL
 */
template<class T> bool HashTable<T>::remove(int key, T& value)
{
    // THIS IS THE CODE FOR hashTwo, LINEAR PROBE
    // Check if there is a record in that location (by checking if the record is initialized)
    if (hashTable[hashTwo(key)].initTrue())
    {
        // Copy the record's value into value
        value = hashTable[hashTwo(key)].getValue();

        // Remove the record by setting its init to false
        hashTable[hashTwo(key)].setInit(false);

        // Set gravestone to 1 upon a successful removal
        hashTable[hashTwo(key)].setGrave(1);

        return true;
    }

    // If it made it here, there was no record: return false
    return false;
}

/*
 *   FIND
 *       A hash will be applied to the given key, allowing for the user to check if there is a RECORD in that location.
 *       If a RECORD is found, set value = to a COPY of that RECORD, return TRUE
 *       Else, return false
 */
template<class T> bool HashTable<T>::find(int key, T& value)
{
    // Possible start locations:
        // Case 1: Index is initialized and there is no grave
            // See if that record is the given key, if not, probe until it's found
        // IMPOSSIBLE: Index is initialized and there is a grave
        // Case 2: Index is not initialized and there is no grave
            // Record is not in hashtable: return false
        // Case 3: Index is not initialized and there is a grave
            // Probe until either a blank space is hit or the key is found

    // THIS CODE IS FOR hashTwo, LINEAR PROBE
    // Check if there is a record in that location (by checking if the record is initialized)
    if (hashTable[hashTwo(key)].initTrue() && hashTable[hashTwo(key)].getGrave() == -1)
    {
        // See if that the Record's key matches the given key. If so, return true. Else, probe until an empty space with no grave is hit
        if (hashTable[hashTwo(key)].getKey() == key)
        {
            // Set value to that record's value
            value = hashTable[hashTwo(key)].getValue();
            return true;
        }
        else // Use probing to see if the record was placed elsewhere
        {
            bool isTrue = true;
            int offset = 0;
            int i = 0;
            while (isTrue)
            {
                offset = linearProbe(key, i);

                // Hash(key) + offset is the index. Index ranges from 0 - 999. Must be less than MAXHASH
                // If hash + offset >= MAXHASH, subtract MAXHASH from it
                while (hashTwo(key) + offset >= MAXHASH)
                {
                    offset -= MAXHASH;
                }

                if (!hashTable[hashTwo(key) + offset].initTrue()) // If offset landed on a blank space
                {
                    // If that blank space has a gravestone, increment i and leave if statement
                    if (hashTable[hashTwo(key) + offset].getGrave() == 1)
                    {
                        i++;
                    }
                    else // Never found key. Return false
                    {
                        return false;
                    }
                }
                else // Offset didn't land on a blank space
                {
                    // Check if this location contains the key
                    if (hashTable[hashTwo(key) + offset].getKey() == key)
                    {
                        value = hashTable[hashTwo(key) + offset].getValue();
                        return true;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
        }
    }
    else if (!hashTable[hashTwo(key)].initTrue() && hashTable[hashTwo(key)].getGrave() == 1)
    {
        bool isTrue = true;
        int offset = 0;
        int i = 0;
        while (isTrue)
        {
            offset = linearProbe(key, i);

            // Hash(key) + offset is the index. Index ranges from 0 - 999. Must be less than MAXHASH
            // If hash + offset >= MAXHASH, subtract MAXHASH from it
            while (hashTwo(key) + offset >= MAXHASH)
            {
                offset -= MAXHASH;
            }

            if (!hashTable[hashTwo(key) + offset].initTrue()) // If offset landed on a blank space
            {
                // If that blank space has a gravestone, increment i and leave if statement
                if (hashTable[hashTwo(key) + offset].getGrave() == 1)
                {
                    i++;
                }
                else // Never found key. Return false
                {
                    return false;
                }
            }
            else // Offset didn't land on a blank space
            {
                // Check if this location contains the key
                if (hashTable[hashTwo(key) + offset].getKey() == key)
                {
                    value = hashTable[hashTwo(key) + offset].getValue();
                    return true;
                }
                else
                {
                    i++;
                }
            }
        }
    }

    // If it made it here, there was no record: return false
    return false;
}

// alpha - returns getSize() / MAXHASH
template<class T> float HashTable<T>::alpha()
{
    return ((float)getSize() / (float)MAXHASH);
}

// getSize() - counts all initialized Records in the HashTable and returns that count
template<class T> int HashTable<T>::getSize()
{
    // Start a count
    int count = 0;

    // Iterate through the entire array
    for (int i = 0; i < MAXHASH; i++)
    {
        // If the Record at the current index, i, has a value, increment count by 1
        if (hashTable[i].initTrue())
        {
            count++;
        }
    }

    // Return how many Records were counted
    return count;
}

// hashOne: returns key % MAXHASH
template<class T> int HashTable<T>::hashOne(int key)
{
    return key % MAXHASH;
}

// hashTwo: returns (key + getSize()) % MAXHASH
template<class T> int HashTable<T>::hashTwo(int key)
{
    return ((key * 3) + (key * 2) + key )% MAXHASH;
}

// hashThree: returns (key / getSize()) % MAXHASH
// Used by doubleHashProbe()
template<class T> int HashTable<T>::hashThree(int key)
{
    return ((key * 7) + key) % MAXHASH;
}

// LinearProbe
// Return the position of the next record in the array as the offset
template<class T> int HashTable<T>::linearProbe(int key, int attempts)
{
    // If the probe landed on an empty space (initTrue == false)
    return attempts + 1;
}

// Double-hash probe: calculates a relatively prime number to use as a probe using hashThree
// Return the offset if it is relatively prime to MAXHASH
template<class T> int HashTable<T>::doubleHashProbe(int key, int attempts)
{
    // Get the offset by multiplying the number of attempts by hashThree
    int offset = attempts + hashThree(key);

    if (offset != 0)
    {
        // Make sure that the offset is relatively prime
        while (MAXHASH % offset == 0)
        {
            offset++; // increment offset until MAXHEAP is not evenly divisible by offset
        }
    }

    return offset;

}

// Overriding the << operator to print all of the records held in the HashTable
// Writing "cout << *hashtable" will print the hashtable
template<class U> ostream& operator<<(ostream& os, const HashTable<U>& hash)
{
    os << "HASHTABLE\n_________________\n";
    for (int i = 0; i < MAXHASH; i++) {
        if (hash.hashTable[i].initTrue())
        {
            os << i << " | " << hash.hashTable[i].getKey() << " | " << hash.hashTable[i].getValue() << endl;
        }
    }
    return os;
}
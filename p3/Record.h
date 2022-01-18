// Record class created by Logan Brennaman on 10/18/21.

// A Record is located in one index of a HashTable's array. A Record contains a key, a value, and a gravestone to be used by the HashTable

#ifndef RECORD_H
#define RECORD_H

template<class T> class Record
{
    // Private fields of a Record
    private:
        int key; // Used to match an index of a HashTable to this Record
        T value; // Value stored in this Record
        int gravestone; // Indicates whether or not a Record can be written to or not (initialized to -1)
        bool init; // Tells if the above fields have been altered yet or not

    // Public methods of the Record class
    public:
        // Empty constructor to initialize the most basic Record: a Record filled with nothing
        Record();

        // Second constructor: initializes a Record with a key and a value
        Record(int, T);

        // Setter methods
        void setKey(int);
        void setValue(T);
        void setGrave(int);
        void setInit(bool);

        // Getter methods
        int getKey();
        T getValue();
        int getGrave();
        bool initTrue();

        // Override the = operator
        Record<T>& operator=(const Record&);

};

#endif
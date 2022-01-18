// Logan Brennaman 9/10/21

#include <exception>
#include <iostream>

#include "Entry.h"
#include "NoSuchEntry.h"

using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------------//
/* THE SPARSEMATRIX CLASS
 * ----------------------
 *
 * This class implements the data type known as a SparseMatrix:
 * Given a two dimensional array with many empty spaces, a sparsematrix takes the data in the nonempty spaces and stores that data
 *     (along with its row and column) in a list.
 */
//-----------------------------------------------------------------------------------------------------------------------------------//

template <class T> class SparseMatrix
{

    private:
        Entry<T>** entries;
        int capacity;
        int size;

    public:
        // Default constructor – creates a new sparse matrix that contains no entries
        SparseMatrix()
        {
            // First, set the initial capacity
            capacity = 5;

            // Initialize entries by allocating space but not filling any of it
            // Initialize columns of size capacity
            entries = createEntries();

            // No items have been added to the list of Entries; therefore, size should be set to 0
            size = 0;
        }

        // Copy constructor – creates an independent copy of the other sparse matrix
        SparseMatrix(const SparseMatrix& other)
        {
            // First, copy the capacity and size so that a new list of entries can be created without corrupting memory
            // For example, say the list of Entries was copied first while this.capacity = 10, other.capacity = 20.
            // Copying an array of size 20 into an array of size 10 would copy over the 10 indexes past this object's size.
            // Just extending the size of this object wouldn't work because those indexes past index 9 could still have important data in them

            //----------------------------------------------------------------------------------------------------------------------------//
            // The proper way to copy these values is to create a new array entirely and then deallocate the memory used for the old list
            //----------------------------------------------------------------------------------------------------------------------------//

            // Change capacity and size to equal that of other
            capacity = other.capacity;
            size = other.size;

            // Initialize this object's list of Entries based on the size of the other object
            // Since it is using this constructor the entries have not yet been created so create them
            entries = createEntries();

            // Fill that list of Entries using the given object
            for (int i = 0; i < capacity; i++)
            {
                for (int j = 0; j < capacity; j++)
                {
                    // The "=" has been overriden for the entry class. Entry = Entry will copy the values properly
                    entries[i][j] = other.entries[i][j];
                }
            }

        }

        // Assignment operator overload – creates an independent copy of the other sparse matrix without leaking any memory
        SparseMatrix& operator=(const SparseMatrix& other)
        {
            //----------------------------------------------------------------------------------------------------------------------------//
            // The proper way to copy these values is to create a new array entirely and then deallocate the memory used for the old list
            //----------------------------------------------------------------------------------------------------------------------------//

            // Change capacity and size to equal that of other
            capacity = other.capacity;
            size = other.size;

            // Free the memory in this list of entries, they are being overwritten and no longer needed
            deleteMatrix();

            // Store other's entries into this one's entries
            for (int i = 0; i < capacity; i++)
            {
                for (int j = 0; j < capacity; j++)
                {
                    // The "=" has been overriden for the entry class. Entry = Entry will copy the values properly
                    entries[i][j] = other.entries[i][j];
                }
            }

            // Return the object
            return *this;
        }

        // Destructor – destroys the sparse matrix without leaking any memory
        ~SparseMatrix()
        {
            // Deallocate memory by deleting the list of Entries
            // The list of Entries is two dimensional so each array must be deleted individually
            deleteMatrix();
        }

        //---------------------------------------------------------------------------------------------------//
        /* void add(int row, int col, T value) – adds the value to the specified row and column of the sparse
         * matrix, [overwriting an existing entry if one is already present at that location (without leaking
         * any memory)]; there should be no limit on the number of entries that can be added, within the
         * bounds of the available RAM
         *///------------------------------------------------------------------------------------------------//
        void add(int row, int col, T value)
        {
            // First check that the provided values for row and col actually exist within the array
            if (row < capacity && col < capacity)
            {
                // Create an Entry from the given parameters
                Entry<T>* newEntry = new Entry<T>(row, col, value);

                // Use the equals operator to overwrite the Entry
                entries[row][col] = *newEntry;

                // Add 1 to size
                size++;
            }
            else // If the row/col is out of bounds, expand capacity by capacity *2
            {
                // Keep track of old capacity for bounds
                int old_capacity = capacity;

                // A new array of the size of the new capacity must be created
                // Begin by creating a copy array of the old capacity and fill it with the entries to copy
                Entry<T>** copy = new Entry<T>*[old_capacity];
                for (int i = 0; i < old_capacity; i++)
                {
                    for (int j = 0; j < old_capacity; j++)
                    {
                        copy[i] = new Entry<T>[old_capacity];
                    }
                }
                for (int i = 0; i < old_capacity; i++)
                {
                    for (int j = 0; j < old_capacity; j++)
                    {
                        copy[i][j] = entries[i][j];
                    }
                }

                // Delete entries in this object
                deleteMatrix();

                // Create new entries list of new capacity size
                capacity *= 2;
                entries = createEntries();

                // Give entries its old values back
                for (int i = 0; i < old_capacity; i++)
                {
                    for (int j = 0; j < old_capacity; j++)
                    {
                        entries[i][j] = copy[i][j];
                    }
                }

                // Try to add the element again. If the element is still out of bounds, expand the capacity until it is in bounds.
                this->add(row, col, value);
            }
        }

        //---------------------------------------------------------------------------------------------------//
        /* void remove(int row, int col) – clears the entry at the indicated row and column without leaking
         * any memory; if there is no entry at the specified row and column, throw a NoSuchEntry
         * exception (you have been provided with this class in the file NoSuchEntry.h on Pilot).
         *///------------------------------------------------------------------------------------------------//
        void remove(int row, int col)
        {
            // Go to row, column, and see if an Entry exists there. If not, throw a NoSuchEntry Exception. If so, follow these steps below.
            // Ensure that the given row and column exist within the array
            if (row < capacity && col < capacity)
            {
                // An Entry does not exist if row or column = -1.
                // The value of an uninitialized Entry can be anything so value cannot be used to determine if an Entry exists
                if (entries[row][col].getRow() == -1 || entries[row][col].getCol() == -1)
                {
                    throw new NoSuchEntry();
                }
                else // An entry exists, so remove Entry.
                {
                    // The easiest way to do this is to create an empty Entry
                    Entry<T>* enter = new Entry<T>();
                    entries[row][col] = *enter;
                }
            }
            else
            {
                throw new NoSuchEntry();
            }

        }

        //---------------------------------------------------------------------------------------------------//
        /* T getValue(int row, int col) – returns the value of the entry at the indicated row and column;
         * throws a NoSuchEntry exception if there is no entry there.
         *///------------------------------------------------------------------------------------------------//
        T getValue(int row, int col) const
        {
            // Go to row, column, and see if an Entry exists there. If not, throw a NoSuchEntry Exception. If so, follow these steps below.
            if (row < capacity && col < capacity)
            {
                // An Entry does not exist if row or column = -1.
                // The value of an uninitialized Entry can be anything so value cannot be used to determine if an Entry exists
                if (entries[row][col].getRow() == -1 || entries[row][col].getCol() == -1)
                {
                    throw new NoSuchEntry();
                }
                else // An entry exists, so return the value of that Entry
                {
                    return entries[row][col].getValue();
                }
            }
            else
            {
                throw new NoSuchEntry();
            }

        }

        //---------------------------------------------------------------------------------------------------//
        /* int getNumRows() – returns the number of rows in the sparse matrix (i.e. the row of the largest
         * entry in the matrix plus one)
         *///------------------------------------------------------------------------------------------------//
        int getNumRows() const
        {
            // Search through each Entry and find the Entry with the largest row. Return that row + 1
            // Starting from the end of the array and going backwards is the most efficient way of doing this
            // The optimal pattern is searching left through the row, then shifting up
            int returnVal = 0;
            for (int i = capacity - 1; i >= 0; i--)
            {
                for (int j = capacity - 1; j >= 0; j--)
                {
                    if (entries[i][j].getRow() != -1 || entries[i][j].getCol() != -1)
                    {
                        return entries[i][j].getRow() + 1;
                    }
                }
            }
            return returnVal;

        }

        //---------------------------------------------------------------------------------------------------//
        /* int getNumCols() – returns the number of columns in the sparse matrix (i.e. the column of the
         * largest entry in the matrix plus one)
         *///------------------------------------------------------------------------------------------------//
        int getNumCols() const
        {
            // Search through each Entry and find the Entry with the largest column. Return that col + 1
            // The optimal pattern would be to search up the column first, then shift left
            int returnVal = 0;
            for (int j = capacity - 1; j >= 0; j--)
            {
                for (int i = capacity - 1; i >= 0; i--)
                {
                    if (entries[i][j].getRow() != -1 || entries[i][j].getCol() != -1)
                    {
                        return entries[i][j].getCol() + 1;
                    }
                }
            }
            return returnVal;

        }

        // int getNumEntries() – returns the number of non-empty elements in the sparse matrix
        int getNumEntries() const
        {
            // Count the number of entries with actual values in them, return that count.
            int count = 0;

            // A Entry is non-empty is row && col != -1 (It should be fine to use ||. If only one is incorrect then something else is very wrong)
            for (int i = 0; i < capacity; i++)
            {
                for (int j = 0; j < capacity; j++)
                {
                    if (entries[i][j].getRow() != -1 || entries[i][j].getCol() != -1)
                    {
                        count++;
                    }
                }
            }

            return count;

        }

        // Entry<T>** createEntries(SparseMatrix*) - returns a new SparseMatrix based on the parameter's capacity
        Entry<T>** createEntries()
        {

            // Initialize a 2D array of size capacity X capacity
            // Start by creating the columns of size capacity
            Entry<T>** functionEntries = new Entry<T>*[capacity];

            // Initialize rows of size capacity
            for (int i = 0; i < capacity; i++)
            {
                functionEntries[i] = new Entry<T>[capacity];
            }

            return functionEntries;
        }

        // void deleteMatrix() - deallocates the array of entries stored in this SparseMatrix
        void deleteMatrix()
        {
            // Deallocate memory by deleting the list of Entries
            // The list of Entries is two dimensional so each array must be deleted individually
            for (int i = 0; i < capacity; i++)
            {
                delete[] entries[i];
            }
        }

        // See method declaration for explanation
        template <class U> friend ostream& operator<<(ostream& os, const SparseMatrix<U>& sm);
};

//---------------------------------------------------------------------------------------------------//
/* << operator overload – displays the sparse matrix as a two-dimensional array, with empty slots
 * indicated by a hyphen
 *///------------------------------------------------------------------------------------------------//
template <class U> ostream& operator<<(ostream& os, const SparseMatrix<U>& sm)
{
    // Send arguments to os to print
    for (int i = 0; i < sm.capacity; i++)
    {
        for (int j = 0; j < sm.capacity; j++)
        {
            // If Entry is not empty
            if (sm.entries[i][j].getRow() != -1 || sm.entries[i][j].getCol() != -1)
            {
                os << sm.entries[i][j].getValue() << " ";
            }
            else // If entry is empty, print a hyphen in its place
            {
                os  << "- ";
            }
        }
        os << endl;
    }
    os << endl;
    return os;
}
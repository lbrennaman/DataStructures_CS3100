// Logan Brennaman 9/10/21

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------------//
/* The ENTRY Class
 * ---------------
 *
 * The Entry class is used to store one entry in a SparseMatrix.
 * An entry consists of the Data of type T, the row that data was found, and the column that data was found
 */
//-------------------------------------------------------------------------------------------------------//

template <class T> class Entry
{

	private:
		// Fields: the data along with its row and column
		int row;
		int col;
		T value;

	public:
		// Default constructor: Initializes an Entry that does not exist. Hence the row and column exist outside the actual array.
		// The point of this is to initialize an Entry before either a (row, column, and value) exists or another Entry.
		Entry()
		{
			row = -1;
			col = -1;
		}

		// Constructor(row, column, data): Initializes an Entry with the given values when those values are known.
		Entry(int row, int col, T value)
		{
			this->row = row;
			this->col = col;
			this->value = value;
		}

		// Constructor(Entry): Creates a copy of an Entry that is NOT BY REFERENCE.
		Entry(const Entry& other)
		{
			row = other.row;
			col = other.col;
			value = other.value;
		}

		// OVERLOADING the = OPERATOR
		// Overloading the = operator allows one to copy the values of one Entry to another (NOT BY REFERENCE)
		Entry& operator=(const Entry& other)
		{
			row = other.row;
			col = other.col;
			value = other.value;
			return *this;
		}

		// Return the row that this Entry exists in
		int getRow()
		{
			return row;
		}

		// Return the column that this Entry exists in
		int getCol()
		{
			return col;
		}

		// Return the value that this Entry holds
		T getValue()
		{
			return value;
		}

		// Change the value set in this location
		void setValue(T value)
		{
			this->value = value;
		}

};

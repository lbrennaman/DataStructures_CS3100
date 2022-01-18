#include <iostream>
#include "SparseMatrix.h"

using namespace std;

template <class T> void printState(const SparseMatrix<T>& matrix) {
	cout << matrix << endl;
	cout << "rows = " << matrix.getNumRows() << endl;
	cout << "cols = " << matrix.getNumCols() << endl;
	cout << "numEntries = " << matrix.getNumEntries() << endl;
	cout << endl;
}

int main() {

	cout << "Initial creation" << endl;
	SparseMatrix<int> matrix;
	printState(matrix);

	cout << "Fresh add" << endl;
	matrix.add(0, 0, 4);
	printState(matrix);

	cout << "Another fresh add" << endl;
	matrix.add(4, 1, 10);
	printState(matrix);

	cout << "One more fresh add" << endl;
	matrix.add(3, 5, 10);
	printState(matrix);

	cout << "Overwrite add" << endl;
	matrix.add(0, 0, 9);
	printState(matrix);



	cout << "Invalid remove" << endl;
	try {
		matrix.remove(1, 5);
	} catch (NoSuchEntry* e) {
		cout << e->what() << endl << endl;
	}


	cout << "Valid remove (last add)" << endl;
	matrix.remove(3, 5);
	printState(matrix);

	cout << "Valid remove (not last add)" << endl;
	matrix.remove(0, 0);
	printState(matrix);

	cout << "Copy constructor" << endl;
	SparseMatrix<int> copy1(matrix);
	cout << "Done with copy constructor" << endl;
	copy1.add(2, 1, 6);
	printState(copy1);
	printState(matrix);

	cout << "Assignment operator (fresh assignment)" << endl;
	SparseMatrix<int> copy2 = matrix;
	copy2.add(1, 1, 7);
	printState(copy2);
	printState(matrix);

	cout << "Assignment operator (overwriting assignment)" << endl;
	copy2 = matrix;
	copy2.add(2, 2, 9);
	printState(copy2);
	printState(matrix);

	cout << "Template" << endl;
	SparseMatrix<char> otherMatrix;
	otherMatrix.add(0, 0, 'A');
	printState(otherMatrix);

}

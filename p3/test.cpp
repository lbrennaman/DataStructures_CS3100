#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "HashTable.cpp"

// p3_4: hashtwo, doublehashProbe

using namespace std;

unsigned seed = time(0);

int main() {

	srand(seed);

	// Make a HashTable
	HashTable<string>* hash = new HashTable<string>();
	int collisions = 0;

	string a = "";

	int lower = 1;
    int upper = 10000000;
    int num = 0;
/*
	hash->insert(1053, "A", collisions);
	hash->insert(10053, "B", collisions);
	hash->insert(100053, "C", collisions);
	cout << *hash << endl;
	hash->remove(10053, a);
	cout << *hash << endl;
	cout << hash->find(10053, a) << endl;
	*/
/*
	// Insert numbers 1 - 999
	for (int i = 1; i <= 1000; i++)
	{
		cout << i << ": " << hash->insert(i, "String", collisions) << endl;
		if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900)
		{
			//cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}
	*/
/*
	// Find starting from 1 and going to 999
	for (int i = 1; i <= 1000; i++)
	{
		cout << i << " found: " << hash->find(i, a) << endl;

	}

	// Remove starting from 1 and going to 999
	for (int i = 1; i <= 1000; i++)
	{
		cout << i << " remove: " << hash->remove(i, a) << endl;
	}

	// Find starting from 1 and going to 999
	for (int i = 1; i <= 1000; i++)
	{
		cout << i << " found: " << hash->find(i, a) << endl;

	}

	for (int i = 1; i <= 1000; i++)
	{
		cout << i << ": " << hash->insert(i, "String", collisions) << endl;
		if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900)
		{
			cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}
	*/

/*
	// Insert numbers 500-999, then 1 - 499
	for (int i = 500; i <= 1000; i++)
	{
		cout << i << ": " << hash->insert(i, "String", collisions) << endl;
		if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900)
		{
			cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}
	for (int i = 1; i <= 500; i++)
	{
		cout << i << ": " << hash->insert(i, "String", collisions) << endl;
		if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900)
		{
			cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}

	// Find starting from 500 and going to 999 then 1 - 499
	for (int i = 500; i <= 1000; i++)
	{
		cout << i << " found: " << hash->find(i, a) << endl;

	}
	for (int i = 1; i <= 500; i++)
	{
		cout << i << " found: " << hash->find(i, a) << endl;

	}

	// Remove starting from 500 and going to 999 then 1 - 499
	for (int i = 500; i <= 1000; i++)
	{
		cout << i << " remove: " << hash->remove(i, a) << endl;

	}
	for (int i = 1; i <= 500; i++)
	{
		cout << i << " remove: " << hash->remove(i, a) << endl;

	}
	*/


	// Testing random numbers 1 - 1000
	cout << "Insert\n";
	for (int i = 0; i < 1000; i++)
	{
		num = rand() % ((upper + 1) - lower) + lower;
		//cout << "Key: " << num << endl;
		hash->insert(num, "String", collisions);
		if (i == 99 || i == 199 || i == 299 || i == 399 || i == 499 || i == 599 || i == 699 || i == 799 || i == 899)
		{
			cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}
	//cout << *hash << endl;

/*
	cout << "Find1\n";
	for (int i = 0; i < 1000; i++)
	{
		num = rand() % ((upper + 1) - lower) + lower;
		//cout << "Key: " << num << endl;
		//cout << i << " Found: " << hash->find(num, a);
		if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900)
		{
			cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}
	*/
/*
	cout << "\nRemove\n";
	for (int i = 0; i < 1000; i++)
	{
		num = rand() % ((upper + 1) - lower) + lower;
		//cout << "Key: " << num << endl;
		hash->remove(num, a);
		if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900)
		{
			cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}
*/
	/*
	cout << "Find2\n";
	for (int i = 0; i < 1000; i++)
	{
		num = rand() % ((upper + 1) - lower) + lower;
		//cout << "Key: " << num << endl;
		//cout << i << " Found: " << hash->find(num, a);
		if (i == 100 || i == 200 || i == 300 || i == 400 || i == 500 || i == 600 || i == 700 || i == 800 || i == 900)
		{
			cout << "alpha: " << hash->alpha() << endl << "Probe accesses: " << collisions << endl << flush;
		}
	}
	*/



	//cout << *hash << endl << endl;
	cout << "Collisions: " << collisions << endl;
}

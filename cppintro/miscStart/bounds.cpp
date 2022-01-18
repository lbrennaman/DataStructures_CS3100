/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Activity: Write a function that takes an UPPER AND LOWER BOUND and a LENGTH and RETURNS AN ARRAY OF RANDOM INTEGERS between those bounds.           /
Additionally, after the function completes, the UPPER AND LOWER BOUND should be set to the MAXIMUM AND MINIMUM VALUES IN THE ARRAY, respectively.   /
(Note, you use rand() % n to generate a random number between 0 and n-1, inclusive.                                                                 /
                                                                                                                                                    /
Int upper = 100;                                                                                                                                    /
                                                                                                                                                    /
Int lower = 1;                                                                                                                                      /
                                                                                                                                                    /
int arr[] = my_function(upper, lower, 5);                                                                                                           /
                                                                                                                                                    /
[32, 78, 31, 1, 47] — returned array (for example)                                                                                                  /
                                                                                                                                                    /
Upper = 78                                                                                                                                          /
                                                                                                                                                    /
Lower = 1                                                                                                                                           /
*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
int* ranArray(int&, int&, int);

// Global variables
// int dum = 0;                // Dummy variable used to initialize pointers
unsigned seed = time(0);    // A seed for random number generation

// Main method
int main(void)
{

    // Initialize
    srand(seed);
    int upper = 0;
    int lower = 0;
    int length = 0;

    // Get values
    cout << "Upper: ";
    cin >> upper;
    cout << "\nLower: ";
    cin >> lower;
    cout << "\nlength: ";
    cin >> length;
    cout << endl;

    // Run function

    /* The dum way
    int* array = &dum; // Sets the start of the array to the address of the dummy variable
    array = ranArray(upper, lower, length); // Sets array to the starting address of the function's array
    */

    // Running function properly
    int* array = ranArray(upper, lower, length);

    // Print array
    cout << "[ ";
    for (int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << "]" << endl;

    // Print upper and lower
    cout << "Upper: " << upper << endl << "Lower: " << lower << endl;
}

// Functions
int* ranArray(int& upper, int& lower, int length)
{

    // Sets the array to the address of the dummy variable
    // int* mArray = &dum; // The dum way
    int* mArray = new int[length];

    // Create a random number between upper and lower a length number of times
    for (int i = 0; i < length; i++) {
        int number = rand() % ((upper + 1) - lower) + lower;
        mArray[i] = number;
    }

    // Search array, if array[i] < lower, set lower to array[i]
    // Do the same for upper
    lower = mArray[0];
    upper = mArray[0];
    for (int i = 1; i < length; i++) {
        if (mArray[i] < lower) {
            lower = mArray[i];
        }
        if (mArray[i] > upper) {
            upper = mArray[i];
        }
    }

    return mArray;

}
#include <iostream>

using namespace std;

int main(void)
{

    // Initialization 1
    int arr1[5] = {1, 2, 3, 4, 5};

    // Initialization 2
    //int* arr2[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << endl;
    }
}
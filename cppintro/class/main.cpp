#include <iostream>
#include "classy.h"

using namespace std;

// Compilation. Does not use make
// g++ main.cpp classy.cpp classy.h

void classMaker();

int main(void)
{
    classMaker();
}

void classMaker()
{
    long val = 0;
    for (int i = 0; i < 100000000; i++)
    {
        // Creating the class on the heap
        classy* cass = new classy();
        val += cass->getSize();

        /* Creating the class on the stack
        classy cass;
        val += cass.getSize();
        */
    }
    cout << "val = " << val << endl;

}
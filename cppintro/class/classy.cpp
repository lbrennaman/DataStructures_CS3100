#include <iostream>
#include "classy.h"

using namespace std;

classy::classy()
{
    size = 1000;
    values = new int[size];
}

classy::~classy()
{
    delete[] values;
    size = 0;
}

int classy::getSize()
{
    return size;
}


#include <iostream>

#include "Kaku.h"
#include "Futatsu.h"

using namespace std;

int main(void)
{
    Kaku* kami = new Kaku();
    kami->miseru();
    delete kami;
}
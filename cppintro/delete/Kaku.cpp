#include <iostream>
#include "Kaku.h"
#include "Futatsu.h"

using namespace std;

Kaku::Kaku()
{
    cout << "Kaite imasu..." << endl;
    size = 10;
    array = new Futatsu*[size];
    for (int i = 0; i < size; i++)
    {
        cout << i*10 << ": ";
        array[i] = new Futatsu[size];
        cout << endl;
    }
}

Kaku::~Kaku()
{
    cout << "Array points to: " << array;

    for (int i = 0; i < 10; i++)
    {
        cout << i*10 << ": ";
        delete[] array[i];
        cout << endl;
    }

    cout << "Kaite owari shimashita." << endl;
}

void Kaku::miseru()
{
    int number = returnNum(this);
    cout << "Atarashii ban wa: " << number << endl;
}

int Kaku::returnNum(Kaku* kami)
{
    int newNum = kami->size;
    newNum += 5;
    return newNum;
}
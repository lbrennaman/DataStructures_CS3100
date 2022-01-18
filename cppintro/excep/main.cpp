#include <iostream>
#include "dexception.cpp"

using namespace std;

int returnA();

int main(void)
{

    try
    {
        int a = returnA();
    } catch (exception e) {
        cout << e.what() << endl;
    }

}

int returnA() {
    throw new dexception();
    return 10;
}

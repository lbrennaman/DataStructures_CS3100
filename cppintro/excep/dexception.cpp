#include <iostream>
#include <exception>

using namespace std;

class dexception : public exception
{
    virtual const char* what() const throw()
    {
        return "My exception happened";
    }
};
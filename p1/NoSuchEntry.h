// Logan Brennaman 9/10/21

#include <exception>

using namespace std;

//-------------------------------------------------------------------------------------------------------//
/*
 * The NO_SUCH_ENTRY CLASS
 * -----------------------
 *
 * Throws an exception in these cases:
 *
 *  You can remove an item from a specified row and column within the sparse matrix without introducing a
 *  memory leak; trying to remove an item from an empty location throws a NoSuchEntry exception.
 *
 *  You can retrieve the value (via getValue) from a specified row and column within the sparse matrix;
 *  trying to get a value from an empty location throws a NoSuchEntry exception.
 */
 //-------------------------------------------------------------------------------------------------------//

class NoSuchEntry : public exception
{

    public:
        virtual const char* what() const throw()
        {
            return "No entry exists at this location";
        }

};


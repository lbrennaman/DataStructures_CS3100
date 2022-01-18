#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{

    /* Writing to a file
    --------------------------------------
    ofstream myFile;
    myFile.open("text.txt");
    myFile << "Writing this to a file.\n";
    myFile.close();
    --------------------------------------
    */

    /* Reading a string from a file
    --------------------------------------
    string line;
    ifstream myFile;
    myFile.open("text.txt");
    if (myFile.is_open())
    {
        while (getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
    }
    --------------------------------------
    */

    /* Reading integers from a file
    --------------------------------------
    int line = 0;
    ifstream myFile;
    myFile.open("text.txt");
    if (myFile.is_open())
    {
        while (myFile >> line)
        {
            cout << line << endl;
        }
        myFile.close();
    }
    --------------------------------------
    */

}
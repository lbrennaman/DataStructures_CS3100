// Driver program created by Logan Brennaman on 9/25/21
#include <iostream>
#include <string>

#include "gTree.h"
#include "gTree.cpp"

using namespace std;

// Driver program:
// "a driver program creates a single directory called “root” and then continually waits for
// the user to type in a command and performs the requested action"

int main(void)
{

    // Initialize a gTree called "root"
    gTree<string>* root = new gTree<string>("root");

    // Keep track of the current tree (current directory)
    gTree<string>* current = root;

    // Accept input while input != "quit"
    string input = "";

    // Place to dump extra input if provided
    string garbo = "";

    while (input != "quit")
    {
        // Take in an input and compare it to the options
        cin >> input;

        if (input == "pwd")
        {
            // Based off of the pwd command, print the path to the directory the user is in
            cout << current->pwd() << endl;
        }
        else if (input == "ls")
        {
            // Print all existing children of the current directory
            current->ls();
        }
        else if (input == "exists") // Accounts for exists <directory>
        {
            // Take in a second argument if not given one before
            cin >> input;

            // Given an input, tell the user if the respective node exists in the tree
            if (root->exists(input) == 1)
                cout << input << " exists" << endl;
            else
                cout << input << " does not exist" << endl;
        }
        else if (input == "cd") // Accounts for cd <dir> and cd ..
        {
            // Take in a second argument if not given one before
            cin >> input;

            // Change the current directory to the one input if able
            current = current->cd(input);
        }
        else if (input == "mkdir") // Accounts for mkdir <dir>
        {
            // Take in a second argument if not given one before
            cin >> input;

            // Make a new child (new directory) for the current node (directory)
            current->mkdir(input);
        }
        else if (input == "rmdir") // Accounts for rmdir <dir>
        {
            // Take in a second argument if not given one before
            cin >> input;

            // Remove a directory if that directory exists
            current->rmdir(input);
        }
        else if (input == "countdir")
        {
            // Print the number of directories that exist in this subtree
            cout << (current->countdir() + 1) << endl;
        }
        else if (input == "showtree")
        {
            // Print the subtree starting from the current node for the user to see
            current->showtree(0);
        }
        else if (input != "quit")
        { // If it was none of these commands, print "Unknown command"
            cout << "Unknown command" << endl;
        }

        // Flush cin and cout before continuing in case cin accidentally holds a value in its stream
        getline(cin, garbo);
        cout << flush;
    }

    // End by deleting the entire tree to free memory
    delete root;

}
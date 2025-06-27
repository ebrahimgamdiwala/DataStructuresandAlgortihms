#include <iostream>
#include <vector>

using namespace std;

int main()
{
    /*
    VECTOR - C++ STL (Standard Template Library)
    ---------------------------------------------
    A vector is a dynamic array that can grow or shrink in size.
    - Stored in contiguous memory locations.
    - Offers fast random access (like arrays).
    - Can add/remove elements at the end efficiently (O(1) on average).
    - Automatically manages memory (unlike raw arrays).
    */

    // Different ways to initialize a vector
    // vector<int> vec;
    // vector<int> vec = {1, 2, 3};
    vector<int> vec(3, 0); // The first argument here is the size of the vector and the second argument is the value with which each element of the vector is initialized with

    cout << vec[0] << endl;
    cout << vec[1] << endl;
    cout << vec[2] << endl;

    // For each loop for traversing through a vector
    for (int val : vec)
    {
        cout << val << endl;
    }

    return 0;
}
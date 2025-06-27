#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> vec = {'a', 'b', 'c', 'd'};
   
    cout << "Size of the vector is : "<< vec.size() << endl;
    vec.push_back('h');
    vec.push_back('h');
    vec.push_back('h');
    cout << "Capacity of the vector is : "<< vec.capacity() << endl; // The capacity of the vector increases by twice its original size once it reaches its maximum and new element is added

    // For each loop for traversing through a vector
    for (char val : vec)
    {
        cout << val << endl;
    }
    
    return 0;
}
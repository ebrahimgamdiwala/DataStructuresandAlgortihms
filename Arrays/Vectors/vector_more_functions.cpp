#include <iostream>
#include <vector>  // Required to use vectors

using namespace std;

int main() {
    // Declare and initialize a vector of integers
    vector<int> numbers;

    // Add elements using push_back()
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    // Access elements using indexing and at()
    cout << "Element at index 0 using indexing: " << numbers[0] << endl;
    cout << "Element at index 2 using at(): " << numbers.at(2) << endl;

    // Access first and last elements using front() and back()
    cout << "First element using front(): " << numbers.front() << endl;
    cout << "Last element using back(): " << numbers.back() << endl;

    // Modify values using at(), front(), and back()
    numbers.at(2) = 35;           // Modify third element
    numbers.front() = 5;          // Modify first element
    numbers.back() = 100;         // Modify last element

    // Display updated vector
    cout << "Updated vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Size of vector
    cout << "Size of vector: " << numbers.size() << endl;

    // Remove last element using pop_back()
    numbers.pop_back();
    cout << "After pop_back, size: " << numbers.size() << endl;

    // Insert an element at a specific position
    numbers.insert(numbers.begin() + 1, 15);  // Insert 15 at index 1
    cout << "After insertion: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Erase element at index 0
    numbers.erase(numbers.begin());
    cout << "After erasing first element: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

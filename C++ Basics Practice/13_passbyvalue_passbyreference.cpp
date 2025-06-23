#include <iostream>
using namespace std;

// Function demonstrating pass by value
void passByValue(int x) {
    x = x + 10;
    cout << "Inside passByValue, x = " << x << endl;
}

// Function demonstrating pass by reference
void passByReference(int &x) {
    x = x + 10;
    cout << "Inside passByReference, x = " << x << endl;
}

int main() {
    int a = 5;
    int b = 5;

    cout << "Before passByValue, a = " << a << endl;
    passByValue(a);
    cout << "After passByValue, a = " << a << endl << endl;

    cout << "Before passByReference, b = " << b << endl;
    passByReference(b);
    cout << "After passByReference, b = " << b << endl;

    return 0;
}

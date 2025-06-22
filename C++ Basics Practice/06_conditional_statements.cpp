#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;
    cout << "\n";

    // 1. Simple if statement
    if (n == 0) {
        // Check if the number is zero
        cout << "The number is zero\n";
    }

    // 2. if-else statement
    if (n >= 0) {
        // Check if the number is positive
        cout << n << " is positive\n";
    } else {
        // If not positive, then it's negative
        cout << n << " is negative\n";
    }

    // 3. Nested if statement
    if (n >= 0) {
        // Inside positive check, now check even or odd
        if (n % 2 == 0) {
            cout << n << " is a positive even number\n";
        } else {
            cout << n << " is a positive odd number\n";
        }
    }

    // 4. if-else-if ladder
    cout << "\nChecking range using if-else-if ladder:\n";
    if (n < 0) {
        // Negative number case
        cout << "Number is negative.\n";
    } else if (n == 0) {
        // Exact zero
        cout << "Number is zero.\n";
    } else if (n > 0 && n <= 100) {
        // Between 1 and 100
        cout << "Number is in the range 1 to 100.\n";
    } else {
        // Greater than 100
        cout << "Number is greater than 100.\n";
    }

    // 5. switch statement
    cout << "\nUsing switch to check for specific small values:\n";
    switch (n) {
        case 0:
            // When n is 0
            cout << "Number is zero\n";
            break;
        case 1:
            // When n is 1
            cout << "Number is one\n";
            break;
        case 2:
            // When n is 2
            cout << "Number is two\n";
            break;
        default:
            // When n is not 0, 1, or 2
            cout << "Number is not 0, 1, or 2\n";
    }

    return 0;
}

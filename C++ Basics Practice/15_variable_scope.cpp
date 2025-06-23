#include <iostream>
using namespace std;

// Global variable (accessible throughout the entire file)
int globalVar = 100;

void demoFunctionScope() {
    // Local variable (only accessible within this function)
    int localVar = 50;

    cout << "Inside demoFunctionScope():\n";
    cout << "  globalVar = " << globalVar << "\n";   // Accessible
    cout << "  localVar = " << localVar << "\n";     // Accessible
}

int main() {
    cout << "Inside main():\n";
    cout << "  globalVar = " << globalVar << "\n";   // Accessible

    // Block scope example
    if (true) {
        // Variable with block scope (accessible only within this block)
        int blockVar = 25;
        cout << "  blockVar inside if-block = " << blockVar << "\n";

        // Shadowing: a local variable with the same name as a global variable
        int globalVar = 10;
        cout << "  Shadowed globalVar = " << globalVar << " (local version)\n";
    }

    // The following line would cause a compile-time error because blockVar is out of scope:
    // cout << blockVar;

    demoFunctionScope();  // Call the function

    // The following line would cause a compile-time error because localVar is not visible in main():
    // cout << localVar;

    return 0;
}

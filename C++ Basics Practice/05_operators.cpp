#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Enter a number 'a':\n";
    cin >> a;
    cout << "Enter a number 'b':\n";
    cin >> b;
    cout << "\n\n";

    // 1. Arithmetic Operators
    cout << "Arithmetic Operators:\n";
    cout << "Addition = " << (a + b) << "\n";
    cout << "Subtraction = " << (a - b) << "\n";
    cout << "Multiplication = " << (a * b) << "\n";
    cout << "Division = " << (a / b) << "\n";
    cout << "Remainder/Modulo = " << (a % b) << "\n\n";

    // 2. Relational Operators
    cout << "Relational Operators:\n";
    cout << "a == b: " << (a == b) << "\n";
    cout << "a != b: " << (a != b) << "\n";
    cout << "a > b: " << (a > b) << "\n";
    cout << "a < b: " << (a < b) << "\n";
    cout << "a >= b: " << (a >= b) << "\n";
    cout << "a <= b: " << (a <= b) << "\n\n";

    // 3. Logical Operators
    cout << "Logical Operators:\n";
    cout << "(a > 0 && b > 0): " << ((a > 0 && b > 0) ? "true" : "false") << "\n";
    cout << "(a > 0 || b > 0): " << ((a > 0 || b > 0) ? "true" : "false") << "\n";
    cout << "!(a > 0): " << (!(a > 0) ? "true" : "false") << "\n\n";

    // 4. Bitwise Operators
    cout << "Bitwise Operators:\n";
    cout << "a & b (AND): " << (a & b) << "\n";
    cout << "a | b (OR): " << (a | b) << "\n";
    cout << "a ^ b (XOR): " << (a ^ b) << "\n";
    cout << "~a (NOT): " << (~a) << "\n";
    cout << "a << 1 (Left Shift): " << (a << 1) << "\n";
    cout << "a >> 1 (Right Shift): " << (a >> 1) << "\n\n";

    // 5. Assignment Operators
    cout << "Assignment Operators:\n";
    int x = a;
    cout << "x = a: " << x << "\n";
    x += b;
    cout << "x += b: " << x << "\n";
    x -= b;
    cout << "x -= b: " << x << "\n";
    x *= b;
    cout << "x *= b: " << x << "\n";
    x /= b;
    cout << "x /= b: " << x << "\n";
    x %= b;
    cout << "x %= b: " << x << "\n\n";

    // 6. Increment and Decrement Operators
    cout << "Increment and Decrement Operators:\n";
    int y = a;
    cout << "Original y: " << y << "\n";
    cout << "Post-increment y++: " << y++ << "\n";
    cout << "After Post-increment y: " << y << "\n";
    cout << "Pre-increment ++y: " << ++y << "\n";
    cout << "Post-decrement y--: " << y-- << "\n";
    cout << "After Post-decrement y: " << y << "\n";
    cout << "Pre-decrement --y: " << --y << "\n\n";

    // 7. Ternary Operator
    cout << "Ternary Operator:\n";
    int max = (a > b) ? a : b;
    cout << "Max of a and b = " << max << "\n\n";

    // 8. sizeof and comma operators
    cout << "Other Operators:\n";
    cout << "Size of int: " << sizeof(int) << " bytes\n";
    int z;
    z = (a++, b++, a + b);  // Comma operator: evaluates left to right, returns last
    cout << "Result using comma operator: " << z << "\n";

    //An example of implicit type conversion
    cout<<(5/2)<<"\n";
    cout<<(5/(double)2);
    
    return 0;
}

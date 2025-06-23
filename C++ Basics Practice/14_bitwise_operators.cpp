#include <iostream>
#include <bitset>
using namespace std;

int main() {
    unsigned int a = 12; // binary: 00001100
    unsigned int b = 5;  // binary: 00000101

    // Show values in binary
    cout << "a = " << a << " (" << bitset<8>(a) << ")\n";
    cout << "b = " << b << " (" << bitset<8>(b) << ")\n\n";

    // 1. Bitwise AND (&)
    // Bits are set to 1 only if both corresponding bits are 1
    unsigned int andResult = a & b;
    cout << "a & b = " << andResult << " (" << bitset<8>(andResult) << ")\n";

    // 2. Bitwise OR (|)
    // Bits are set to 1 if at least one of the corresponding bits is 1
    unsigned int orResult = a | b;
    cout << "a | b = " << orResult << " (" << bitset<8>(orResult) << ")\n";

    // 3. Bitwise XOR (^)
    // Bits are set to 1 if only one of the corresponding bits is 1 (exclusive OR)
    unsigned int xorResult = a ^ b;
    cout << "a ^ b = " << xorResult << " (" << bitset<8>(xorResult) << ")\n";

    // 4. Bitwise NOT (~)
    // Inverts all bits (1 becomes 0, 0 becomes 1)
    unsigned int notA = ~a;
    cout << "~a = " << notA << " (" << bitset<8>(notA) << ")\n";

    // 5. Left Shift (<<)
    // Shifts bits to the left, inserting 0s on the right
    unsigned int leftShift = a << 1;
    cout << "a << 1 = " << leftShift << " (" << bitset<8>(leftShift) << ")\n";

    // 6. Right Shift (>>)
    // Shifts bits to the right, discarding bits on the right
    unsigned int rightShift = a >> 1;
    cout << "a >> 1 = " << rightShift << " (" << bitset<8>(rightShift) << ")\n";

    return 0;
}

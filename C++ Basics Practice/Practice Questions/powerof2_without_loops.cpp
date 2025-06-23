#include <iostream>
using namespace std;

bool isPowerOf2Bitwise(unsigned int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    unsigned int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOf2Bitwise(num))
        cout << num << " is a power of 2 (checked using bitwise).\n";
    else
        cout << num << " is NOT a power of 2 (checked using bitwise).\n";

    return 0;
}

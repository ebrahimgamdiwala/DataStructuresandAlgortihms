#include <iostream>
using namespace std;

bool isPowerOf2Loop(unsigned int n) {
    if (n == 0) return false;

    unsigned int power = 1;
    while (power <= n) {
        if (power == n)
            return true;
        power *= 2;
    }
    return false;
}

int main() {
    unsigned int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOf2Loop(num))
        cout << num << " is a power of 2\n";
    else
        cout << num << " is NOT a power of 2\n";

    return 0;
}

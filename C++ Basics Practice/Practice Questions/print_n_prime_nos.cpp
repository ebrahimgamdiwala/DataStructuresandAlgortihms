#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number < 2) return false;
    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) return false;
    }
    return true;
}

void printPrimesUpTo(int n) {
    for (int i = 1; i <= n; ++i) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Prime numbers from 1 to " << n << " are:\n";
    printPrimesUpTo(n);

    return 0;
}

#include <iostream>
using namespace std;

long long factorial(int number) {
    long long result = 1;
    for (int i = 2; i <= number; ++i) {
        result *= i;
    }
    return result;
}

long long computeNCR(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n = 5, r = 2;
    long long nCr = computeNCR(n, r);

    cout << "nCr for n = " << n << " and r = " << r << " is: " << nCr << "\n";

    return 0;
}

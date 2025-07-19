// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 1; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    cout << fib(10) << endl;
    return 0;
}

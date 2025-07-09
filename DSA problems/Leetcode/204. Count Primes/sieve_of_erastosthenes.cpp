#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i] == true) {
            count++;
            for (int j = i * 2; j < n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    return count;
}

int main() {
    int n = 100; 
    int result = countPrimes(n);
    cout << "Number of primes less than " << n << " is: " << result << endl;
    return 0;
}

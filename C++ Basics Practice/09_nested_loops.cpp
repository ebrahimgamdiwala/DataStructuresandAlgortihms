#include <iostream>
using namespace std;

int main() {
    // Outer loop for base numbers (e.g., 1 to 5)
    for (int i = 1; i <= 5; i++) {
        // Inner loop for multipliers (e.g., 1 to 10)
        for (int j = 1; j <= 10; j++) {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << endl; 
    }

    return 0;
}

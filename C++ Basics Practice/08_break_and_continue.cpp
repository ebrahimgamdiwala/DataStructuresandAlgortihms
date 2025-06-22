#include <iostream>
using namespace std;

int main() {

    // Loop from 1 to 10
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            cout << "Skipping number 5 using continue.\n";
            continue;  
        }
        if (i == 8) {
            cout << "Breaking the loop at 8.\n";
            break;  
        }
        cout << "Current number: " << i << endl;
    }

    return 0;
}

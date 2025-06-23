#include <iostream>
using namespace std;

int reverseNumber(int num) {
    int reversed = 0;

    while (num != 0) {
        int digit = num % 10;           // Extract last digit
        reversed = reversed * 10 + digit; // Append digit to reversed number
        num /= 10;                      // Remove last digit from original number
    }

    return reversed;
}

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    int reversedNumber = reverseNumber(number);
    cout << "Reversed number: " << reversedNumber << endl;

    return 0;
}

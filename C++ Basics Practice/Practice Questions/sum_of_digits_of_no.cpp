#include <iostream>
using namespace std;

int sumOfDigits(int number) {
    int digitSum = 0;

    while (number > 0) {
        int lastDigit = number % 10;
        digitSum += lastDigit;
        number /= 10;
    }

    return digitSum;
}

int main() {
    int inputNumber = 145;
    int result = sumOfDigits(inputNumber);

    cout << "The sum of the digits of the number is: " << result << "\n";

    return 0;
}

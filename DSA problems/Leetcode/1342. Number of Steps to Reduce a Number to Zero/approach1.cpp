// Required for input/output operations, like printing to the console.
#include <iostream>

using namespace std;

/**
 * @brief Calculates the number of steps to reduce a non-negative integer to zero.
 *
 * The rules for reduction are:
 * - If the current number is even, you have to divide it by 2.
 * - If the current number is odd, you have to subtract 1 from it.
 *
 * @param num The non-negative integer to reduce.
 * @return int The total number of steps taken.
 *
 * ## Overall Approach
 * The function works by directly simulating the process described. It uses a `while` loop
 * that continues as long as the number is greater than zero. Inside the loop, it checks
 * if the number is even or odd and performs the appropriate operation, incrementing a
 * step counter each time. The loop terminates when the number reaches zero, and the
 * total count is returned.
 *
 * ## Time Complexity: O(log N)
 * The time complexity is logarithmic with respect to the input number `num` (N).
 * This is because dividing an even number by 2 is equivalent to a bitwise right shift,
 * which rapidly reduces the magnitude of the number. Subtracting 1 from an odd number
 * always makes it even, guaranteeing a division by 2 in the next step. The number of
 * operations is proportional to the number of bits in the binary representation of `num`,
 * which is log₂(N).
 *
 * ## Space Complexity: O(1)
 * The algorithm uses only a fixed number of variables (`num`, `count`) regardless of the
 * size of the input. Therefore, the space complexity is constant.
 */
int numberOfSteps(int num) {
    // `count` will keep track of the number of operations performed.
    int count = 0;

    // The loop continues until the number is reduced to 0.
    while (num > 0) {
        // STEP 1: Check if the number is even.
        // The modulo operator (%) returns the remainder of a division.
        // If num % 2 is 0, the number is even.
        if (num % 2 == 0) {
            // If even, divide the number by 2.
            num /= 2;
        } else {
            // If odd, subtract 1 from the number.
            num -= 1;
        }
        // STEP 2: Increment the step counter for the operation just performed.
        count++;
    }

    // Return the total count of steps taken.
    return count;
}

int main() {
    // Create a hardcoded input number for testing.
    int testNum1 = 14;
    cout << "Calculating steps for number: " << testNum1 << endl;
    int steps1 = numberOfSteps(testNum1);
    cout << "Number of steps: " << steps1 << endl; // Expected: 6
    cout << "---" << endl;

    int testNum2 = 8;
    cout << "Calculating steps for number: " << testNum2 << endl;
    int steps2 = numberOfSteps(testNum2);
    cout << "Number of steps: " << steps2 << endl; // Expected: 4
    cout << "---" << endl;

    int testNum3 = 123;
    cout << "Calculating steps for number: " << testNum3 << endl;
    int steps3 = numberOfSteps(testNum3);
    cout << "Number of steps: " << steps3 << endl; // Expected: 12
    cout << "---" << endl;

    return 0;
}

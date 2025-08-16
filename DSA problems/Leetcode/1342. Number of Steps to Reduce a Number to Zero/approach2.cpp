// Required for input/output operations, like printing to the console.
#include <iostream>

using namespace std;

/**
 * @brief Calculates the number of steps to reduce a non-negative integer to zero using bitwise operations.
 *
 * The rules for reduction are:
 * - If the current number is even, you have to divide it by 2.
 * - If the current number is odd, you have to subtract 1 from it.
 *
 * @param num The non-negative integer to reduce.
 * @return int The total number of steps taken.
 *
 * ## Overall Approach
 * This function is a more optimized version that uses bitwise operations to achieve the same
 * result as the arithmetic version. It directly simulates the process in a `while` loop.
 * - To check for evenness, it uses a bitwise AND (`&`) with 1. If the result is 0, the
 * number's least significant bit is 0, meaning it's even.
 * - To divide by 2, it uses the bitwise right shift operator (`>>= 1`), which is often
 * faster than arithmetic division.
 *
 * ## Time Complexity: O(log N)
 * The complexity is logarithmic with respect to the input `num` (N). Each right shift (`>>`)
 * effectively halves the number, and each subtraction (`--`) on an odd number guarantees a
 * right shift in the next step. The number of operations is proportional to the number of
 * bits in the binary representation of `num`, which is log₂(N).
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
        // STEP 1: Check if the number is even using a bitwise AND.
        // `(num & 1)` isolates the least significant bit (LSB).
        // If the LSB is 0, the number is even. e.g., 14 (1110) & 1 (0001) = 0.
        if ((num & 1) == 0) {
            // If even, perform a bitwise right shift by 1.
            // This is equivalent to integer division by 2. e.g., 14 (1110) >> 1 = 7 (0111).
            num >>= 1;
        } else {
            // If odd (LSB is 1), subtract 1 from the number.
            // This always makes the number even for the next step. e.g., 7 (0111) - 1 = 6 (0110).
            num--;
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

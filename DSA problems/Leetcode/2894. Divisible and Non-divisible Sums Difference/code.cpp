// Required for input/output operations.
#include <iostream>

using namespace std;

/**
 * @brief Calculates the difference between the sum of numbers not divisible by `m` and the sum of numbers divisible by `m` in the range [1, n].
 *
 * @param n The upper bound of the range of numbers to consider (inclusive).
 * @param m The divisor used to categorize the numbers.
 * @return int The calculated difference (num1 - num2).
 *
 * ## Overall Approach
 * The function iterates through every integer `i` from 1 to `n`. In each iteration, it checks
 * if `i` is divisible by `m`.
 *
 * 1.  **Initialization:** Two accumulator variables, `num1` and `num2`, are initialized to 0.
 * `num1` will store the sum of numbers *not* divisible by `m`.
 * `num2` will store the sum of numbers *that are* divisible by `m`.
 *
 * 2.  **Iteration and Categorization:** A `for` loop runs from `i = 1` to `n`.
 * - Inside the loop, the condition `i % m == 0` checks for divisibility.
 * - If `true`, `i` is added to `num2`.
 * - If `false`, `i` is added to `num1`.
 *
 * 3.  **Return Value:** After the loop has processed all numbers, the function returns the
 * final difference between the two sums, `num1 - num2`.
 *
 * ## Time Complexity: O(N)
 * The function uses a single `for` loop that runs `n` times. All operations inside the loop
 * (modulo, addition) are constant time. Therefore, the time complexity is linear with
 * respect to the input `n`.
 *
 * ## Space Complexity: O(1)
 * The function uses a fixed number of variables (`num1`, `num2`, `i`) regardless of the size
 * of the input `n`. No auxiliary data structures that scale with the input are used.
 * Therefore, the space complexity is constant.
 */
int differenceOfSums(int n, int m) {
    // num1 will hold the sum of integers not divisible by m.
    int num1 = 0;
    // num2 will hold the sum of integers divisible by m.
    int num2 = 0;

    // Loop through each integer from 1 to n (inclusive).
    for (int i = 1; i <= n; i++) {
        // Check if the current integer 'i' is divisible by 'm'.
        // The modulo operator (%) returns 0 if 'i' is perfectly divisible by 'm'.
        if (i % m == 0) {
            // If it is divisible, add it to num2.
            num2 += i;
        } else {
            // Otherwise, add it to num1.
            num1 += i;
        }
    }
    // Return the final difference as specified by the problem.
    return num1 - num2;
}

int main() {
    // --- Test Case 1 ---
    int n1 = 10, m1 = 3;
    // num1 = 1+2+4+5+7+8+10 = 37
    // num2 = 3+6+9 = 18
    // Difference = 37 - 18 = 19
    cout << "n = " << n1 << ", m = " << m1 << endl;
    cout << "Difference of sums: " << differenceOfSums(n1, m1) << endl; // Expected: 19
    cout << "--------------------" << endl;

    // --- Test Case 2 ---
    int n2 = 5, m2 = 6;
    // num1 = 1+2+3+4+5 = 15
    // num2 = 0
    // Difference = 15 - 0 = 15
    cout << "n = " << n2 << ", m = " << m2 << endl;
    cout << "Difference of sums: " << differenceOfSums(n2, m2) << endl; // Expected: 15
    cout << "--------------------" << endl;

    // --- Test Case 3 ---
    int n3 = 5, m3 = 1;
    // num1 = 0
    // num2 = 1+2+3+4+5 = 15
    // Difference = 0 - 15 = -15
    cout << "n = " << n3 << ", m = " << m3 << endl;
    cout << "Difference of sums: " << differenceOfSums(n3, m3) << endl; // Expected: -15
    cout << "--------------------" << endl;

    return 0;
}

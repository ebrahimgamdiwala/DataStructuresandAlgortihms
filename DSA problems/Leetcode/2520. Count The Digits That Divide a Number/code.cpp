// Required for input/output operations.
#include <iostream>

using namespace std;

/**
 * @brief A helper function to check if a number is evenly divisible by a digit.
 * @param num The original number.
 * @param dig The digit to check for divisibility.
 * @return bool True if num is divisible by dig, false otherwise.
 */
bool isDivisible(int num, int dig){
    // This is a safeguard. Division by zero is undefined and would cause a crash.
    if (dig == 0) {
        return false;
    }
    // The modulo operator (%) returns the remainder of a division.
    // If the remainder is 0, the number is evenly divisible.
    return num % dig == 0;
}

/**
 * @brief Counts how many of a number's own digits divide the number evenly.
 *
 * @param num The integer to be evaluated.
 * @return int The count of its digits that can divide it.
 *
 * ## Overall Approach
 * The function works by iterating through each digit of the input number `num`. For each
 * digit, it performs a check to see if the original number `num` is evenly divisible by
 * that digit.
 *
 * 1.  **Preserve Original Number:** A copy of the original number (`numcopy`) is made.
 * This is crucial because we need the original `num` for the divisibility check in each
 * iteration, while we dismantle `numcopy` to extract its digits.
 * 2.  **Digit Extraction:** A `while` loop runs as long as `numcopy` is greater than 0.
 * In each iteration:
 * - `numcopy % 10` extracts the last digit.
 * - `numcopy /= 10` removes the last digit.
 * 3.  **Divisibility Check:** The extracted digit is passed to the `isDivisible` helper
 * function along with the *original* `num`. If it returns true, a counter is incremented.
 *
 * The loop continues until all digits have been processed, and the final count is returned.
 *
 * ## Time Complexity: O(log10(N)) or O(D)
 * The time complexity is proportional to the number of digits (D) in the input number `num`.
 * The `while` loop runs once for each digit. The number of digits in N is approximately log10(N).
 *
 * ## Space Complexity: O(1)
 * The function uses a fixed amount of extra space (a few integer variables) regardless of
 * the size of the input number.
 */
int countDigits(int num) {
    int count = 0;
    // Create a copy of 'num' so we can modify it to extract digits,
    // while preserving the original 'num' for the division check.
    int numcopy = num;

    // Loop until all digits have been extracted from numcopy.
    while(numcopy > 0){
        // Get the last digit of the current number.
        int dig = numcopy % 10;
        
        // Check if the original number is divisible by the extracted digit.
        if(isDivisible(num, dig)){
            count++;
        }
        
        // Remove the last digit from numcopy to process the next one.
        numcopy /= 10;
    }
    return count;
}

int main() {
    // --- Test Case 1 ---
    int num1 = 7;
    cout << "Number: " << num1 << endl;
    cout << "Count of digits that divide it: " << countDigits(num1) << endl; // 7 is divisible by 7. Expected: 1
    cout << "--------------------" << endl;

    // --- Test Case 2 ---
    int num2 = 121;
    cout << "Number: " << num2 << endl;
    cout << "Count of digits that divide it: " << countDigits(num2) << endl; // 121 is divisible by 1 (twice). Expected: 2
    cout << "--------------------" << endl;

    // --- Test Case 3 ---
    int num3 = 1248;
    cout << "Number: " << num3 << endl;
    cout << "Count of digits that divide it: " << countDigits(num3) << endl; // 1248 is divisible by 1, 2, 4, 8. Expected: 4
    cout << "--------------------" << endl;

    return 0;
}

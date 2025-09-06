// Required for input/output operations and the vector data structure.
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Defines an array `nums` where `nums[i] = start + 2 * i` and returns the XOR total of all its elements.
 *
 * @param n The number of elements in the array.
 * @param start The starting value for the array definition.
 * @return int The result of XORing all elements in the generated array.
 *
 * ## Overall Approach
 * The function first conceptually defines an array based on the given `start` and `n` values.
 * It then iterates through the elements of this conceptual array, accumulating the bitwise
 * XOR sum.
 *
 * 1.  **Initialization:** A `std::vector` named `nums` of size `n` is created. The first element is set to
 * `start`, and the initial XOR sum (`ans`) is also set to `start`.
 * 2.  **Iteration and Calculation:** A loop runs from `i = 1` to `n-1`. In each step:
 * - The next element `nums[i]` is calculated using the formula `start + 2 * i`.
 * - The current XOR sum `ans` is updated by XORing it with the new element (`ans ^= nums[i]`).
 * The `^` operator is the bitwise XOR operator in C++.
 * 3.  **Return Value:** After the loop completes, `ans` holds the XOR sum of all elements,
 * which is then returned.
 *
 * Note: The intermediate `nums` vector is not strictly necessary to calculate the final answer.
 * The result could be computed by just generating the numbers on the fly within the loop and
 * XORing them, which would optimize space. This implementation is a direct translation of the
 * provided logic.
 *
 * ## Time Complexity: O(N)
 * The function iterates from 1 to `n-1` in a single loop. Therefore, the time complexity is
 * linear with respect to the input `n`.
 *
 * ## Space Complexity: O(N)
 * The function uses an auxiliary vector `nums` of size `n` to store the numbers. This makes
 * the space complexity linear with respect to `n`. (This could be O(1) if the vector was not used).
 */
int xorOperation(int n, int start) {
    // A standard C++ vector of integers is created with size n.
    vector<int> nums(n);

    // The first element is simply the start value.
    nums[0] = start;
    
    // Initialize the answer with the first element's value.
    int ans = start;

    // Loop through the remaining n-1 elements.
    for (int i = 1; i < n; i++) {
        // Calculate the value of the current element based on the formula.
        nums[i] = start + 2 * i;
        
        // Update the answer by XORing it with the current element.
        ans ^= nums[i];
    }

    // Return the final XOR sum.
    return ans;
}

int main() {
    // --- Test Case 1 ---
    int n1 = 5, start1 = 0;
    // Array would be: [0, 2, 4, 6, 8]
    // 0 ^ 2 ^ 4 ^ 6 ^ 8 = 8
    cout << "n = " << n1 << ", start = " << start1 << endl;
    cout << "XOR sum: " << xorOperation(n1, start1) << endl; // Expected: 8
    cout << "--------------------" << endl;

    // --- Test Case 2 ---
    int n2 = 4, start2 = 3;
    // Array would be: [3, 5, 7, 9]
    // 3 ^ 5 ^ 7 ^ 9 = 8
    cout << "n = " << n2 << ", start = " << start2 << endl;
    cout << "XOR sum: " << xorOperation(n2, start2) << endl; // Expected: 8
    cout << "--------------------" << endl;

    // --- Test Case 3 ---
    int n3 = 1, start3 = 7;
    // Array would be: [7]
    // 7 = 7
    cout << "n = " << n3 << ", start = " << start3 << endl;
    cout << "XOR sum: " << xorOperation(n3, start3) << endl; // Expected: 7
    cout << "--------------------" << endl;

    return 0;
}


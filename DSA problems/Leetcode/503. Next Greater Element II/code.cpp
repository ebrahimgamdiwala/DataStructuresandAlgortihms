// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the stack data structure.
#include <stack>
// Required for using the vector (dynamic array) data structure.
#include <vector>

using namespace std;

/**
 * @brief Finds the next greater element for each element in a circular array.
 *
 * For each element, this function finds the first element that is greater than it,
 * searching in a circular fashion. If no such element exists, -1 is used.
 *
 * @param nums A vector of integers representing the circular array.
 * @return vector<int> A vector containing the next greater element for each element in nums.
 *
 * ## Overall Approach
 * This problem is solved efficiently using a monotonic stack. The key challenge is handling
 * the "circular" nature of the array. The code cleverly simulates this by pretending the
 * array is twice its size (e.g., `[1,2,1]` becomes `[1,2,1,1,2,1]`).
 *
 * This is achieved by looping from `2*n - 1` down to `0`. The modulo operator (`i % n`) is
 * used to get the correct index within the original array bounds. By iterating through the
 * "doubled" array from right to left, we ensure that for each element, we check all
 * subsequent elements, including those that wrap around from the beginning of the array.
 *
 * A monotonic (decreasing) stack is used to keep track of the indices of elements that
 * could be potential "next greater elements" for numbers we haven't processed yet.
 *
 * ## Time Complexity: O(N)
 * The time complexity is linear with respect to the number of elements (N) in the input `nums`.
 * Although the main loop runs `2*n` times, each element's index is pushed onto the stack
 * and popped from the stack at most once over the entire execution. Thus, the total
 * number of operations is proportional to N.
 *
 * ## Space Complexity: O(N)
 * The space complexity is determined by the stack. In the worst-case scenario (e.g., a
 * strictly decreasing array like `[5,4,3,2,1]`), the stack will grow to hold all N indices.
 * Therefore, the space required is proportional to the size of the input array.
 */
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    // Initialize the answer vector with -1. This is the default value for elements
    // that do not have a next greater element.
    vector<int> ans(n, -1);
    // The monotonic stack will store the *indices* of the numbers, not the numbers themselves.
    stack<int> s;

    // STEP 1: Iterate as if the array were twice its size to handle circularity.
    // We loop from `2*n - 1` down to `0`. The modulo operator `i % n` will map these
    // values to valid indices in the original `nums` array, effectively letting us
    // pass over the array twice.
    for (int i = 2 * n - 1; i >= 0; i--) {
        // The current index in the original array.
        int currentIndex = i % n;
        int currentNum = nums[currentIndex];

        // STEP 2: Maintain the monotonic (decreasing) stack property.
        // While the stack is not empty and the number at the index on top of the stack
        // is less than or equal to our current number...
        while (!s.empty() && nums[s.top()] <= currentNum) {
            // ...pop it. These smaller elements cannot be the "next greater element"
            // for any numbers we will process to the left.
            s.pop();
        }

        // STEP 3: Determine the next greater element.
        // After the while loop, the stack is either empty or the index at its top
        // points to the first number to the right that is greater than `currentNum`.
        if (!s.empty()) {
            // If the stack is not empty, the top element is our answer.
            ans[currentIndex] = nums[s.top()];
        }
        // Note: If the stack IS empty, the answer for `ans[currentIndex]` remains -1,
        // which is the correct default value.

        // STEP 4: Push the current index onto the stack.
        // This index will be a candidate for being the next greater element for the
        // numbers we process next (those to the left).
        s.push(currentIndex);
    }
    return ans;
}

/**
 * @brief A helper function to print the elements of a vector.
 * @param vec The vector to be printed.
 */
void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i == vec.size() - 1 ? " " : ", ");
    }
    cout << "]" << endl;
}

int main() {
    // Create a hardcoded input vector for testing.
    vector<int> nums = {1, 2, 3, 4, 3};

    cout << "Input Array: ";
    printVector(nums);

    // Call the function to get the result.
    vector<int> result = nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    printVector(result);
    // Expected output: [ 2, 3, 4, -1, 4 ]

    return 0;
}

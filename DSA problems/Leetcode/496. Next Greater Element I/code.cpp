// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the stack data structure.
#include <stack>
// Required for using the vector (dynamic array) data structure.
#include <vector>
// Required for using the unordered_map (hash map) data structure.
#include <unordered_map>

using namespace std;

/**
 * @brief Finds the next greater element for each element of nums1 in nums2.
 *
 * The next greater element of a number `x` in `nums1` is the first greater
 * number to its right in `nums2`. If it does not exist, the answer is -1.
 *
 * @param nums1 A subset of nums2 for which we need to find the next greater elements.
 * @param nums2 The array to search for the next greater elements.
 * @return vector<int> A vector containing the next greater element for each element in nums1.
 *
 * ## Overall Approach
 * The function uses a monotonic stack and a hash map to solve the problem efficiently.
 * The core idea is to pre-process `nums2` to find the next greater element for *every*
 * number in it. This information is stored in a hash map for quick lookups later.
 *
 * We iterate through `nums2` from right to left. A monotonic stack (specifically, a
 * decreasing stack) is used to keep track of elements we've seen. For each number,
 * we pop smaller elements from the stack until we find one that is greater. This
 * greater element is the "next greater element".
 *
 * ## Time Complexity: O(N + M)
 * Where N is the number of elements in `nums2` and M is the number of elements in `nums1`.
 * We iterate through `nums2` once to populate the map. Although there's a nested `while`
 * loop, each element of `nums2` is pushed and popped from the stack at most once.
 * This makes the first part O(N). Then, we iterate through `nums1` once to build the
 * result vector using O(1) map lookups, which takes O(M) time.
 * The total complexity is O(N + M).
 *
 * ## Space Complexity: O(N)
 * In the worst-case scenario (a strictly decreasing `nums2` array), the stack and the
 * map will both store an entry for every element in `nums2`. Therefore, the space
 * required is proportional to the size of `nums2`.
 */
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    // `ans` will store the final result.
    vector<int> ans;
    // `s` is our monotonic stack.
    stack<int> s;
    // `m` is a hash map to store the mapping from an element to its next greater element.
    unordered_map<int, int> m;

    // STEP 1: Pre-process nums2 to find the next greater element for each number.
    // We iterate from right to left.
    for (int i = nums2.size() - 1; i >= 0; i--) {
        // Get the current number from nums2.
        int current_num = nums2[i];

        // Maintain the monotonic (decreasing) stack property.
        // While the stack is not empty and the element at the top is less than or
        // equal to our current number, pop it. Those elements can't be the next
        // greater element for anyone to their left.
        while (s.size() > 0 && s.top() <= current_num) {
            s.pop();
        }

        // After the while loop, the stack top is either a greater element or the stack is empty.
        if (s.empty()) {
            // If the stack is empty, there is no greater element to the right.
            m[current_num] = -1;
        } else {
            // Otherwise, the top of the stack is the next greater element.
            m[current_num] = s.top();
        }

        // Push the current number onto the stack for processing future elements (to its left).
        s.push(current_num);
    }

    // STEP 2: Build the result vector using the pre-computed map.
    // Iterate through each element in nums1.
    for (int ele : nums1) {
        // Find the next greater element from the map and add it to our answer.
        ans.push_back(m[ele]);
    }

    // Return the final result.
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


// The main function serves as the entry point for the program.
int main() {

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    cout << "nums1: ";
    printVector(nums1);
    cout << "nums2: ";
    printVector(nums2);

    // Call the function to get the result.
    vector<int> result = nextGreaterElement(nums1, nums2);

    cout << "Result: ";
    printVector(result);
    // Expected output: [ -1, 3, -1 ]
    // Explanation:
    // For 4 in nums1, there is no greater number to its right in nums2.
    // For 1 in nums1, the next greater number to its right in nums2 is 3.
    // For 2 in nums1, there is no greater number to its right in nums2.

    return 0;
}

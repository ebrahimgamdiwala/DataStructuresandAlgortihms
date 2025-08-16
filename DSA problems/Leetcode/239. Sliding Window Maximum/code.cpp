// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the vector (dynamic array) data structure.
#include <vector>
// Required for using the deque (double-ended queue) data structure.
#include <deque>

using namespace std;

/**
 * @brief Finds the maximum value in each sliding window of size k.
 *
 * @param nums The input vector of integers.
 * @param k The size of the sliding window.
 * @return vector<int> A vector containing the maximum of each window.
 *
 * ## Overall Approach
 * This function uses a `deque` (double-ended queue) to find the maximum in each
 * sliding window in linear time. The deque is used to store the *indices* of elements
 * in the current window. It is maintained as a "monotonic decreasing" queue, meaning
 * the elements' values at the indices in the deque are always in decreasing order
 * from front to back.
 *
 * This property ensures that the index of the largest element in the current window is
 * always at the front of the deque (`dq.front()`). As the window slides, we add new
 * indices to the back and remove old ones from the front, efficiently updating the
 * potential maximums.
 *
 * ## Time Complexity: O(N)
 * The time complexity is linear with respect to the number of elements (N) in the input `nums`.
 * Although there are nested `while` loops, each element's index is pushed onto and popped
 * from the deque at most once over the entire execution. Thus, the total number of
 * operations is proportional to N.
 *
 * ## Space Complexity: O(k)
 * The space complexity is determined by the size of the deque. In the worst case, the
 * deque will store `k` indices (e.g., for a strictly decreasing input array). Therefore,
 * the space required is proportional to the window size `k`.
 */
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // `dq` will store indices of elements, maintained in decreasing order of their values.
    deque<int> dq;
    // `ans` will store the maximum of each window.
    vector<int> ans;

    // STEP 1: Process the first window of size k.
    for (int i = 0; i < k; i++) {
        // Maintain the monotonic decreasing property.
        // Before pushing a new index, remove all indices from the back of the deque
        // that correspond to values smaller than or equal to the current value.
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        // Add the current index to the back of the deque.
        dq.push_back(i);
    }

    // STEP 2: Process the rest of the elements.
    for (int i = k; i < nums.size(); i++) {
        // The front of the deque holds the index of the maximum element for the *previous* window.
        ans.push_back(nums[dq.front()]);

        // Remove indices from the front that are no longer in the current window.
        // An index `j` is out of the window `[i-k+1, i]` if `j <= i-k`.
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Maintain the monotonic decreasing property for the new element.
        // Remove indices of smaller elements from the back.
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        // Add the current index to the back.
        dq.push_back(i);
    }

    // After the loop, the maximum of the very last window is still in the deque.
    // Add it to the answer.
    if (!dq.empty()) {
        ans.push_back(nums[dq.front()]);
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
    // Create a hardcoded input vector and window size for testing.
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Input Array: ";
    printVector(nums);
    cout << "Window Size: " << k << endl;

    // Call the function to get the result.
    vector<int> result = maxSlidingWindow(nums, k);

    cout << "Sliding Window Maximums: ";
    printVector(result);
    // Expected output: [ 3, 3, 5, 5, 6, 7 ]

    return 0;
}

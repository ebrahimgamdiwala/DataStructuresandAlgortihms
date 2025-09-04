// Required for input/output, the vector data structure, and sorting/swapping algorithms.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Simulates a number game where players pick and arrange numbers.
 *
 * @param nums A vector of integers.
 * @return vector<int> The resulting vector after the game simulation.
 *
 * ## Overall Approach
 * The problem describes a game with two players, Alice and Bob, and a set of rules for
 * arranging numbers. The logic can be implemented in two main steps:
 *
 * 1.  **Sorting:** The rules state that Alice and Bob always pick the minimum available
 * numbers. Sorting the initial array (`nums`) ensures that at each step of the process,
 * we are dealing with the two smallest available numbers.
 * 2.  **Swapping:** The game requires Bob to append his number first, then Alice.
 * After sorting, we have pairs of numbers like `(nums[0], nums[1])`, `(nums[2], nums[3])`, etc.,
 * where `nums[i]` is Alice's pick and `nums[i+1]` is Bob's pick. By swapping these pairs,
 * we effectively place Bob's number before Alice's in the final arrangement, satisfying
 * the game's rules. This is done by iterating through the sorted array with a step of 2.
 *
 * ## Time Complexity: O(N log N)
 * The complexity is dominated by the sorting step, which typically takes O(N log N) time.
 * The subsequent loop to swap elements runs in O(N) time, which is less significant.
 *
 * ## Space Complexity: O(log N) or O(1)
 * The space complexity depends on the implementation of the `sort` function. `std::sort`
 * is typically an introspective sort (introsort) which has a space complexity of O(log N)
 * due to the recursion stack. If we consider the modification to be in-place, the extra
 * space used is minimal.
 */
vector<int> numberGame(vector<int>& nums) {
    // Step 1: Sort the array to easily access the two minimum elements at each turn.
    sort(nums.begin(), nums.end());

    // Step 2: Iterate through the sorted array in steps of 2 to process pairs.
    for (int i = 0; i < nums.size(); i += 2) {
        // For each pair (Alice's pick, Bob's pick), swap them to simulate
        // Bob appending his number first, then Alice.
        swap(nums[i], nums[i + 1]);
    }

    // Return the final arranged vector.
    return nums;
}


/**
 * @brief Helper function to print the elements of a vector.
 * @param arr The vector to be printed.
 */
void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // --- Test Case 1 ---
    vector<int> nums1 = {5, 4, 2, 3};
    cout << "Initial array: ";
    printVector(nums1);
    // After sorting: {2, 3, 4, 5}
    // After swapping pairs: {3, 2, 5, 4}
    vector<int> result1 = numberGame(nums1);
    cout << "Resulting array: ";
    printVector(result1); // Expected output: 3 2 5 4
    cout <<endl;

    // --- Test Case 2 ---
    vector<int> nums2 = {2, 5};
    cout << "Initial array: ";
    printVector(nums2);
    // After sorting: {2, 5}
    // After swapping pairs: {5, 2}
    vector<int> result2 = numberGame(nums2);
    cout << "Resulting array: ";
    printVector(result2); // Expected output: 5 2
    cout << endl;

    return 0;
}

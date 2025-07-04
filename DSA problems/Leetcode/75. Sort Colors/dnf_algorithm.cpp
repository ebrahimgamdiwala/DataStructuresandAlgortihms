#include <iostream>
#include <vector>
using namespace std;

/*
 * Dutch National Flag Sorting Algorithm Explanation:
 *
 * This algorithm is designed to sort an array with three distinct elements (e.g., 0, 1, 2).
 * It partitions the array into three regions:
 * 
 * 1. The "low" region: all elements equal to 0 (on the left side).
 * 2. The "middle" region: all elements equal to 1 (in the middle).
 * 3. The "high" region: all elements equal to 2 (on the right side).
 *
 * The algorithm uses three pointers:
 * - low: Points to the first position where a `0` should go.
 * - mid: Points to the current element being processed.
 * - high: Points to the first position where a `2` should go.
 *
 * The algorithm operates as follows:
 * - If `nums[mid] == 0`, swap `nums[mid]` with `nums[low]`, then move both `low` and `mid` forward.
 * - If `nums[mid] == 1`, just move the `mid` pointer forward as `1` is already in the correct middle region.
 * - If `nums[mid] == 2`, swap `nums[mid]` with `nums[high]`, and move the `high` pointer backward.
 * The process continues until the `mid` pointer exceeds the `high` pointer, ensuring that the array is sorted in one pass.
 * 
 * Time Complexity: O(n) - each element is processed at most once.
 * Space Complexity: O(1) - the sorting is done in-place, using only a constant amount of extra space.
 */

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    // While mid pointer does not surpass high pointer
    while (mid <= high) {
        // If the current element is 0, it should be placed in the "low" region (leftmost side)
        if (nums[mid] == 0) {
            // Swap nums[mid] and nums[low] to place 0 in the correct position
            swap(nums[mid], nums[low]);
            // Move both pointers forward as we have handled nums[mid]
            low++;
            mid++;
        }
        // If the current element is 1, it is already in the correct region (middle)
        else if (nums[mid] == 1) {
            // No swap needed, just move the mid pointer
            mid++;
        }
        // If the current element is 2, it should be placed in the "high" region (rightmost side)
        else {
            // Swap nums[mid] and nums[high] to place 2 in the correct position
            swap(nums[mid], nums[high]);
            // Move the high pointer backward, as the swapped element is now handled
            high--;
        }
    }
}

int main() {
    // Hardcoded input array
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    // Print original array
    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Call sortColors to sort the array
    sortColors(nums);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

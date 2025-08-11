// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the vector (dynamic array) data structure.
#include <vector>
// Required for using the min and max functions.
#include <algorithm>

using namespace std;

/**
 * @brief Calculates the total amount of rainwater that can be trapped between bars (space-optimized).
 *
 * @param height A vector of non-negative integers representing the elevation map.
 * @return int The total units of water trapped.
 *
 * ## Overall Approach
 * This function uses a highly efficient two-pointer technique to solve the problem in a
 * single pass, without needing extra arrays for storage.
 *
 * It maintains two pointers, `l` and `r`, starting at the left and right ends of the array,
 * and two variables, `lmax` and `rmax`, to track the maximum height seen so far from the
 * left and right, respectively.
 *
 * The core insight is this: the water trapped at any position is limited by the shorter of
 * the max height on the left and the max height on the right. If `lmax` is less than `rmax`,
 * we can be certain that the water level at the `l` pointer is determined by `lmax`, because
 * we know a taller wall (`rmax`) exists somewhere to the right. We can then safely calculate
 * the trapped water at `l` and move `l` inward. The same logic applies symmetrically when
 * `rmax` is less than or equal to `lmax`. The pointers move towards each other until they meet.
 *
 * ## Time Complexity: O(N)
 * The algorithm uses two pointers, `l` and `r`, that traverse the array once. Each element
 * is visited exactly one time, resulting in a linear time complexity.
 *
 * ## Space Complexity: O(1)
 * This is the main advantage of the two-pointer approach. It only uses a few variables to
 * store the pointers and maximums, regardless of the input size. It does not use any
 * auxiliary arrays, giving it constant space complexity.
 */
int trap(vector<int> &height)
{
    int n = height.size();
    if (n <= 2)
    {
        return 0;
    }
    int ans = 0;
    // Initialize left and right pointers.
    int l = 0, r = n - 1;
    // Initialize max heights seen from left and right.
    int lmax = 0, rmax = 0;

    // Process the array until the pointers meet.
    while (l < r)
    {
        // Update the max height seen so far from the left.
        lmax = max(height[l], lmax);
        // Update the max height seen so far from the right.
        rmax = max(height[r], rmax);

        // The key logic: process the side with the smaller max height.
        if (lmax < rmax)
        {
            // The water level at pointer `l` is determined by `lmax`.
            // We know this because `rmax` (a taller wall) exists to the right,
            // so `lmax` is the bottleneck.
            ans += lmax - height[l];
            // Move the left pointer inward.
            l++;
        }
        else
        {
            // The water level at pointer `r` is determined by `rmax`.
            // `lmax` is the taller wall, so `rmax` is the bottleneck for the right side.
            ans += rmax - height[r];
            // Move the right pointer inward.
            r--;
        }
    }

    return ans;
}

int main()
{

    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Calculating trapped rainwater for elevation map: [0,1,0,2,1,0,1,3,2,1,2,1]" << endl;

    // Call the function to get the result.
    int totalWater = trap(height);

    cout << "Total trapped water: " << totalWater << endl;
    // Expected output: 6

    return 0;
}

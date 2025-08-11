// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the vector (dynamic array) data structure.
#include <vector>
// Required for using the min and max functions.
#include <algorithm>

using namespace std;

/**
 * @brief Calculates the total amount of rainwater that can be trapped between bars of a histogram.
 *
 * @param height A vector of non-negative integers representing the elevation map.
 * @return int The total units of water trapped.
 *
 * ## Overall Approach
 * The core idea is that the amount of water trapped above any single bar `height[i]` is
 * determined by the height of the walls on its left and right. Specifically, the water
 * can fill up to the height of the shorter of the two walls. The two "walls" are:
 * 1. The tallest bar to the left of `i` (including `i` itself).
 * 2. The tallest bar to the right of `i` (including `i` itself).
 *
 * The amount of water above bar `i` is `min(tallest_left_wall, tallest_right_wall) - height[i]`.
 *
 * This algorithm works by pre-computing the tallest wall to the left and right for every
 * single position in the array. It stores these values in `leftMax` and `rightMax` arrays.
 * Once these values are known, a final pass through the array calculates the trapped water
 * at each position and sums it up.
 *
 * ## Time Complexity: O(N)
 * The algorithm makes three separate passes through the array of size N: one to compute
 * `leftMax`, one for `rightMax`, and one to calculate the final answer. Each pass takes
 * O(N) time. Therefore, the total time complexity is O(N) + O(N) + O(N) = O(N).
 *
 * ## Space Complexity: O(N)
 * We use two additional arrays, `leftMax` and `rightMax`, each of size N, to store the
 * pre-computed maximum heights. This results in a space complexity proportional to N.
 */
int trap(vector<int> &height)
{
    int n = height.size();
    if (n <= 2)
    {
        // Cannot trap water with 2 or fewer bars.
        return 0;
    }

    // `leftMax[i]` will store the maximum height from index 0 to i.
    vector<int> leftMax(n, 0);
    // `rightMax[i]` will store the maximum height from index i to n-1.
    vector<int> rightMax(n, 0);

    // STEP 1: Pre-compute the maximum height to the left of each position.
    // Initialize the first element.
    leftMax[0] = height[0];
    // Iterate from the second element to the end.
    for (int i = 1; i < n; i++)
    {
        // The max height at `i` is the greater of the previous max and the current height.
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // STEP 2: Pre-compute the maximum height to the right of each position.
    // Initialize the last element.
    rightMax[n - 1] = height[n - 1];
    // Iterate from the second-to-last element to the beginning.
    for (int i = n - 2; i >= 0; i--)
    {
        // The max height at `i` is the greater of the next max and the current height.
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // STEP 3: Calculate the trapped water.
    int ans = 0;
    // Iterate through each bar of the histogram.
    for (int i = 0; i < n; i++)
    {
        // The water level above the current bar is limited by the shorter of the
        // left and right maximum walls.
        int waterLevel = min(leftMax[i], rightMax[i]);
        // The amount of trapped water at this position is the water level minus the
        // height of the current bar.
        ans += waterLevel - height[i];
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

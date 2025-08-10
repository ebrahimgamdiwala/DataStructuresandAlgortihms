// Required for input/output operations, like printing to the console.
#include <iostream>
// Required for using the stack data structure.
#include <stack>
// Required for using the vector (dynamic array) data structure.
#include <vector>
// Required for using the max function.
#include <algorithm>

using namespace std;

/**
 * @brief Calculates the area of the largest rectangle in a histogram.
 *
 * @param heights A vector of integers representing the heights of the bars in the histogram.
 * @return int The area of the largest possible rectangle.
 *
 * ## Overall Approach
 * The core idea is that for any given bar `heights[i]`, the largest rectangle that can be
 * formed with this bar as the *shortest* bar will extend to the left and right until it hits
 * a bar that is shorter than `heights[i]`.
 *
 * The algorithm efficiently finds these boundaries for every bar:
 * 1.  **Nearest Smaller to the Right (NSR):** For each bar `i`, find the index of the first
 * bar to its right that is shorter. This is stored in the `right` vector.
 * 2.  **Nearest Smaller to the Left (NSL):** For each bar `i`, find the index of the first
 * bar to its left that is shorter. This is stored in the `left` vector.
 *
 * A monotonic stack is used twice to compute these boundaries in linear time. Once the `left`
 * and `right` boundaries are known for every bar `i`, the width of the rectangle is
 * `right[i] - left[i] - 1`. The area is this width times `heights[i]`. We calculate this
 * area for every bar and keep track of the maximum one found.
 *
 * ## Time Complexity: O(N)
 * The algorithm consists of three main loops, each iterating through the N elements of the
 * `heights` array once. The two loops that use a monotonic stack are also O(N) because each
 * element is pushed and popped from the stack at most once. Therefore, the total time
.
 *
 * ## Space Complexity: O(N)
 * We use two additional vectors, `left` and `right`, each of size N, and a stack that can
 * grow up to size N in the worst case. This results in a space complexity proportional to N.
 */
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;

    vector<int> left(n);  // Stores index of nearest smaller element to the left
    vector<int> right(n); // Stores index of nearest smaller element to the right
    stack<int> s;

    // STEP 1: Calculate Nearest Smaller to the Right (NSR) for each bar.
    // We iterate from right to left.
    for (int i = n - 1; i >= 0; i--) {
        // While stack is not empty and the bar at the stack's top is taller
        // than or equal to the current bar, pop it.
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        // If the stack is empty, it means no smaller bar exists to the right.
        // We use `n` as a sentinel boundary index.
        // Otherwise, the index at the top of the stack is our answer.
        right[i] = s.empty() ? n : s.top();
        // Push the current bar's index onto the stack.
        s.push(i);
    }

    // Clear the stack to reuse it for the next calculation.
    while (!s.empty()) {
        s.pop();
    }

    // STEP 2: Calculate Nearest Smaller to the Left (NSL) for each bar.
    // We iterate from left to right.
    for (int i = 0; i < n; i++) {
        // While stack is not empty and the bar at the stack's top is taller
        // than or equal to the current bar, pop it.
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        // If the stack is empty, it means no smaller bar exists to the left.
        // We use `-1` as a sentinel boundary index.
        // Otherwise, the index at the top of the stack is our answer.
        left[i] = s.empty() ? -1 : s.top();
        // Push the current bar's index onto the stack.
        s.push(i);
    }

    // STEP 3: Calculate the area for each bar and find the maximum.
    int largestArea = 0;
    for (int i = 0; i < n; i++) {
        // The width of the rectangle with `heights[i]` as the smallest bar
        // is the distance between its right and left boundaries.
        int width = right[i] - left[i] - 1;
        int currArea = width * heights[i];
        largestArea = max(largestArea, currArea);
    }

    return largestArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Calculating the largest rectangle area for histogram: [2, 1, 5, 6, 2, 3]" << endl;

    // Call the function to get the result.
    int area = largestRectangleArea(heights);

    cout << "Largest Area: " << area << endl;
    // Expected output: 10
    // Explanation: The largest rectangle is formed by the bars of height 5 and 6.
    // The height of this rectangle is limited by the shorter bar (5).
    // The width is 2. So, the area is 5 * 2 = 10.

    return 0;
}

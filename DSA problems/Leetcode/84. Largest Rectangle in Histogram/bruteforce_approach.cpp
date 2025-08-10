#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestRectangleAreaBruteForce(vector<int>& heights) {
    int n = heights.size();
    if (n == 0) return 0;
    int maxArea = 0;

    for (int i = 0; i < n; i++) {
        int minHeight = heights[i];
        for (int j = i; j < n; j++) {
            minHeight = min(minHeight, heights[j]);
            int width = j - i + 1;
            maxArea = max(maxArea, minHeight * width);
        }
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Calculating the largest rectangle area for histogram: [2, 1, 5, 6, 2, 3]" << endl;
    int area = largestRectangleAreaBruteForce(heights);
    cout << "Largest Area: " << area << endl;
    return 0;
}
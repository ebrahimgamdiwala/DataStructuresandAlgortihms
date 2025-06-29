#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int maxArea(vector<int>& height) {
    int maxWater = 0;
    for(int i = 0; i < height.size(); i++) {
        for(int j = i + 1; j < height.size(); j++) {
            int width = j - i;
            int ht = min(height[i], height[j]);
            int area = width * ht;
            maxWater = max(maxWater, area);
        }
    }
    return maxWater;
}

int main() {

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int result = maxArea(height);
    cout << "Maximum water that can be contained: " << result << endl;

    return 0;
}

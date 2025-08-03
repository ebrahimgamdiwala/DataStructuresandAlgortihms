#include <iostream>
#include <vector>

using namespace std;

// Function to compute the running sum of a vector
// Time Complexity: O(n), where n is the size of the input vector
vector<int> runningSum(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    // Call the function
    vector<int> result = runningSum(nums);

    // Output the result
    cout << "Running sum: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

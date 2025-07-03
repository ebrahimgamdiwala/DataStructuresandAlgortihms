// Book allocation problem

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to check if the array can be split into k or fewer subarrays with max sum <= maxAllowedSum
    bool isValid(vector<int>& nums, int n, int k, int maxAllowedSum) {
        int noOfSubarrays = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxAllowedSum) {
                return false;
            }
            if (sum + nums[i] <= maxAllowedSum) {
                sum += nums[i];
            } else {
                noOfSubarrays++;
                sum = nums[i];
            }
        }
        return noOfSubarrays <= k;
    }

    // Main function to find the minimal largest subarray sum when splitting into k parts
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n) {
            return -1;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int start = 0, end = sum;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValid(nums, n, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {

    vector<int> nums = {7, 2, 5, 10, 8};  // Example input
    int k = 2;  

    Solution solution;
    int result = solution.splitArray(nums, k);

    cout << "Minimal largest subarray sum: " << result << endl;

    return 0;
}

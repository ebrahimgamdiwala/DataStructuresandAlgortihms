#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive function to generate unique subsets
void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
    if(i == nums.size()) {
        allSubsets.push_back(ans); // Save the current subset
        return;
    }

    // Include nums[i]
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);
    ans.pop_back();

    // Skip duplicates
    int idx = i + 1;
    while(idx < nums.size() && nums[idx] == nums[idx - 1]) {
        idx++;
    }

    // Exclude nums[i]
    getAllSubsets(nums, ans, idx, allSubsets);
}

// Wrapper function
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Sort to handle duplicates
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main() {
    // Input (with duplicates)
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = subsetsWithDup(nums);

    // Print results
    cout << "All unique subsets:\n";
    for(const auto& subset : result) {
        cout << "[";
        for(size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if(i < subset.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}

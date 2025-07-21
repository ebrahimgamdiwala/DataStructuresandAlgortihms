#include <iostream>
#include <vector>

using namespace std;

// Function to generate all subsets
void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
    if(i == nums.size()) {
        allSubsets.push_back(ans); // Store the current subset
        return;
    }

    // Include nums[i]
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i + 1, allSubsets);

    // Exclude nums[i]
    ans.pop_back();
    getAllSubsets(nums, ans, i + 1, allSubsets);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(nums, ans, 0, allSubsets);
    return allSubsets;
}

int main() {
   
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    // Print the subsets
    cout << "All subsets:\n";
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

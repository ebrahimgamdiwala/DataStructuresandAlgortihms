#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    // TC : O(n^2 log(uniqueTriplets))
    // SC : O(uniqueTriplets + n)

    int n = nums.size();
    set<vector<int>> uniqueTriplets;
    
    for(int i = 0; i < n; i++){
        int target = -nums[i];
        set<int> s;
        for(int j = i + 1; j < n; j++){
            int third = target - nums[j];
            if(s.find(third) != s.end()){
                vector<int> triplet = {nums[i], nums[j], third};
                sort(triplet.begin(), triplet.end());
                uniqueTriplets.insert(triplet);
            }
            s.insert(nums[j]);
        }
    }
    
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);
    
    for(auto& triplet : result) {
        cout << "[";
        for(int i = 0; i < triplet.size(); i++) {
            cout << triplet[i];
            if(i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
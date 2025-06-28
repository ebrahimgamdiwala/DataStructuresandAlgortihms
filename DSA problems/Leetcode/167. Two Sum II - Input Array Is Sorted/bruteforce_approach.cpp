#include <iostream>
#include <vector>

using namespace std;

vector <int> pairSum(vector<int> nums, int target){
    vector <int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(nums[i]+nums[j]==target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }   
        }
    }
    return ans;
}

int main(){

    vector<int> vec = {2,7,11,15};
    int target = 18;

    vector<int> ans = pairSum(vec, target);

    for(int i : ans){
        cout << i << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

vector <int> pairSum(vector<int> nums, int target){
    vector <int> ans;
    
    int i = 0;
    int j = nums.size();
    while (i<j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum>target)
        {
            j--;
        }
        else if(pairSum<target){
            i++;
        }
        else{
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
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
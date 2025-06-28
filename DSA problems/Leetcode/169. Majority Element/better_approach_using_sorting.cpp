#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int> nums){
    int n = nums.size();

    //Sort
    sort(nums.begin(), nums.end());

    int freq = 1, ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if(nums[i-1] == nums[i]){
            freq++;
        }
        else{
            freq = 1;
            ans = nums[i];
        }

        if (freq>n/2)
        {
            return ans;
        }
        
    }
    return ans;
}

int main(){

    vector<int> vec = {2,2,1,1,1,2,2};

    int ans = majorityElement(vec);

    cout << "The majority element is = " << ans << endl;

    return 0;
}
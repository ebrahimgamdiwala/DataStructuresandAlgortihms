#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> nums){
    int n = nums.size();

    for(int val : nums){
        int freq = 0;
        for(int ele: nums){
            if(val == ele){
                freq++;
            }
        }
        if(freq>n/2){
            return val;
        }
    }
    return -1;
}

int main(){

    vector<int> vec = {2,2,1,1,1,2,2};

    int ans = majorityElement(vec);

    cout << "The majority element is = " << ans << endl;

    return 0;
}
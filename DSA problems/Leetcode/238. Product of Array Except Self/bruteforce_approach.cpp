#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i != j)
                ans[i] *= nums[j];
        }
    }
    return ans;
}

int main() {

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = productExceptSelf(nums);

    cout << "Product except self: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

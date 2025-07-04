#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Time Complexity : O(n log n). This is using the inbuilt sort function in C++

void sortColors(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sortColors(nums);

    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1;
    int index = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) {
            nums1[index] = nums1[i];
            i--;
        } else {
            nums1[index] = nums2[j];
            j--;
        }
        index--;
    }
    while (j >= 0) {
        nums1[index] = nums2[j];
        index--;
        j--;
    }
}

int main() {

    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // Length = m + n
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

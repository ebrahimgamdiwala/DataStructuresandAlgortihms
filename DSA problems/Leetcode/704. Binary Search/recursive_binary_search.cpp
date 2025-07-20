#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion stack
int binarySearch(vector<int>& arr, int target, int st, int end) {
    if (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] <= target)
            return binarySearch(arr, target, mid + 1, end);
        else
            return binarySearch(arr, target, st, mid - 1);
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int result = binarySearch(arr, target, 0, arr.size() - 1);
    cout << "Index: " << result << endl;
    return 0;
}

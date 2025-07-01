#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int start = 1, end = arr.size() - 2;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return mid;
        } else if (arr[mid - 1] < arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Hardcoded input - must be a mountain array (strictly increasing then strictly decreasing)
    vector<int> arr = {1, 3, 5, 7, 6, 4, 2};

    int peakIndex = peakIndexInMountainArray(arr);

    if (peakIndex != -1) {
        cout << "Peak index: " << peakIndex << endl;
        cout << "Peak value: " << arr[peakIndex] << endl;
    } else {
        cout << "No peak found." << endl;
    }

    return 0;
}

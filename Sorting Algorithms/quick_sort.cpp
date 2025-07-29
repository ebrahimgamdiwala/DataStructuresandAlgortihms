#include <iostream>
#include <vector>

using namespace std;

////////////////////////////////////////////////////////////
// Partition Method 1: Lomuto Partition Scheme (pivot = end)
////////////////////////////////////////////////////////////
/*
int partition(vector<int> &arr, int st, int end){
    int pivot = arr[end];         // Pivot is the last element
    int idx = st - 1;

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);     // Place pivot at correct position

    return idx;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}
*/

////////////////////////////////////////////////////////////
// Partition Method 2: Hoare Partition Scheme (pivot = start)
////////////////////////////////////////////////////////////
int partition(vector<int> &arr, int st, int end) {
    int pivot = arr[st];  // Pivot is the first element
    int i = st + 1;
    int j = end;

    while (i <= j) {
        while (i <= end && arr[i] <= pivot) i++; // Move from left to right until finding an element > pivot
        while (j >= st + 1 && arr[j] > pivot) j--; // Move from right to left until finding an element <= pivot

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[st], arr[j]); // Place pivot in the correct position

    return j;

    // Time Complexity: O(n)
    // Space Complexity: O(1)
}

void quickSort(vector<int> &arr, int st, int end){
    if (st < end) {
        int pivotIndex = partition(arr, st, end);
        quickSort(arr, st, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }

    // Average Time Complexity: O(n log n)
    // Worst Time Complexity: O(n^2)
    // Space Complexity: O(log n) average, O(n) worst (recursion stack)
}

int main(){
    vector<int> arr = {5, 2, 6, 4, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Quick Sort: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

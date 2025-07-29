#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int st, int mid, int end){
    // Temporary vector to store merged results
    vector<int> temp;

    int i = st, j = mid+1;
    
    // Merge the two sorted halves into temp
    while (i<=mid && j<=end)
    {
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy any remaining elements from left half
    while (i<=mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy any remaining elements from right half
    while (j<=end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy the sorted temp array back into the original array
    for(int idx = 0; idx<temp.size(); idx++){
        arr[idx+st] = temp[idx];
    }

    // Space Complexity: O(n) auxiliary space for the temp vector
    // Time Complexity for this merge function: O(n), where n = end - st + 1
}

void mergeSort(vector<int> &arr, int st, int end){
    // Base case: if the segment has only one element, it's already sorted
    int mid = st + (end - st)/2;
    if (st<end)
    {
        // Recursively sort left half
        mergeSort(arr, st, mid);

        // Recursively sort right half
        mergeSort(arr, mid+1, end);

        // Merge the sorted halves
        merge(arr, st, mid, end);
    }

    // Time Complexity: O(n log n) for the entire merge sort
    // Space Complexity: O(n) due to temporary arrays in each merge call
    // (not counting recursion stack)

    // Additional Space: O(log n) for recursion stack (depth of recursion tree)
}

int main()
{
    vector<int> arr = {12, 31, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size()-1);

    cout << "Merge Sort: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

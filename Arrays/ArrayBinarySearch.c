#include <stdio.h>

int binarySearchArray(int arr[], int size, int target){
    int low ,mid , high;
    low = 0, high = size-1;
    
    //Keep searching until low<=high
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    //Searching ends
    return -1;
}

void display(int arr[], int n ){
    //Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 4, 54, 76};
    int size = sizeof(arr)/sizeof(int), capacity = 50, element = 76;
    display(arr, size);
    printf("Element %d is present at index %d", element, binarySearchArray(arr, size, element));
    return 0;
}
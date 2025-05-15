#include <stdio.h>

int linearSearchArray(int arr[], int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
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
    int arr[] = {1, 4, 76, 54, 78, 99, 143, 156, 3434};
    int size = sizeof(arr)/sizeof(int), capacity = 50, element = 54;
    display(arr, 9);
    printf("Element %d is present at index %d", element, linearSearchArray(arr, size, element));
    return 0;
}
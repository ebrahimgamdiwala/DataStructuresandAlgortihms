#include <stdio.h>

void display(int arr[], int n ){
    //Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[], int size, int element, int capacity, int index){
    // Code for insertion at a specific index
    if(size>=capacity){
        return -1;
    }
    else{
        for (int i = size-1; i >=index; i--)
        {
            arr[i+1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
}

int main() {
    int arr[100] = {1, 2, 6, 78};
    int size = 4, element = 45, index = 3, capacity = 100;
    printf("Array before insertion : \n");
    display(arr, size);
    indInsertion(arr, size, element, capacity, index);
    size++;
    printf("Array after insertion : \n");
    display(arr, size);
    return 0;
}
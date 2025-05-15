#include <stdio.h>

void display(int arr[], int n ){
    //Code for Traversal
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int indDeletion(int arr[], int size, int index){
    // Code for deletion at a specific index
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i+1];
    }
    return 1;
}

int main() {
    int arr[100] = {1, 2, 6, 78};
    int size = 4, element = 45, index = 3, capacity = 100;
    printf("Array before deletion : \n");
    display(arr, size);
    indDeletion(arr, size, index);
    size--;
    printf("Array after deletion : \n");
    display(arr, size);
    return 0;
}
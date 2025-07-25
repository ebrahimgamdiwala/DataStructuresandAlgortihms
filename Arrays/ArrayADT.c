#include <stdio.h>
#include <stdlib.h>

struct myArray {
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct myArray *a, int tSize, int uSize) {
    // (*a).total_size = tSize;
    // (*a).used_size = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void showArray(struct myArray * a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ", (a->ptr)[i]);
    }
}

void setVal(struct myArray * a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter the value of element %d : ",i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main() {
    struct myArray marks;
    
    createArray(&marks, 100, 5);
    printf("We are running setVal now\n");
    setVal(&marks);

    printf("We are running showArray now\n");
    showArray(&marks);
    return 0;
}

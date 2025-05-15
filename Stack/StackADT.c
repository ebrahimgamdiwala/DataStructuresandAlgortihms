#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct Stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct Stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}


int main() {
    // struct Stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
    struct Stack * s;
    s->size = 1;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    // Pushing an element manually to the stack
    s->arr[0] = 45;
    (s->top)++;

    //Checking if stack is empty 
    if(isEmpty(s)){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }
    //Checking if stack is full
    if(isFull(s)){
        printf("The stack is full\n");
    }
    else{
        printf("The stack is not full\n");
    }

    return 0;
}
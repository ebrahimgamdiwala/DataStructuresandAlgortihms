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

void push(struct Stack * ptr, int element){
    if(isFull(ptr)){
        printf("Stack Overflow. Push operation unsuccessful\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

int pop(struct Stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow. Pop operation unsuccessful\n");
        return -1;
    }
    else{
        int element = ptr->arr[ptr->top];
        ptr->top--;
        return element;
    }
}

int peek(struct Stack * ptr, int i){
    if(isEmpty(ptr)){
        printf("Stack is Empty. Cannot peek\n");
        return -1;
    }
    else if(ptr->top-i+1 < 0 || i<= 0){
        printf("i out of bounds. Cannot peek\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int stackTop(struct Stack * ptr){
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top];
    }
    
}

int stackBottom(struct Stack * ptr){
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else{
        return ptr->arr[0];
    }
    
}

int main() {
    // struct Stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));
    struct Stack * s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    push(s,57);
    push(s,5);
    push(s,7);
    push(s,127);
    push(s,90);

    for (int j = 0; j <= s->top+1; j++)
    {
        printf("Element at position i = %d is : %d\n", j , peek(s,j));
    }
    printf("The element at the top of the stack is %d\n",stackTop(s));
    printf("The element at the bottom of the stack is %d\n",stackBottom(s));
    return 0;
}
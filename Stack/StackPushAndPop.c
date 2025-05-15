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
    push(s,11);

    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
   
    printf("%d\n",isEmpty(s));
    printf("%d\n",isFull(s));
    printf("%d\n",s->top);
    printf("%d\n",s->top);
    
    
    return 0;
}
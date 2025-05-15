#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char * arr;
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

char pop(struct Stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow. Pop operation unsuccessful\n");
        return -1;
    }
    else{
        char element = ptr->arr[ptr->top];
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

int parenthesisMatch(char * exp){
    struct Stack * sp;
    sp -> size = 100;
    sp -> top = -1;
    sp -> arr = (char *) malloc(sizeof(sp->size * sizeof(char)));
    for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp,exp[i]);
        }
        else if(exp[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            else{
                pop(sp);
            }
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main() {
    char * exp = "((a + b) * (c - d) / (e + f)";
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *ptr, int element)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow. Push operation unsuccessful\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}

char pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow. Pop operation unsuccessful\n");
        return -1;
    }
    else
    {
        char element = ptr->arr[ptr->top];
        ptr->top--;
        return element;
    }
}

char stackTop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}

int peek(struct Stack *ptr, int i)
{
    if (isEmpty(ptr))
    {
        printf("Stack is Empty. Cannot peek\n");
        return -1;
    }
    else if (ptr->top - i + 1 < 0 || i <= 0)
    {
        printf("i out of bounds. Cannot peek\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char ch){
    if(ch=='/' || ch=='*'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
}

char * infixToPostfix(char * infix){
    int i = 0;
    int j = 0;
    char * postfix = (char *) malloc((strlen(infix)+1)*sizeof(char));
    struct Stack * sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size*sizeof(char));
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char * infix = "x-y/z-k*d";
    printf("The postfix expression is : %s", infixToPostfix(infix));

    return 0;
}
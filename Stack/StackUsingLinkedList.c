#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

int isFull(){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node *));
    if(newNode == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Node * top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node * push(struct Node * top, int data){
    if(isFull()){
        printf("Stack Overflow");
        return top;
    }
    else{
        struct Node * newNode = (struct Node *) malloc(sizeof(struct Node *));
        newNode->data = data;
        newNode->next = top;
        return newNode;
    }
}
int pop(struct Node ** top){
    if(isEmpty(*top)){
        printf("Stack Underflow");
    }
    else{
        int element = (*top)->data;
        struct Node * temp = *top;
        (*top) = (*top)->next;
        free(temp);
        return element;
    }
}

int stackTop(struct Node * top){
    if(isEmpty(top)){
        printf("The stack is empty\n");
    }
    else{
        return top->data;
    }
}
int stackBottom(struct Node * top){
    if(isEmpty(top)){
        printf("The stack is empty\n");
    }
    else{
        struct Node * ptr = top;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        return ptr->data;
    }
}
int peek(struct Node * top, int pos){
    struct Node * ptr = top;
    for (int i = 0; (i < pos-1 && ptr!=NULL) ; i++)
    {
        ptr = ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
    
}
void traversal(struct Node * top){
    struct Node * ptr = top;
    while(ptr != NULL){
        printf("Element : %d\n ",ptr->data);
        ptr = ptr->next;
    }
    
} 
int main() {
    struct Node * top = NULL;
    top = push(top,43);
    top = push(top,7);
    top = push(top,47);
    top = push(top,417);
    top = push(top,1227);
    printf("Element that has been popped is %d\n",pop(&top));
    traversal(top);
    printf("The element at the top of the stack is %d\n",stackTop(top));
    printf("The element at the bottom of the stack is %d\n",stackBottom(top));
    printf("The element at index %d is %d", 3, peek(top,3));
    return 0;
}
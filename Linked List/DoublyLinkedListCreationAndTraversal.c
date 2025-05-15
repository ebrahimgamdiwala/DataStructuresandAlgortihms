#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * prev;
    struct Node * next;
};

void doublyLinkedListTraversal(struct Node * head){
    struct Node * ptr = head;
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

void doublyLinkedListReverseTraversal(struct Node * tail){
    struct Node * ptr = tail;
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->prev;
    }
}

int main() {
    struct Node * head = (struct Node *) malloc(sizeof(struct Node));
    struct Node * second = (struct Node *) malloc(sizeof(struct Node));
    struct Node * third = (struct Node *) malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *) malloc(sizeof(struct Node));

    //Linking first node to the second node
    head->data = 7;
    head->prev = NULL;
    head->next = second;

    //Linking second node to the third node and first node
    second->data = 77;
    second->prev = head;
    second->next = third;

    //Linking third node to the fourth node and second node
    third->data = 45;
    third->prev = second;
    third->next = fourth;

    //Linking fourth node to third node and terminating the list
    fourth->data = 198;
    fourth->prev = third;
    fourth->next = NULL;

    printf("Elements of the doubly linked list are :\n");
    doublyLinkedListTraversal(head);
    printf("Elements of the doubly linked list in reverse order are :\n");
    doublyLinkedListReverseTraversal(fourth);

    
    return 0;
}
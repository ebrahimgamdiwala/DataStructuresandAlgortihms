#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void circularlinkedListTraversal(struct Node * head){
    struct Node * ptr = head;
    // // Approach 1
    // printf("Element : %d \n",ptr->data);
    // ptr = ptr->next;
    // while(ptr!=head){
    //     printf("Element : %d \n",ptr->data);
    //     ptr = ptr->next;
    // }

    // Approach 2 (Cleaner Method)
    do
    {
        printf("Element : %d \n",ptr->data);
        ptr = ptr->next;
    } while (ptr!=head);
} 


int main() {
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    //Allocate the memory for nodes in heap memory
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // Link first and second node
    head->data = 7;
    head->next = second;

    // Link second and third node
    second->data = 14;
    second->next = third;

    // Link third and fourth node
    third->data = 21;
    third->next = fourth;

    // Link last node and head node
    fourth->data = 28;
    fourth->next = head;

    circularlinkedListTraversal(head);

    return 0;
}
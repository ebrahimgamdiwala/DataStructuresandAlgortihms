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

struct Node * insertAtFirst(struct Node * head, int data){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node * ptr = head->next;
    while (ptr->next!=head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
    
}
struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    struct Node * ptr = head->next;
    while (ptr->next!=head)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = head;
    return head;
    
}

struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    int i = 1;
    newNode->data = data;
    struct Node * ptr = head->next;
    while (i<index-1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
    
}

struct Node * insertAfterNode(struct Node * head, struct Node * p, int data){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    return head;
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

    // Circular Linked List before insertion
    printf("Circular Linked List before insertion :\n");
    circularlinkedListTraversal(head);
    
    // // Inserting a node at the beginning of the linked list
    // head = insertAtFirst(head, 75);
    // // Inserting a node at the end of the linked list
    // head = insertAtEnd(head, 75);
    // // Inserting a node at specified index of the linked list
    // head = insertAtIndex(head, 75, 3);
    // Inserting a node at specified index of the linked list
    head = insertAfterNode(head, second, 3);
    
    // Circular Linked List after insertion
    printf("Circular Linked List after insertion :\n");
    circularlinkedListTraversal(head);


    return 0;
}
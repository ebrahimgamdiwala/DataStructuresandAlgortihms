#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * head){
    struct Node * ptr = head;
    while(ptr != NULL){
        printf("Element : %d\n ",ptr->data);
        ptr = ptr->next;
    }
    
} 

struct Node * insertAtBeginning(struct Node * head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node * insertAtEnd(struct Node * head, int data){
    struct Node * newNode = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->data = data;
    newNode->next = NULL;
    return head;
}

struct Node * insertAfterNode(struct Node * head, struct Node * prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

struct Node * insertAtIndex(struct Node * head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    int i = 0;
    struct Node * p = head;
    while(i<index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
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

    // Terminate the list at the last node
    fourth->data = 28;
    fourth->next = NULL;

    printf("Linked List before insertion : \n");
    linkedListTraversal(head);

    // // Inserting at the beginning of the linked list
    // head = insertAtBeginning(head, 0);
    // // Inserting at a specific index of the linked list
    // head = insertAtIndex(head, 45, 1);
    // // Insert at the end of linked list 
    // head = insertAtEnd(head, 69);
    // // Insert after a specific node which is passed via pointer
    // head = insertAfterNode(head, second, 5);

    printf("Linked List after insertion : \n");
    linkedListTraversal(head);

    return 0;
}
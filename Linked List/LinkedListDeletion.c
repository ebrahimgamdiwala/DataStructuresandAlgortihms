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

struct Node * deleteAtTheBeginning(struct Node * head){
    struct Node * ptr = head->next;
    free(head);
    return ptr;
}

struct Node * deleteAtTheEnd(struct Node * head){
    struct Node * ptr = head;
    while (ptr->next->next!=NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node * curr = head;
    struct Node * prev;
    int i = 0;
    while (i<index)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }
    prev->next = curr->next;
    free(curr);
    return head;
}

struct Node * deleteNodeWithGivenValue(struct Node * head, int value){
    struct Node * curr = head;
    struct Node * prev;

    while (curr->data!=value && curr->next!=NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr->data==value){
        prev->next = curr->next;
        free(curr);
        return head;
    }

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

    // Linked list before deletion
    printf("Linked List before deletion is :\n");
    linkedListTraversal(head);
    
    // // Deleting the element at the beginning of the linked list
    // head = deleteAtTheBeginning(head);
    // //Deleting the element at the end of the linked list
    // head = deleteAtTheEnd(head);
    // // Deleting an element at a specific index of the linked list
    // head = deleteAtIndex(head, 2);
    // Deleting the node with a given value
    head = deleteNodeWithGivenValue(head,14);
    
    //Linked list after deletion
    printf("Linked List after deletion is :\n");
    linkedListTraversal(head);

    return 0;
}
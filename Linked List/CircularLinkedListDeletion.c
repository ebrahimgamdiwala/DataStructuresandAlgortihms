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

struct Node * deleteAtBeginning(struct Node * head){
    if (head == NULL) {
        return NULL;  // List is empty, nothing to delete
    }
    
    // If there's only one node in the list
    if (head->next == head) {
        free(head);  // Free the only node
        return NULL;  // List becomes empty
    }

    // Find the last node (the one whose next points to the head)
    struct Node *ptr = head;
    while (ptr->next != head) {
        ptr = ptr->next;
    }

    // The last node now points to the second node (head->next)
    struct Node *newHead = head->next;
    ptr->next = newHead;

    // Free the old head
    free(head);

    return newHead;  // Return the new head of the list
}
struct Node * deleteAtEnd(struct Node * head){
   
    // Find the last node (the one whose next points to the head)
    struct Node *ptr = head;
    struct Node *curr;
    while (ptr->next != head) {
        curr = ptr;
        ptr = ptr->next;
    }
    curr->next = head;
    free(ptr);
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
    while(curr->data!=value && curr->next!=head){
        prev=curr;
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

    // Link last node and head node
    fourth->data = 28;
    fourth->next = head;

    // Circular Linked List before deletion
    printf("Linked list before deletion :\n");
    circularlinkedListTraversal(head);
    // // Deleting the first node of circular linked list
    // head = deleteAtBeginning(head);
    // // Deleting the last node of circular linked list
    // head = deleteAtEnd(head);
    // //Delete node at specified index of circular linked list
    // head = deleteAtIndex(head, 1);
    //Deleting a node with a given value from circular linked list
    head = deleteNodeWithGivenValue(head,14);
    // Circular Linked List after deletion
    printf("Linked list after deletion :\n");
    circularlinkedListTraversal(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = x;
    newNode->next = NULL;
    
    if (front == NULL && rear == NULL) {
        // Queue is empty
        front = rear = newNode;
        rear->next = front; // Circular connection
    } else {
        // Queue has elements
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Circular connection
    }
    printf("enqueueed %d successfully\n", x);
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("QUEUE IS EMPTY (Underflow)\n");
        return;
    }
    
    struct node *temp = front;
    
    if (front == rear) {
        // Only one element in queue
        front = rear = NULL;
    } else {
        // Multiple elements in queue
        front = front->next;
        rear->next = front; // Update circular connection
    }
    
    printf("dequeued element: %d\n", temp->data);
    free(temp);
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    
    struct node *temp = front;
    printf("Queue elements: ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    
    printf("\n");
}

int main() {
    int choice, value;
    
    do {
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
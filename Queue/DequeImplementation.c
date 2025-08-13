#include <stdio.h>
#include <stdlib.h>

// Define maximum size for deque
#define N 5
int deque[N];
int f = -1;
int r = -1;

// Insert element at the front of Deque
void enqueuefront(int x) {
    if ((f == 0 && r == N-1) || (f == r+1)) {
        printf("Queue is full\n");
    } else if (f == -1 && r == -1) {
        f = r = 0;
        deque[f] = x;
        printf("%d inserted at front successfully\n", x);
    } else if (f == 0) {
        f = N-1;
        deque[f] = x;
        printf("%d inserted at front successfully\n", x);
    } else {
        f--;
        deque[f] = x;
        printf("%d inserted at front successfully\n", x);
    }
}

// Insert element at the rear of Deque
void enqueuerear(int x) {
    if ((f == 0 && r == N-1) || (f == r+1)) {
        printf("Queue is full\n");
    } else if (f == -1 && r == -1) {
        f = r = 0;
        deque[r] = x;
        printf("%d inserted at rear successfully\n", x);
    } else if (r == N-1) {
        r = 0;
        deque[r] = x;
        printf("%d inserted at rear successfully\n", x);
    } else {
        r++;
        deque[r] = x;
        printf("%d inserted at rear successfully\n", x);
    }
}

// Delete element from front of Deque
void dequeuefront() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else if (f == r) {
        printf("%d deleted from front successfully\n", deque[f]);
        f = r = -1;
    } else if (f == N-1) {
        printf("%d deleted from front successfully\n", deque[f]);
        f = 0;
    } else {
        printf("%d deleted from front successfully\n", deque[f]);
        f++;
    }
}

// Delete element from rear of Deque
void dequeuerear() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else if (f == r) {
        printf("%d deleted from rear successfully\n", deque[r]);
        f = r = -1;
    } else if (r == 0) {
        printf("%d deleted from rear successfully\n", deque[r]);
        r = N-1;
    } else {
        printf("%d deleted from rear successfully\n", deque[r]);
        r--;
    }
}

// Get the front element
int getfront() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return deque[f];
}

// Get the rear element
int getrear() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    return deque[r];
}

// Display all elements of Deque
void display() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
    } else {
        int i = f;
        printf("Queue elements: ");
        while (i != r) {
            printf("%d ", deque[i]);
            i = (i + 1) % N;
        }
        printf("%d\n", deque[r]);
    }
}

// Main function with menu-driven approach
int main() {
    int choice, x;
    
    do {
        printf("\n===== DOUBLE ENDED QUEUE MENU =====\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display\n");
        printf("6. Get Front Element\n");
        printf("7. Get Rear Element\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &x);
                enqueuefront(x);
                break;
                
            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &x);
                enqueuerear(x);
                break;
                
            case 3:
                dequeuefront();
                break;
                
            case 4:
                dequeuerear();
                break;
                
            case 5:
                display();
                break;
                
            case 6:
                x = getfront();
                if (x != -1)
                    printf("Front element: %d\n", x);
                break;
                
            case 7:
                x = getrear();
                if (x != -1)
                    printf("Rear element: %d\n", x);
                break;
                
            case 8:
                printf("Exiting program.\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (1);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front;
    struct QueueNode *rear;
};

struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

void enqueue(struct Queue *queue, int data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Successfully Enqueued\n");
}

void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Empty\n");
        return;
    }
    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    printf("Successfully Dequeued\n");
}

void traversal(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Empty\n");
        return;
    }
    struct QueueNode *ptr = queue->front;
    printf("Queue Elements: ");
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Empty\n");
        return -1;
    }
    printf("Front Element: %d", queue->front->data);
    return queue->front->data;
}

int rear(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Empty\n");
        return -1;
    }
    printf("Rear Element: %d", queue->rear->data);
    return queue->rear->data;
}

int main() {
    struct Queue *myQueue = createQueue();
    char ch;
    int data;

    do {
        printf("Choose:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display/Traverse\n");
        printf("4. Peek\n");
        printf("5. Rear\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &ch);
        getchar();
        
        switch (ch) {
            case '1':
                printf("Enter data: ");
                scanf("%d", &data);
                getchar();
                enqueue(myQueue, data);
                break;
            case '2':
                dequeue(myQueue);
                break;
            case '3':
                traversal(myQueue);
                break;
            case '4':
                peek(myQueue);
                break;
            case '5':
                rear(myQueue);
                break;
            case '6':
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (ch != '6');

    return 0;
}

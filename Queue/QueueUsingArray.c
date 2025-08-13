#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int array[MAX_SIZE];
    int front;
    int rear;
};

struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue *queue) {
    return (queue->front == -1);
}

int isFull(struct Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue *queue, int data) {
    if (isFull(queue)) {
        printf("queue is full\n");
        return;
    }
    
    if (queue->front == -1) {
        queue->front = 0;
    }
    
    queue->rear++;
    queue->array[queue->rear] = data;
    printf("successfully enqueued\n");
}

void dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("queue is empty\n");
        return;
    }
    
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    
    printf("successfully dequeued\n");
}

void traversal(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("queue empty\n");
        return;
    }
    
    printf("queue elements are:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int peek(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("queue empty\n");
        return -1;
    }
    
    printf("front element: %d", queue->array[queue->front]);
    return queue->array[queue->front];
}

int rear(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("queue empty\n");
        return -1;
    }
    
    printf("rear element: %d", queue->array[queue->rear]);
    return queue->array[queue->rear];
}

int main() {
    struct Queue *myQueue = createQueue();
    char ch;
    int data;
    
    do {
        printf("choose:\n");
        printf("1. enqueue\n");
        printf("2. dequeue\n");
        printf("3. display/traverse\n");
        printf("4. peek\n");
        printf("5. rear\n");
        printf("6. exit\n");
        printf("enter your choice: ");
        scanf(" %c", &ch);
        getchar();
        
        switch (ch) {
            case '1':
                printf("enter data: ");
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
                printf("invalid\n");
                break;
        }
    } while (ch != '6');
    
    free(myQueue);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Maximum size of the queue

typedef struct Queue {
    int items[SIZE];
    int front;
    int rear;
} Queue;


void initializeQueue(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
void displayQueue(Queue *q);

int main() {
    Queue q;
    initializeQueue(&q);

    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                value = dequeue(&q);
                if (value != -1)
                    printf("Dequeued: %d\n", value);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}


void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int isFull(Queue *q) {
    return q->rear == SIZE - 1;
}


int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}


void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->items[++q->rear] = value;
    printf("Enqueued: %d\n", value);
}


int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int value = q->items[q->front++];
    if (q->front > q->rear) {
        // Reset the queue when empty
        q->front = -1;
        q->rear = -1;
    }
    return value;
}


void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

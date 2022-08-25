#include<stdlib.h>


typedef struct Queue {
    int* data, front, rear, capacity;
} Queue;

Queue * createQueue(int size);
int isFull(Queue* q);
int isEmpty(Queue* q);
int getRear(Queue* q);
int getFront(Queue* q);
int enqueue(Queue* q, int item);
int dequeue(Queue* q);

int isFull(Queue *q) {
    return (q->rear + 1) % q->capacity == q->front;
}

int isEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

int getRear(Queue* q) {
    return q->data[q->rear];
}

int getFront(Queue* q) {
    return q->data[q->front];
}

int enqueue(Queue* q, int item) {
    if (isFull(q)) return -1;
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
        q->data[q->rear] = item;
    }

    else {
        q->rear = (q->rear + 1) % q->capacity;
        q->data[q->rear] = item;
    }
    return 1;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    if (q->rear == q->front) {
        int data = q->data[q->front];
        q->front = -1;
        q->rear = -1;
        return data;
    }
    else {
        int data = q->data[q->front];
        q->front = (q->front + 1) % q->capacity;
        return data;
    }
}

Queue* createQueue(int size) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->data = (int*) malloc(size * sizeof(int));
    q->front = q->rear = -1;
    q->capacity = size;
    return q;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int *arr;
    int capacity;
} circularQ;

circularQ *createQ(int capacity) {
    circularQ *q = malloc(sizeof(circularQ *));
    q->arr = malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    q->front = q->rear = -1;
    return q;
};

char isQEmpty(circularQ *q) {
    if (q->front == -1)
        return 1;
    return 0;
};

char isQFull(circularQ *q) {
    if ((q->front == 0 && q->rear == q->capacity - 1) ||
        (q->rear == (q->front - 1) % (q->capacity)))
        return 1;
    return 0;
};

void enqueue(circularQ *q, int value) {
    if (isQFull(q)) {
        printf("ERROR : Queue is full\n");
        return;
    }
    if (isQEmpty(q)) {
        q->arr[0] = value;
        q->front = q->rear = 0;
        return;
    }
    q->rear = (q->rear + 1) % (q->capacity);
    q->arr[q->rear] = value;
};

void dequeue(circularQ *q) {
    if (isQEmpty(q)) {
        printf("ERROR : Queue is empty\n");
        return;
    }
    if (q->front == q->rear) {
        q->front = q->rear = -1;
        return;
    }
    q->front = (q->front + 1) % q->capacity;
};

int peek(circularQ *q) {
    if (isQEmpty(q)) {
        printf("ERROR : circularQ is empty\n");
        exit(EXIT_FAILURE);
    }
    return q->arr[q->front];
};

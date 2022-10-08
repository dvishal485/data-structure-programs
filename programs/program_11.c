#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int *arr;
    int capacity;
} queue;

queue *createQ(int capacity) {
    queue *q = malloc(sizeof(queue *));
    q->arr = malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    q->front = q->rear = -1;
    return q;
};

char isEmpty(queue *q) {
    if (q->front == q->rear && q->front == -1)
        return 1;
    return 0;
};

char isFull(queue *q) {
    if (q->rear == q->capacity - 1)
        return 1;
    return 0;
};

void enqueue(queue *q, int value) {
    if (isFull(q)) {
        printf("ERROR : Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->arr[++q->rear] = value;
        q->front = q->rear;
    }
    q->arr[++q->rear] = value;
};

void dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("ERROR : Queue is empty\n");
        return;
    }
    q->front++;
    if (q->front == q->rear)
        q->front = q->rear = -1;
};

int peek(queue *q) {
    if (isEmpty(q)) {
        printf("ERROR : Queue is empty\n");
        exit(-1);
    }
    return q->arr[q->front];
};

int main(void) {
    queue *q = createQ(10);
    enqueue(q, 14);
    enqueue(q, 18);
    enqueue(q, 5);
    printf("Peek : %d\n", peek(q));
    dequeue(q);
    printf("Peek : %d\n", peek(q));
    dequeue(q);
    printf("Peek : %d\n", peek(q));
    dequeue(q);
    dequeue(q);
    enqueue(q, 7);
    enqueue(q, 2);
    printf("Peek : %d\n", peek(q));
    return 0;
};
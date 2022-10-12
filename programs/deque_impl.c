#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int capacity;
} deque;

deque *createDeque(int capacity) {
    deque *q = (deque *)malloc(sizeof(deque));
    q->arr = (int *)calloc(sizeof(int) * capacity, sizeof(int));
    q->capacity = capacity;
    q->front = q->rear = -1;
    return q;
}

char isQEmpty(deque *q) {
    if (q->front == -1)
        return 1;
    return 0;
};

char isQFull(deque *q) {
    if ((q->front == 0 && q->rear == q->capacity - 1) ||
        (q->rear == (q->front - 1) % (q->capacity)))
        return 1;
    return 0;
};

void push_back(deque *q, int value) {
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
}
void push_front(deque *q, int value) {
    if (isQFull(q)) {
        printf("ERROR : Queue is full\n");
        return;
    }
    if (isQEmpty(q)) {
        q->arr[0] = value;
        q->front = q->rear = 0;
        return;
    }
    q->front = (q->front - 1) < 0 ? q->capacity - 1 : q->front - 1;
    q->arr[q->front] = value;
}

void pop_front(deque *q) {
    if (isQEmpty(q)) {
        printf("ERROR : Queue is empty\n");
        return;
    }
    if (q->front == q->rear) {
        q->front = q->rear = -1;
        return;
    }
    q->front = (q->front + 1) % q->capacity;
}

void pop_back(deque *q) {
    if (isQEmpty(q)) {
        printf("ERROR : Queue is empty\n");
        return;
    }
    if (q->front == q->rear) {
        q->front = q->rear = -1;
        return;
    }
    q->rear = (q->rear - 1) < 0 ? q->capacity - 1 : q->rear - 1;
}

void showFullQ(deque *q) {
    for (int i = 0; i < q->capacity; i++) {
        if (i == q->front && i == q->rear)
            printf("_%d_ ", q->arr[i]);
        else if (i == q->front)
            printf("[%d] ", q->arr[i]);
        else if (i == q->rear)
            printf("{%d} ", q->arr[i]);
        else
            printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int peek_front(deque *q) {
    if (isQEmpty(q)) {
        printf("ERROR : Queue is empty! Cannot peek.");
        exit(EXIT_FAILURE);
    }
    return q->arr[q->front];
}

int peek_back(deque *q) {
    if (isQEmpty(q)) {
        printf("ERROR : Queue is empty! Cannot peek.");
        exit(EXIT_FAILURE);
    }
    return q->arr[q->rear];
}

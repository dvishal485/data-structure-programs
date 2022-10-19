#include "stack_impl.c"

typedef struct {
    stack *s;
} myQueue;

myQueue *createQ(int capacity) {
    myQueue *q = (myQueue *)malloc(sizeof(myQueue));
    q->s = createStack(capacity);
    return q;
}

void enqueue(myQueue *q, int x) { push(q->s, x); }

void dequeue(myQueue *q) {
    if (isEmpty(q->s)) {
        printf("ERROR : Queue empty!\n");
        return;
    }
    int x = top(q->s);
    if (size(q->s) != 1) {
        pop(q->s);
        dequeue(q);
        push(q->s, x);
        return;
    }
    pop(q->s);
}

int peek(myQueue *q) {
    if (isEmpty(q->s)) {
        printf("ERROR : Queue empty!\n");
        exit(EXIT_FAILURE);
    }
    int x = top(q->s);
    int y = x;
    if (size(q->s) != 1) {
        pop(q->s);
        x = peek(q);
        push(q->s, y);
    }
    return x;
}

char isQEmpty(myQueue *q) { return isEmpty(q->s); }

int main(void) {
    myQueue *q = createQ(15);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Peek queue : %d\n", peek(q));
    dequeue(q);
    printf("Peek queue : %d\n", peek(q));
    dequeue(q);
    enqueue(q, 40);
    dequeue(q);
    printf("Peek queue : %d\n", peek(q));
    return 0;
}

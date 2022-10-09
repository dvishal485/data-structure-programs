#include "./queue_impl.c"
#include "./stack_impl.c"
#include <stdio.h>

void *reverseKElement(queue *q, int k) {
    stack *s = createStack(k);
    int upto = q->front + k;

    for (int i = q->front; i < upto; i++) {
        push(s, peek(q));
        dequeue(q);
    }
    queue *t = createQ(q->capacity - k);
    while (!isQueueEmpty(q)) {
        enqueue(t, peek(q));
        dequeue(q);
    }
    while (!isEmpty(s)) {
        enqueue(q, top(s));
        pop(s);
    }
    while (!isQueueEmpty(t)) {
        enqueue(q, peek(t));
        dequeue(t);
    }
}

int main(void) {
    queue *q = createQ(15);
    for (int i = 1; i <= 15; i++)
        enqueue(q, i);
    showQ(q);
    reverseKElement(q, 7);
    showQ(q);
}

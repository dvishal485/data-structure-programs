/*
Q. We have discussed the problem of implementing Queue using two stacks using an
approach where the enqueue operation is constant time while dequeue operation
takes O(n) time. Think about a different approach of implementing queue using
two stacks where enqueue operation may be costly but the dequeue operation
remains O(1). Write the enqueue and dequeue operations code for this new
approach.
*/

#include "../stack_impl.c"

typedef struct {
    stack *s1;
    stack *s2;
} queue;

queue *createQueue(int capacity) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->s1 = createStack(capacity);
    q->s2 = createStack(capacity);
    return q;
}
void enqueue(queue *q, int x) {
    while (!isEmpty(q->s1)) {
        push(q->s2, top(q->s1));
        pop(q->s1);
    }
    push(q->s2, x);
    while (!isEmpty(q->s2)) {
        push(q->s1, top(q->s2));
        pop(q->s2);
    }
}

void dequeue(queue *q) { pop(q->s1); }
int peek(queue *q) { return top(q->s1); }

int main(void) {
    queue *q = createQueue(10);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("%d\n", peek(q));
    enqueue(q, 40);
    dequeue(q);
    enqueue(q, 50);
    dequeue(q);
    printf("%d\n", peek(q));
    return 0;
}
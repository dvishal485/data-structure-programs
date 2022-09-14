#include "stack_impl.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    stack *stack;
    stack *minStack;
} minstack;

minstack *createMinStack(int capacity) {
    minstack *m = (minstack *)malloc(sizeof(minstack));
    m->minStack = createStack(capacity);
    m->stack = createStack(capacity);
    return m;
}

void minstack_push(minstack *m, int x) {
    push(m->stack, x);
    if (!isEmpty(m->minStack))
        push(m->minStack, (top(m->minStack) > x ? x : top(m->minStack)));
    else
        push(m->minStack, x);
}

int minstack_top(minstack *m) {
    if (!isEmpty(m->stack))
        return top(m->stack);
    printf("Stack is empty!\n");
    return -1;
}

void minstack_pop(minstack *m) {
    if (isEmpty(m->stack))
        return;
    pop(m->stack);
    pop(m->minStack);
}

int getMinimum(minstack *m) { return top(m->minStack); }

int main(void) {
    minstack *s = createMinStack(10);
    minstack_push(s, 31);
    minstack_push(s, 72);
    minstack_push(s, 10);
    minstack_push(s, 45);
    readStack(s->stack);
    printf("Top element : %d\n", minstack_top(s));
    printf("Minimum element : %d\n\n", getMinimum(s));
    minstack_pop(s);
    minstack_pop(s);
    readStack(s->stack);
    printf("Top element : %d\n", minstack_top(s));
    printf("Minimum element : %d\n", getMinimum(s));
    return 0;
}

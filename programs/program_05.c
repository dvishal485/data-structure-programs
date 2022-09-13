#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int top;
    int capacity;
} stack;

stack *createStack(int capacity) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->array = (int *)(malloc(sizeof(int) * capacity));
    s->capacity = capacity;
    s->top = -1;
}

void pop(stack *s) {
    if (s->top != -1) {
        s->top--;
        printf("Top element popped!\n");
    } else
        printf("ERROR : Stack underflow");
}

int isFull(stack *s) {
    if (s->top == s->capacity - 1)
        return 1;
    return 0;
}

int isEmpty(stack *s) {
    if (s->top == -1)
        return 1;
    return 0;
}

void push(stack *s, int x) {
    if (s->top != s->capacity - 1) {
        s->array[++s->top] = x;
        printf("Pushed %d!\n", x);
    } else
        printf("ERROR : Stack overflow");
}

int top(stack *s) {
    if (s->top != -1)
        return s->array[s->top];
}

int main() {
    stack *s = createStack(10);
    push(s, 10);
    push(s, 72);
    push(s, 45);
    printf("Top element : %d\n", top(s));
    pop(s);
    pop(s);
    printf("Top element : %d\n", top(s));
    return 0;
}

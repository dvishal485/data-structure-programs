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
    return s;
}

void readStack(stack *s) {
    printf("Stack : ");
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->array[i]);
    printf("\n");
}

void pop(stack *s) {
    if (s->top != -1) {
        s->top--;
    } else
        printf("ERROR : Stack underflow");
}

char isFull(stack *s) {
    if (s->top == s->capacity - 1)
        return 1;
    return 0;
}

char isEmpty(stack *s) {
    if (s->top == -1)
        return 1;
    return 0;
}

void push(stack *s, int x) {
    if (s->top != s->capacity - 1) {
        s->array[++s->top] = x;
    } else
        printf("ERROR : Stack overflow");
}

int top(stack *s) {
    if (s->top != -1)
        return s->array[s->top];
    printf("ERROR : Stack is empty");
    exit(EXIT_FAILURE);
}

int size(stack *s) { return s->top + 1; }

#include "circularQ_impl.c"

typedef struct {
    circularQ *front;
} MyStack;

MyStack *myStackCreate(int capacity) {
    MyStack *m = ((MyStack *)malloc(sizeof(MyStack)));
    m->front = createQ(capacity);
    return m;
}

void myStackPush(MyStack *obj, int x) { enqueue(obj->front, x); }

void myStackPop(MyStack *obj) {
    if (isQEmpty(obj->front)) {
        printf("ERROR : Empty stack!");
        return;
    }
    int size = qSize(obj->front);
    while (--size) {
        enqueue(obj->front, peek(obj->front));
        dequeue(obj->front);
    }
    dequeue(obj->front);
}

int myStackTop(MyStack *obj) {
    if (isQEmpty(obj->front)) {
        printf("ERROR : Empty stack!\n");
        exit(EXIT_FAILURE);
    }
    int size = qSize(obj->front);
    while (--size) {
        enqueue(obj->front, peek(obj->front));
        dequeue(obj->front);
    }
    int x = peek(obj->front);
    dequeue(obj->front);
    enqueue(obj->front, x);
    return x;
}

char myStackEmpty(MyStack *obj) { return isQEmpty(obj->front); }

int main(void) {
    MyStack *stack = myStackCreate(20);
    myStackPush(stack, 10);
    myStackPush(stack, 11);
    myStackPush(stack, 12);
    printf("Top Element in stack : %d\n", myStackTop(stack));
    myStackPop(stack);
    printf("Top Element in stack : %d\n", myStackTop(stack));
    myStackPop(stack);
    printf("Top Element in stack : %d\n", myStackTop(stack));
    myStackPush(stack, 30);
    printf("Top Element in stack : %d\n", myStackTop(stack));
    myStackPop(stack);
    printf("Top Element in stack : %d\n", myStackTop(stack));
    return 0;
}

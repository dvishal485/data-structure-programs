#include "stack_impl.c"

typedef struct {
    stack *s;
    int min;
} dasMinStack;

dasMinStack *createDasMinStack(int capacity) {
    dasMinStack *dms = malloc(sizeof(dasMinStack));
    dms->s = createStack(capacity);
    return dms;
}

void dasPush(dasMinStack *dms, int x) {
    if (isEmpty(dms->s)) {
        dms->min = x;
        push(dms->s, 0);
    } else {
        push(dms->s, x - dms->min);
        if (x < dms->min)
            dms->min = x;
    }
}

int dasTop(dasMinStack *dms) {
    int x = top(dms->s) + dms->min;
    if (x > 0)
        return x;
    else
        return dms->min;
}

void dasPop(dasMinStack *dms) {
    int x = top(dms->s);
    pop(dms->s);
    if (x < 0)
        dms->min = dms->min - x;
}

void printStack(dasMinStack *dms) {
    int min = dms->min;
    for (int i = dms->s->top; i >= 0; i--) {
        int t = dms->s->array[i];
        if (t < 0) {
            printf("%d ", min);
            min = min - t;
        } else
            printf("%d ", t + min);
    }
    printf("\n");
}

int main(void) {
    dasMinStack *s = createDasMinStack(10);
    dasPush(s, 31);
    printStack(s);
    
    printf("Top element : %d\n", dasTop(s));
    printf("Minimum element : %d\n\n", s->min);
    dasPush(s, 72);
    printStack(s);
    
    printf("Top element : %d\n", dasTop(s));
    printf("Minimum element : %d\n\n", s->min);
    dasPush(s, 10);
    printStack(s);
    
    printf("Top element : %d\n", dasTop(s));
    printf("Minimum element : %d\n\n", s->min);
    dasPush(s, 45);
    printStack(s);
    
    printf("Top element : %d\n", dasTop(s));
    printf("Minimum element : %d\n\n", s->min);
    printStack(s);
    
    printf("Top element : %d\n", dasTop(s));
    printf("Minimum element : %d\n\n", s->min);
    dasPop(s);
    printStack(s);
    
    printf("Top element : %d\n", dasTop(s));
    printf("Minimum element : %d\n\n", s->min);
    dasPop(s);
    printStack(s);
    
    printf("Top element : %d\n", dasTop(s));
    printf("Minimum element : %d\n\n", s->min);
    // printStack(s);
    // printf("Top element : %d\n", dasTop(s));
    // printf("Minimum element : %d\n", s->min);
    return 0;
}

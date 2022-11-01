// Write a C/C++ program to implement Tower of Hanoi Problem using Stack.
#include "stack_impl.c"
#include <stdio.h>
stack *from_rod, *to_rod, *aux_rod;
long long itr = 0;

void solveHanoi(int n, stack *from, stack *to, stack *helper) {
    if (n == 0)
        return;
    itr++;
    solveHanoi(n - 1, from, helper, to);
    int t = top(from);
    push(to, t);
    pop(from);
    solveHanoi(n - 1, helper, to, from);
}

int main(void) {
    int n = 3;
    from_rod = createStack(n);
    aux_rod = createStack(n);
    to_rod = createStack(n);
    for (int i = n; i > 0; i--) {
        push(from_rod, i);
    }

    printf("Tower of Hanoi before solving :\n");
    readStack(from_rod);
    readStack(aux_rod);
    readStack(to_rod);

    solveHanoi(n, from_rod, to_rod, aux_rod);

    printf("\nTower of Hanoi after solving :\n");
    readStack(from_rod);
    readStack(aux_rod);
    readStack(to_rod);
    printf("\nTook %lld recursive calls\n", itr);
    return 0;
}
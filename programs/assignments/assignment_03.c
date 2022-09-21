/*
Given a linked list, write a program to swap every two adjacent nodes and return
its head. You must solve the problem without modifying the values in the linked
list nodes. For a linked list with odd number of nodes, last node should not be
swapped.
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int data, struct node *next) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

struct node *swapAlterNodes(struct node *head) {
    if (head->next == NULL)
        return head;
    struct node *a, *b, *c;
    a = head;
    b = head->next;
    if (b->next != NULL)
        c = swapAlterNodes(b->next);
    else
        c = NULL;
    b->next = a;
    a->next = c;
    return b;
}

void traverse(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *x = createNode(11, NULL);
    for (int i = 10; i > 0; i--) {
        x = createNode(i, x);
    }
    printf("Before Swapping :\t");
    traverse(x);
    printf("\nAfter Swapping :\t");
    x = swapAlterNodes(x);
    traverse(x);
    return 0;
}
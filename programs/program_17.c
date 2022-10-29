/*
Given a Sorted doubly linked list of positive integers and an integer, finds all
the pairs (sum of two nodes data part) that is equal to the given integer value.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct doublyLL {
    int value;
    struct doublyLL *left;
    struct doublyLL *right;
} doublyLL;

doublyLL *createNode(int value, doublyLL *left, doublyLL *right) {
    doublyLL *x = (doublyLL *)malloc(sizeof(doublyLL));
    x->value = value;
    x->left = left;
    x->right = right;
}

void twoSum(doublyLL *head, int sum) {
    if (!head || !head->right) {
        printf("ERROR : Invalid Input!");
        exit(EXIT_FAILURE);
    }
    doublyLL *a = head, *b = head->right;
    while (b->right) {
        b = b->right;
    }
    int fsum = a->value + b->value;
    while (a != b) {
        if (fsum > sum) {
            b = b->left;
        } else if (fsum < sum) {
            a = a->right;
        } else {
            printf("(%d, %d)\n", a->value, b->value);
            if (a->right == b)
                return;
            a = a->right;
            b = b->left;
        }
        fsum = a->value + b->value;
    }
}

void printLL(doublyLL *head) {
    printf("Linked List : ");
    while (head) {
        printf("%d, ", head->value);
        head = head->right;
    }
    printf("\n");
}

int main() {
    doublyLL *head = createNode(1, NULL, NULL);
    doublyLL *l = head;
    for (int i = 2; i <= 10; i++) {
        doublyLL *x =
            createNode((i * i) / 7 + i, l, NULL); // some sorted Linked List
        l->right = x;
        l = x;
    }
    printLL(head);
    twoSum(head, 10); // find pair of elements for which sum = 10
    return 0;
}

/*
Write an program to concatenate two doubly circular linked lists l1 and l2.
l1 and l1 are pointers to first node of linked lists respectively.

Note : After concatenation (l1 followed by l2), l1 points to first node
of final linked list.
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

doublyLL *arrayToDoublyCircLL(int arr[], int size) {
    if (size <= 0)
        return NULL;
    doublyLL *head = createNode(arr[0], NULL, NULL);
    if (size == 1)
        return head;
    doublyLL *x = createNode(arr[1], head, NULL);
    head->right = x;
    for (int i = 2; i < size; i++) {
        x->right = createNode(arr[i], x, NULL);
        x = x->right;
    }
    x->right = head;
    head->left = x;
    return head;
}

void printCircLL(doublyLL *head) {
    doublyLL *traverse = head;
    printf("Circular Linked List : ");
    while (traverse != head->left && traverse) {
        printf("%d, ", traverse->value);
        traverse = traverse->right;
    }
    printf("%d", traverse->value);
    printf("\n");
}

doublyLL *concat(doublyLL **l1, doublyLL **l2) {
    if (!*l1) {
        *l1 = *l2;
        return *l1;
    }
    if (!l2)
        return *l1;
    doublyLL *traverse = *l1;
    while (traverse->right != *l1)
        traverse = traverse->right;
    traverse->right = *l2;
    (*l2)->left = traverse;
    traverse = *l2;
    while (traverse->right != *l2)
        traverse = traverse->right;
    traverse->right = *l1;
    (*l1)->left = traverse;
}

int main(void) {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    doublyLL *head1 = arrayToDoublyCircLL(arr1, size1);
    doublyLL *head2 = arrayToDoublyCircLL(arr2, size2);
    printCircLL(head1);
    printCircLL(head2);
    doublyLL *x = concat(&head1, &head2);
    printCircLL(x);
    return 0;
}
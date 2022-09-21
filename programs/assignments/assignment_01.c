/*
Given the head of a linked list and an integer n, write a program to delete nth
node from the end of linked list and return the head of new list.
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

struct node *removeNthFromEnd(struct node *head, int n) {
    struct node fake_head = {0, head};
    struct node *traverse = &fake_head;
    struct node *temp = &fake_head;
    int k = 0;
    while (traverse != NULL) {
        traverse = traverse->next;
        if (k++ > n)
            temp = temp->next;
    }
    traverse = temp->next;
    temp->next = (temp->next)->next;
    free(traverse);
    traverse = NULL;
    return fake_head.next;
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
    struct node *x = createNode(5, NULL);
    for (int i = 0; i < 10; i++) {
        x = createNode(i, x);
    }
    traverse(x);
    x = removeNthFromEnd(x, 4);
    traverse(x);
    return 0;
}
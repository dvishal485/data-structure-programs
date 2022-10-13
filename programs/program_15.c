#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node;

node *createNode(int value) {
    node *x = (node *)malloc(sizeof(node));
    x->value = value;
    x->next = NULL;
}

node *insertFromStart(node **pointer_to_head, int n, int value) {
    node fake_head = {0, *pointer_to_head};
    node *traverse = &fake_head;
    while (--n && traverse->next) {
        traverse = traverse->next;
    }
    node *x = createNode(value);
    x->next = traverse->next;
    traverse->next = x;
    *pointer_to_head = fake_head.next;
    return fake_head.next;
}

node *insertAtStart(node **pointer_to_head, int value) {
    return insertFromStart(pointer_to_head, 1, value);
}

void printLL(node *head) {
    printf("Linked List : ");
    while (head) {
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    insertAtStart(&head, 25);
    printLL(head);
    insertAtStart(&head, 36);
    insertFromStart(&head, 2, 49);
    printLL(head);
    return 0;
}
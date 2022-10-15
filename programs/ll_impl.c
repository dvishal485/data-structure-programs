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

node *insertAtEnd(node **pointer_to_head, int value) {
    if (*pointer_to_head == NULL) {
        *pointer_to_head = createNode(value);
        return *pointer_to_head;
    }
    node *traverse = *pointer_to_head;
    while (traverse->next) {
        traverse = traverse->next;
    }
    traverse->next = createNode(value);
    return *pointer_to_head;
}

node *insertAtStart(node **pointer_to_head, int value) {
    if (*pointer_to_head == NULL) {
        *pointer_to_head = createNode(value);
        return *pointer_to_head;
    }
    node *x = createNode(value);
    x->next = *pointer_to_head;
    *pointer_to_head = x;
    return x;
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

node *arrayToLL(int arr[], int size) {
    if (size <= 0)
        return NULL;
    node *head = createNode(arr[0]);
    if (size == 1)
        return head;
    node *x = createNode(arr[1]);
    head->next = x;
    for (int i = 2; i < size; i++) {
        x->next = createNode(arr[i]);
        x = x->next;
    }
    return head;
}

char deleteNode(node *prev_node) {
    if (prev_node == NULL)
        return 0;
    node *deletion = prev_node->next;
    if (deletion) {
        prev_node->next = deletion->next;
        free(deletion);
        return 1;
    }
}

node *deleteFromStart(node **pointer_to_head, int n) {
    node fake_head = {0, *pointer_to_head};
    node *traverse = &fake_head;
    while (--n && traverse->next) {
        traverse = traverse->next;
    }
    deleteNode(traverse);
    *pointer_to_head = fake_head.next;
    return fake_head.next;
}

node *deleteAtStart(node **pointer_to_head) {
    if (!*pointer_to_head)
        return *pointer_to_head;
    node *x = (*pointer_to_head)->next;
    free(*pointer_to_head);
    *pointer_to_head = x;
    return x;
}

node *deleteFromEnd(node **pointer_to_head, int n) {
    if (n <= 0)
        return *pointer_to_head;
    node fake_head = {0, *pointer_to_head};
    node *traverse = &fake_head;
    node *temp = &fake_head;
    int k = 0;
    while (traverse != NULL) {
        traverse = traverse->next;
        if (k++ > n)
            temp = temp->next;
    }
    if (k <= n)
        return fake_head.next;
    deleteNode(temp);
    *pointer_to_head = fake_head.next;
    return fake_head.next;
}

void printLL(node *head) {
    printf("Linked List : ");
    while (head) {
        printf("%d, ", head->value);
        head = head->next;
    }
    printf("\n");
}

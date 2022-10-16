/*
    Q. Implement insertion sort using linked list
    without destroying the original linked list
*/

#include "../ll_impl.c"

void insertionSortLL(node *head, node **ptr_to_head) {
    if (!head)
        return;
    if (!*ptr_to_head) {
        *ptr_to_head = createNode(head->value);
        return insertionSortLL(head->next, ptr_to_head);
    }
    node *traverse = *ptr_to_head;
    int counter = 1;
    while (traverse) {
        if (head->value < traverse->value) {
            insertFromStart(ptr_to_head, counter, head->value);
            return insertionSortLL(head->next, ptr_to_head);
        }
        traverse = traverse->next;
        counter++;
    }
    insertFromStart(ptr_to_head, counter, head->value);
    return insertionSortLL(head->next, ptr_to_head);
}

int main() {
    node *head = NULL, *x = NULL;
    insertAtEnd(&head, 48);
    insertAtEnd(&head, 49);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 36);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 27);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 20);
    insertionSortLL(head, &x);
    printLL(head);
    printLL(x);
    return 0;
}

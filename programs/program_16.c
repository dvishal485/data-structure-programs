#include "ll_impl.c"

void splitLinkedList(node *head, node **l1, node **l2) {
    if (head == NULL) {
        *l1 = NULL;
        *l2 = NULL;
        return;
    }
    node *alpha = head;
    node *sigma = head;
    while (sigma->next && sigma->next->next) {
        alpha = alpha->next;
        sigma = sigma->next->next;
    }
    *l2 = alpha->next;
    alpha->next = NULL;
    *l1 = head;
}

int main() {
    node *head = NULL, *l1, *l2;
    for (int i = 1; i <= 7; i++)
        insertAtEnd(&head, i);
    printLL(head);
    printf("\nSplitting original linked list into 2 sublists\n\n");
    splitLinkedList(head, &l1, &l2);
    printf("Sublist 1 : ");
    printLL(l1);
    printf("Sublist 2 : ");
    printLL(l2);
}

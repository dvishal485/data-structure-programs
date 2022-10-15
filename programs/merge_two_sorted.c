#include "ll_impl.c"

node *mergeTwoSortedLists(node *list1, node *list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    node *temp;
    if (list1->value > list2->value) {
        temp = list2;
        list2 = list1;
        list1 = temp;
    }
    node *head = list1;
    temp = list2;
    while (list1->next && list2) {
        if (list2->value <= list1->next->value) {
            temp = list2->next;
            list2->next = list1->next;
            list1->next = list2;
            list2 = temp;
        }
        list1 = list1->next;
    }
    if (list2) {
        list1->next = list2;
    }
    return head;
};

int main(void) {
    int list1[] = {13, 16, 34, 78, 92, 105};
    int list2[] = {12, 15, 30, 36, 52, 78, 85, 90, 92, 100};
    node *l1 = arrayToLL(list1, sizeof(list1) / sizeof(int));
    node *l2 = arrayToLL(list2, sizeof(list2) / sizeof(int));
    printLL(l1);
    printLL(l2);
    printf("\nAfter merging the sorted lists :\n");
    node *merged = mergeTwoSortedLists(l1, l2);
    printLL(merged);
}
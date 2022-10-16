#include "../bt_impl.c"
#include "../ll_impl.c"

void flattenToLL(btNode *root, node **flatten) {
    if (!root) {
        return;
    } else {
        if (root->left)
            flattenToLL(root->left, flatten);
        insertAtEnd(flatten, root->value);
        if (root->right)
            flattenToLL(root->right, flatten);
    }
}

btNode *generate() {
    btNode *x = createBtNode(5);
    x->left = createBtNode(4);
    x->right = createBtNode(7);
    x->right->left = createBtNode(6);
    x->right->right = createBtNode(8);
    return x;
}

int main(void) {
    btNode *root = generate();
    node *head = NULL;
    flattenToLL(root, &head);
    printLL(head);
    return 0;
}

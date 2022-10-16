/*
Write a function which takes input a binary search tree T1 and returns a
duplicate tree T2. The duplicate tree should have the same structure as T1, but
the node values should be independent of T1. That is, if you change the value of
a node in the original tree, the corresponding node in the duplicate tree should
not change.
*/

#include "bt_impl.c"

btNode *copy_bt(btNode *root) {
    if (!root) {
        return NULL;
    } else {
        btNode *x = createBtNode(root->value);
        x->left = copy_bt(root->left);
        x->right = copy_bt(root->right);
        return x;
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
    btNode *t1 = generate();
    printf("Tree 1 (Inorder Traversal) : ");
    inOrderTraversal(t1);
    btNode *t2 = copy_bt(t1);
    printf("\nTree 2 (Inorder Traversal) : ");
    inOrderTraversal(t2);
    printf("\nTree 1 and Tree 2 are equivalent : %s\n",
           areEquivalentBT(t1, t2) ? "Yes" : "No");
    return 0;
}

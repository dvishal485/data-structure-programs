#include <stdio.h>
#include <stdlib.h>

typedef struct btNode {
    int value;
    struct btNode *left;
    struct btNode *right;
} btNode;

btNode *createBtNode(int value) {
    btNode *x = (btNode *)malloc(sizeof(btNode));
    x->value = value;
    x->left = NULL;
    x->right = NULL;
    return x;
}

void inOrderTraversal(btNode *root) {
    if (!root) {
        return;
    } else {
        if (root->left)
            inOrderTraversal(root->left);
        printf("%d, ", root->value);
        if (root->right)
            inOrderTraversal(root->right);
    }
}

void btCountNodes(btNode *root, int *internal, int *leaf) {
    if (!root) {
        // null child
        *internal += 0;
        *leaf += 0;
    } else if (!root->left && !root->right) {
        // leaf node
        *leaf += 1;
    } else {
        // internal node
        *internal += 1;
        btCountNodes(root->left, internal, leaf);
        btCountNodes(root->right, internal, leaf);
    }
}

int btHeight(btNode *root) {
    if (!root || (!root->left && !root->right))
        return 0;
    int h1 = btHeight(root->left);
    int h2 = btHeight(root->right);
    return (h1 > h2) ? h1 + 1 : h2 + 1;
}

char areEquivalentBT(btNode *t1, btNode *t2) {
    if (!t1 && !t2)
        return 1;
    else if (!t1 || !t2)
        return 0;
    else
        return (t1->value == t2->value) &&
               areEquivalentBT(t1->left, t2->left) &&
               areEquivalentBT(t1->right, t2->right);
}

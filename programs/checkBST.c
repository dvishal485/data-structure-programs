/*
Check if given binary tree is binary search tree or not
*/

#include "bt_impl.c"

int min;
char init = 0;
char isBST(btNode *root) {
    if (!root) {
        return 1;
    } else {
        char x = isBST(root->left);
        if (init && min >= root->value)
            return 0;
        init = 1;
        min = root->value;
        char y = isBST(root->right);
        return x && y;
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
    printf("The given Binary Tres is %sa Binary Search Tree\n",
           isBST(root) ? "" : "not ");
    return 0;
}

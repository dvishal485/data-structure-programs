#include "./bt_impl.c"

char _isBST(btNode *root, int *min, char *init) {
    if (!root) {
        return 1;
    } else {
        char x = _isBST(root->left, min, init);
        if (x == 0 || (*init && *min >= root->value))
            return 0;
        *init = 1;
        *min = root->value;
        char y = _isBST(root->right, min, init);
        return x && y;
    }
}

char isBST(btNode *root) {
    int *min = (int *)malloc(sizeof(int));
    char *init = (char *)malloc(sizeof(char));
    return _isBST(root, min, init);
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
    printf("The given Binary Tree is %sa Binary Search Tree\n",
           isBST(root) ? "" : "not ");
    return 0;
}

#define NEWLINE printf("\n")
#include <stdio.h>
#include <stdlib.h>

typedef struct avlNode {
    int value;
    struct avlNode *left;
    struct avlNode *right;
    int height;
} avlNode;

int max(int a, int b) { return a > b ? a : b; }

int height(avlNode *root) {
    if (!root)
        return 0;
    return root->height;
}

avlNode *createAvlNode(int value) {
    avlNode *x = (avlNode *)malloc(sizeof(avlNode));
    x->value = value;
    x->left = NULL;
    x->right = NULL;
    x->height = 1;
    return x;
}

avlNode *rightRotate(avlNode *root) {
    avlNode *x = root->left;
    avlNode *y = x->right;
    x->right = root;
    root->left = y;
    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

avlNode *leftRotate(avlNode *root) {
    avlNode *x = root->right;
    avlNode *y = x->left;
    x->left = root;
    root->right = y;
    root->height = max(height(root->left), height(root->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

int balanceFactor(avlNode *root) {
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

avlNode *insert(avlNode *root, int value) {
    if (!root)
        return createAvlNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    else
        return root; // Let Duplicate values be not allowed in AVL tree
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = balanceFactor(root);
    if (balance > 1 && value < root->left->value)
        return rightRotate(root);
    if (balance < -1 && value > root->right->value)
        return leftRotate(root);
    if (balance > 1 && value > root->left->value) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && value < root->right->value) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// delete a key from avl tree

avlNode *minValueNode(avlNode *root) {
    avlNode *current = root;
    while (current->left)
        current = current->left;
    return current;
}

avlNode *delete (avlNode *root, int value) {
    if (!root)
        return root;
    if (value < root->value)
        root->left = delete (root->left, value);
    else if (value > root->value)
        root->right = delete (root->right, value);
    else {
        if (!root->left || !root->right) {
            avlNode *temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            avlNode *temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = delete (root->right, temp->value);
        }
    }
    if (!root)
        return root;
    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = balanceFactor(root);
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void printInorder(avlNode *root) {
    if (!root)
        return;
    printInorder(root->left);
    printf("%d ", root->value);
    printInorder(root->right);
}

// count number of leaf nodes in avl tree

int countLeafNodes(avlNode *root) {
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main(void) {
    avlNode *root = NULL;
    printf("Input number of elements to be inserted in AVL tree: ");
    int n;
    scanf("%d", &n);
    printf("Input elements to be inserted in AVL tree: ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    NEWLINE;
    printf("Inorder traversal of the constructed AVL tree is :\n");
    printInorder(root);
    NEWLINE;
    printf("\nNumber of leaf nodes in AVL tree : %d\n", countLeafNodes(root));
    printf("\nInput number of elements to be deleted from AVL tree : ");
    scanf("%d", &n);
    printf("\nInput elements to be deleted from AVL tree : ");
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = delete (root, x);
    }
    printf("\nInorder traversal of the AVL tree after deletion :\n");
    printInorder(root);
    NEWLINE;
    printf("\nNumber of leaf nodes in AVL tree : %d\n", countLeafNodes(root));
    return 0;
}

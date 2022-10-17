/*
Given two integer arrays preorder and inorder where preorder is the preorder
traversal of a binary tree and inorder is the inorder traversal of the same
tree, construct and return the binary tree.
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/

#include "../bt_impl.c"

int _buildTreeSize, _buildTreeIndex;

btNode *_buildTreeHelper(int *preorder, int *inorder, int start, int stop,
                         int *index) {
    if (!(*index < _buildTreeSize))
        return NULL;
    btNode *tree = createBtNode(preorder[*index]);
    int i;
    for (i = start; preorder[*index] != inorder[i]; i++) {
    };

    if (i > start) {
        (*index)++;
        tree->left = _buildTreeHelper(preorder, inorder, start, i - 1, index);
    }
    if (i < stop) {
        (*index)++;
        tree->right = _buildTreeHelper(preorder, inorder, i + 1, stop, index);
    }
    return tree;
}

btNode *buildTree(int preorder[], int inorder[], int size) {
    _buildTreeIndex = 0;
    _buildTreeSize = size;
    return _buildTreeHelper(preorder, inorder, 0, size, &_buildTreeIndex);
}

int main() {
    int preorder[] = {7, -10, -4, 3, -1, 2, -8, 11};
    int inorder[] = {-4, -10, 3, -1, 7, 11, -8, 2};

    btNode *root = buildTree(preorder, inorder, sizeof(preorder) / sizeof(int));

    printf("Inorder Traversal of generated tree :\n");
    inOrderTraversal(root);
    printf("\nPreorder Traversal of generated tree :\n");
    preOrderTraversal(root);
    printf("\n");
    return 0;
}

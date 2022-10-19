#include "../bt_impl.c"

int _buildTreeSize, _buildTreeIndex;

btNode *_buildTreeHelper(int *preorder, int *inorder, int start, int stop) {
    if (!(_buildTreeIndex < _buildTreeSize))
        return NULL;
    btNode *tree = createBtNode(preorder[_buildTreeIndex]);
    int i;
    for (i = start; preorder[_buildTreeIndex] != inorder[i]; i++) {
    };

    if (i > start) {
        _buildTreeIndex++;
        tree->left = _buildTreeHelper(preorder, inorder, start, i - 1);
    }
    if (i < stop) {
        _buildTreeIndex++;
        tree->right = _buildTreeHelper(preorder, inorder, i + 1, stop);
    }
    return tree;
}

btNode *buildTree(int preorder[], int inorder[], int size) {
    _buildTreeIndex = 0;
    _buildTreeSize = size;
    return _buildTreeHelper(preorder, inorder, 0, size);
}

btNode *mirrorBT(btNode *root) {
    if (!root)
        return root;
    btNode *temp = root->left;
    root->left = mirrorBT(root->right);
    root->right = mirrorBT(temp);
    return root;
}

int main() {
    int inorder[] = {3, 1, 5, 4, 2, 7};
    int preorder[] = {5, 1, 3, 2, 4, 7};

    btNode *root = buildTree(preorder, inorder, sizeof(preorder) / sizeof(int));
    btNode *new_root = mirrorBT(root);

    printf("Inorder Traversal of generated tree :\n");
    inOrderTraversal(new_root);
    printf("\nPreorder Traversal of generated tree :\n");
    preOrderTraversal(new_root);
    printf("\n");
    return 0;
}
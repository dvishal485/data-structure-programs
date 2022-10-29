/*
Q. Write a program to construct binary search tree on given pre-order traversal
of the tree. After constructing the binary search tree, print the bstNodes level
wise top to down and left to right.
*/
#include <iostream>
#include <queue>
using namespace std;

class bstNode {
  public:
    int data;
    bstNode *left;
    bstNode *right;
    bstNode(int data) : data(data), left(nullptr), right(nullptr){};
    bstNode(int data, bstNode *left) : data(data), left(left), right(nullptr){};
    bstNode(int data, bstNode *left, bstNode *right)
        : data(data), left(left), right(right) {}
};

bstNode *bstInsert(bstNode **pointer_to_root, int data) {
    bstNode *root = (*pointer_to_root);
    if (!root) {
        *pointer_to_root = new bstNode(data);
        return *pointer_to_root;
    }
    while (true) {
        if (!root)
            return nullptr;
        if (data < root->data) {
            if (!root->left) {
                root->left = new bstNode(data);
                return root->left;
            }
            root = root->left;
        } else {
            if (!root->right) {
                root->right = new bstNode(data);
                return root->right;
            }
            root = root->right;
        }
    }
}

void levelOrderTraversal(bstNode *root) {
    if (!root)
        return;
    queue<bstNode *> q;
    q.push(root);
    while (!q.empty()) {
        bstNode *temp = q.front();
        cout << temp->data << ", ";
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        q.pop();
    }
}

bstNode *buildTree(int preorder[], int size) {
    /*
    we can build a binary search tree simply by inserting
    the elements at the correct position in the order they
    appear in preorder traversal
    */
    bstNode *root = NULL;
    for (int i = 0; i < size; i++)
        bstInsert(&root, preorder[i]);
    return root;
}

int main() {
    int preorder[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(preorder) / sizeof(preorder[0]);
    bstNode *root = buildTree(preorder, size);

    cout << "Level order traversal of the constructed tree is :\n";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}

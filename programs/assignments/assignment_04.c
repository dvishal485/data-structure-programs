/*
Q. Write a program to check if one tree appears in another tree. Two trees match
each other if either
1. Both trees are empty, or
2. both trees are non-empty and
1. both root nodes have the same value,
2. each root has the same number of children, and
3. the corresponding children in each root node match.

The program accepts a source binary tree and a pattern binary tree, and returns
the root of an occurrence of the pattern in the source, if it exists. The
pattern tree may occur anywhere in the source tree.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef char bool;
bool false = 0, true = 1;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool _treeMatchesHelper(Node *source, Node *pattern) {
    if (!source && !pattern)
        return true;
    if (!source || !pattern)
        return false;
    if (source->data == pattern->data)
        return _treeMatchesHelper(source->left, pattern->left) &&
               _treeMatchesHelper(source->right, pattern->right);
    return false;
}

Node *treeMatches(Node *source, Node *pattern) {
    if (!pattern) {
        printf("ERROR : Invalid pattern!");
        exit(EXIT_FAILURE);
    }
    if (!source)
        return NULL;

    if (pattern->data == source->data && _treeMatchesHelper(source, pattern))
        return source;

    Node *temp = treeMatches(source->left, pattern);
    if (temp)
        return temp;

    return treeMatches(source->right, pattern);
}

int main() {
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    // root->left->right->left = createNode(1);
    Node *pattern = createNode(2);
    pattern->left = createNode(4);
    pattern->right = createNode(5);

    Node *result = treeMatches(root, pattern);

    if (result)
        printf("Pattern found at node %d\n", result->data);
    else
        printf("Pattern not found!\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Depth First Search for binary tree
void DFS(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data); // Visit the current node
    DFS(root->left); // Recursively traverse left subtree
    DFS(root->right); // Recursively traverse right subtree
}

int main() {
    // Constructing a sample binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // Perform Depth First Search on the binary tree
    printf("Depth First Search traversal of the binary tree:\n");
    DFS(root);

    return 0;
}

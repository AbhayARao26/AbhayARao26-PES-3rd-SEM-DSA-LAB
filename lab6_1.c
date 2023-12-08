/*
 Counting Leaves in a Binary Tree 1
 
 You are given a binary tree represented by its level order traversal with the special value -1 indicating the absence of a node. Your task is to write a C program to count the number of leaf nodes in the binary tree using a recursive approach.

 A binary tree is a tree data structure in which each node has at most two children, referred to as the left child and the right child. A leaf node is a node that does not have any children.

 Input Format:
    The input consists of two parts: The size of the level order traversal (an integer). The level order traversal of the binary tree as a sequence of integers separated by spaces. The sequence will contain the special value -1 where a node is absent.

 Constraints:
    NONE

 Output Format:
    Output the number of leaf nodes in the binary tree.

 Sample Input:
    7
    1 2 3 4 5 -1 -1
 
 Sample Output:
    3
*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to count leaf nodes in a binary tree
int countLeafNodes(struct Node* root) {
    // Base case: If the tree is empty, return 0
    if (root == NULL) {
        return 0;
    }
    // If the node is a leaf node, return 1
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    // Recursively count leaf nodes in the left and right subtrees
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to build a binary tree from its level order traversal
struct Node* buildTree(int arr[], int size) {
    struct Node** nodes = (struct Node**)malloc(size * sizeof(struct Node*));
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            nodes[i] = createNode(arr[i]);
        } else {
            nodes[i] = NULL;
        }
    }

    int rootIndex = 0;
    for (int i = 0; i < size; i++) {
        if (nodes[i] != NULL) {
            if (2 * i + 1 < size) {
                nodes[i]->left = nodes[2 * i + 1];
            }
            if (2 * i + 2 < size) {
                nodes[i]->right = nodes[2 * i + 2];
            }
        }
    }

    struct Node* root = nodes[rootIndex];
    free(nodes);
    return root;
}

int main() {
    int size;
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, size);
    int leafCount = countLeafNodes(root);

    printf("%d", leafCount);

    return 0;
}

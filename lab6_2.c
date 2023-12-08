/*
 Binary Search Tree (BST)
 
 You are given a sequence of numbers representing a BST in level order traversal with -1 indicating the absence of a node. You need to construct the BST from this input. Once the BST is constructed, you will receive a series of queries, each of which is either a search operation or a delete operation. You need to perform the corresponding operation and return the result.

 Input Format:
    The first line contains an integer, n, representing the number of elements in the level order traversal (1 ≤ n ≤ 1000).
    The second line contains n space-separated integers, representing the level order traversal of the BST. The values are in the range [-10^9, 10^9], and -1 indicates an empty node.
    The third line contains an integer, q (1 ≤ q ≤ 1000), representing the number of queries to be performed.
    The next q lines contain queries in the following format:

     ‘0 x’: A search operation. You need to determine if the value ‘x’ is present in the BST and print "YES" if it is, "NO" otherwise.
     ‘1 x’: A delete operation. You need to delete the node with the value ‘x’ from the BST.

 Constraints:
    None

 Output Format:
    For each search query, print "YES" if the element is found in the BST, "NO" if it's not.

 Sample Input:
     10
     4 2 6 1 3 5 7 -1 -1 -1
     5
     0 3
     0 8
     1 4
     0 4
     0 2
 
 Sample Output:
     YES
     NO
     NO
     YES
*/

#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node with the given value.
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST.
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->val) {
        root->left = insert(root->left, value);
    } else if (value > root->val) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search for a value in the BST.
int search(struct TreeNode* root, int value) {
    if (root == NULL) {
        return 0; // Not found
    }

    if (root->val == value) {
        return 1; // Found
    } else if (value < root->val) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Function to find the minimum value node in a BST.
struct TreeNode* findMin(struct TreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a value from the BST.
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->val) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->val) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

// Function to perform search or delete operations based on queries.
void processQueries(struct TreeNode* root, int queries[][2], int q) {
    for (int i = 0; i < q; i++) {
        int operation, value;
        operation = queries[i][0];
        value = queries[i][1];

        if (operation == 0) {
            // Search operation
            if (search(root, value)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else if (operation == 1) {
            // Delete operation
            root = deleteNode(root, value);
        }
    }
}

int main() {
    int n, q;
    scanf("%d", &n);

    struct TreeNode* root = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        if (value != -1) {
            root = insert(root, value);
        }
    }

    scanf("%d", &q);
    int queries[q][2];

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &queries[i][0], &queries[i][1]);
    }

    processQueries(root, queries, q);

    return 0;
}

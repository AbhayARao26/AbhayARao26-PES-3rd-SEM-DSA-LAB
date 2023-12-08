/*
    The CIA challenge

    In a world shrouded in secrecy and intrigue, I found myself playing the role of a seasoned CIA agent. 
    My mission was unlike any other, for it required me to unravel a web of connections and motives that had remained 
    hidden for far too long. Two notorious thieves were at the heart of this enigma, and my task was to find their 
    lowest common ancestor, a shadowy figure who held the key to understanding their dark and clandestine alliance. 
    To crack this puzzle, I was presented with a peculiar map – a binary tree, a symbol of the complex network that 
    underpinned the thieves' collaboration. However, this wasn't your typical tree; it was a tree of secrets, with 
    each node representing a key player in the criminal underworld. The tree's layout was given to me in an 
    unconventional format, a level order traversal, where -1 marked the absence of a node, and every other number 
    revealed a piece of the puzzle. As I delved into the depths of this tree, I felt like an investigator on a 
    mission to uncover the truth. Each number I encountered was a potential lead, an individual with their own 
    role in this intricate drama. But my ultimate goal was to find the elusive lowest common ancestor – the one 
    node that had a direct connection to both thieves, the linchpin in their dark alliance. This lowest common 
    ancestor wasn't just any node; it was the pivotal character in this narrative, the one who could shed light 
    on the motives behind their criminal activities. To identify this figure, I had to navigate the tree with 
    precision, tracing the paths that led to each thief and meticulously searching for the point where their 
    journeys converged. The binary tree was a labyrinth of secrets, but I was determined to uncover the truth. 
    With every step, I inched closer to the answer, analyzing the connections between nodes, following the paths 
    that linked them, and finally, I found it – the lowest common ancestor, the key to understanding the thieves' 
    connection and motive. As I stood there, staring at the node that held the secrets of this dark alliance,
    I knew that I had unraveled a crucial piece of the puzzle. The lowest common ancestor was the link that 
    connected the two thieves, and it was up to me to decipher the information hidden within this shadowy figure, 
    revealing the truth behind their criminal endeavors and bringing them to justice.

    Input Format:
        First line contains ‘n’ number of nodes in the tree, Second line has level order traversal of the tree, 
        with -1 as null nodes The third line has 2 numbers , who are the thieves

    Constraints:
        1

    Output Format:
        output the answer

    Sample Input:
        7
        3 5 1 6 2 0 8
        5 1
    
    Sample Output:
        3
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node* left;
    struct node* right;
} NODE;

// Function to create a new node with the given data
NODE* createNode(int ele) {
    NODE* newNode = (NODE*) malloc (sizeof(NODE));
    newNode->info = ele;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree from level order traversal
NODE* buildTree(int arr[], int n) {
    if (n <= 0)
        return NULL;

    // Create the root of the tree
    NODE* root = createNode(arr[0]);

    // Create a queue to keep track of the parent nodes
    NODE* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        NODE* parent = queue[front++];
        
        int leftValue = arr[i++];
        if (leftValue != -1) {
            parent->left = createNode(leftValue);
            queue[rear++] = parent->left;
        }

        if (i < n) {
            int rightValue = arr[i++];
            if (rightValue != -1) {
                parent->right = createNode(rightValue);
                queue[rear++] = parent->right;
            }
        }
    }
    return root;
}

// Function to find the lowest common ancestor of two nodes in a binary tree
NODE* findLowestCommonAncestor(NODE* root, int thief1, int thief2) {
    if (root == NULL)
        return NULL;

    // If either of the thieves is the root, the root is the LCA
    if (root->info == thief1 || root->info == thief2)
        return root;

    // Recursively find LCA in the left and right subtrees
    NODE* leftLCA = findLowestCommonAncestor(root->left, thief1, thief2);
    NODE* rightLCA = findLowestCommonAncestor(root->right, thief1, thief2);

    // If both left and right subtrees have an LCA, the current node is the LCA
    if (leftLCA != NULL && rightLCA != NULL)
        return root;

    // If one subtree has an LCA, return that LCA; otherwise, return NULL
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() 
{
    int n;
    scanf("%d", &n);
    int levelOrder[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &levelOrder[i]);
    }

    int thief1, thief2;
    scanf("%d %d", &thief1, &thief2);

    NODE* root = buildTree(levelOrder, n);
    NODE* lca = findLowestCommonAncestor(root, thief1, thief2);

    printf("%d\n", lca->info);

    return 0;
}
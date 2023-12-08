/*
    The Quest for the Tree of Life

    Once upon a time in a lush and vibrant forest, there stood a magnificent tree. This tree was not like any 
    ordinary tree; it was a binary tree, known for its intricate structure and beauty. Each node of the tree was 
    a living entity, holding a unique value greater than zero, symbolizing its own distinct character.
    The tree's level order traversal was like a map of the forest, but it was presented in a rather unusual way. 
    Instead of telling you which nodes connected to which, it provided a list of values, where -1 indicated the 
    absence of a node, and the positive values were the essence of each node's existence.The forest inhabitants 
    were curious about the tree and wondered about its secrets. One day, they set themselves a challenge: to find 
    the length of the tree's "diameter." The diameter of this binary tree was no ordinary measure. It was defined 
    as the length of the longest path between any two nodes in the tree, measured not in units of distance but in 
    the number of nodes traversed.To solve this intriguing problem, the forest dwellers needed to traverse the 
    tree, carefully counting the edges between nodes and seeking the longest possible path. They realized that this 
    path might or might not pass through the root of the tree, adding an extra layer of complexity to their quest.
    As they embarked on their journey through the tree's level order traversal, they felt like explorers on a 
    grand adventure. Each -1 they encountered marked a momentary pause, where they had to acknowledge the absence 
    of a node. But the positive values guided them further, hinting at the existence of vibrant nodes waiting to 
    be discovered.Their goal was clear: find the length of the tree's diameter, the longest path between any 
    two nodes, whether it involved the root or not. With determination and a touch of wonder, they ventured deep 
    into the heart of the binary tree, seeking to unlock the secrets of its diameter and gain a deeper 
    understanding of the intricate web of life it represented.

    Input Format:
        level order traversal of the tree , with -1 where node is null

    Constraints:
        1

    Output Format:
        print the answer to the problem

    Sample Input:
        7
        1 2 3 4 5 -1 -1
    
    Sample Output:
    4
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}NODE;

NODE* createNode(int ele)
{
    NODE* newNode = malloc(sizeof(NODE));
    newNode->data = ele;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

NODE* insertNode(int* arr,int na,int ind)
{
    if(na>0){
        if(arr[ind]==-1)
        {
            return NULL;
        }
        NODE* head = createNode(arr[ind]);
        head->left = insertNode(arr,na-(ind+1),2*ind+1);
        head->right = insertNode(arr,na-(ind+2),2*ind+2);
        return head;
    }
    else 
        return NULL;
}

int height(NODE* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(lh>rh)
        return 1 + lh;
    else
        return 1 + rh;
}

int diameter(NODE* root) 
{
    if (root == NULL) 
    {
        return 0;
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    int dia = lh + rh + 1;
    int ldia = diameter(root->left);
    int rdia = diameter(root->right);
    
    if(dia>ldia && dia>rdia)
    {
        return dia;
    }
    else
    {
        if(ldia>rdia)
            return ldia;
        else
            return rdia;
    }
}

int main()
{
    NODE* root = NULL;
    int a;
    scanf("%d",&a);
    int arr[a];
    
    for(int i=0;i<a;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    root = insertNode(arr,a,0);
    int dia = diameter(root);
    printf("%d",dia);
    
    return 0;
}
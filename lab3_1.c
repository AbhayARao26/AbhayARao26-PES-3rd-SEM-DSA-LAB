/*
 Josephus Problem using Circular Linked List
 
 The Josephus Problem is a theoretical problem related to a circle of people, where you need to devise a strategy to eliminate individuals in a specific order until only one person survives. Given a group of n people standing in a circle and an integer k, the problem requires eliminating every k-th person, looping back to the beginning if necessary, until only one person remains. Your task is to solve the Josephus Problem using a circular linked list and provide the implementation in C.

 You are required to implement a circular linked list to simulate the circle of people. Each node in the linked list should represent a person and contain relevant information such as their index and a pointer to the next person. The elimination process should follow the specified counting interval, and eliminated persons should be removed from the circle.

 Your solution should include the following components:

 Define a structure for the linked list node.
 Implement functions to create and populate the circular linked list.
 Implement a function to simulate the elimination process based on the Josephus Problem.
 Print the order of elimination and the index of the last person remaining.
 Input Format

 • An integer n representing the number of people in the circle.
 • An integer k representing the counting interval for elimination.
 Constraints

 None

 Output Format

 The index of the last person remaining.
 Sample Input 0

 5 2
 Sample Output 0

 3
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node* link;
} NODE;

NODE* createNode(NODE* head, int ele);
NODE* JOSEPHUS(NODE* head, int n, int k);
NODE* deleteNode(NODE* head,int num);

int main()
{
    int n, k;
    NODE* head = NULL;
    scanf("%d %d", &n, &k);
    
    for(int i=1; i<=n; i++)
    {
        head = createNode(head, i);
    }
    
    head = JOSEPHUS(head, n, k);
    
    return 0;
}

NODE* createNode(NODE* head, int ele)
{
    NODE* newNode = (NODE*) malloc (sizeof(NODE));
    newNode->info = ele;
    newNode->link = newNode;
    
    NODE* temp = head;
    
    if(head==NULL)
    {
        return newNode;
    }
    else
    {
        while(temp->link != head)
        {
            temp = temp->link;
        }
        
        temp->link = newNode;
        newNode->link = head;
    }
    return head;
}

NODE* JOSEPHUS(NODE* head, int n, int k)
{
    for(int i=1; i<n; i++)
    {
        head = deleteNode(head, k);
    }
    printf("%d ",head->info);
    return head;
}

NODE* deleteNode(NODE* head,int num)
{
    NODE* temp = head;
    NODE* previous = NULL;
    
    for(int i=1; i < num; i++)
    {
        previous = temp;
        temp = temp->link;
    }
    
    previous->link = temp->link;
    head = previous->link;
    free(temp);

    return head;
}

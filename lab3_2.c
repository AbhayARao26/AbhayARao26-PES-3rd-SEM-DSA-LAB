/*
 Palindrome Check for Doubly Linked List
 
 You are given a doubly linked list, where each node contains an charecter value. Your task is to implement a function isPalindrome that checks whether the given doubly linked list is a palindrome or not. A palindrome is a sequence that reads the same forwards and backwards.

 Input Format

 First line is the number n,
 Next n are the characters in the doubly linked list
 Constraints

 None

 Output Format

 Print 1, if DLL is a Palindrome, 0 other wise
 Sample Input 0

 5
 a b c c b
 Sample Output 0

 0
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    char info;
    struct Node* rlink;
    struct Node* llink;
}NODE;

NODE* createNode(char ele)
{
    NODE* newNode = (NODE*) malloc (sizeof(NODE));
    newNode->info = ele;
    newNode->llink = NULL;
    newNode->rlink = NULL;
    return newNode;
}

NODE* insertList(char arr[], int num)
{
    NODE* head = createNode(arr[0]);
    head->llink = NULL;
    head->rlink = NULL;
    NODE* temp = head;
    for(int i=1; i<num; i++)
    {
        temp->rlink = createNode(arr[i]);
        temp->rlink->llink = temp;
        temp = temp->rlink;
    }
    return head;
}

int checkIfPalindrome(NODE* head, int no)
{
    NODE* temp = head;
    int pal = 1;
    while(temp->rlink)
    {
        temp = temp->rlink;
    }
    for(int i=0; i < no/2; i++)
    {
        if((head->info) != (temp->info))
        {
            return 0;
        }
        else
        {
            head = head->rlink;
            temp = temp->llink;
        }
    }
    return pal;
}

int main()
{
    int n, i=0;
    char x;
    scanf("%d", &n);
    char arry[n];
    getchar();
    while(i<n)
    {
        x=getchar();
        if(x !=' ')
        {
            arry[i] = x;
            i++;
        }
        else
        {
            continue;
        }
    }
    NODE* head=insertList(arry,n);
    int answer;
    answer = checkIfPalindrome(head, n);
    printf("%d", answer);
    return 0;
}

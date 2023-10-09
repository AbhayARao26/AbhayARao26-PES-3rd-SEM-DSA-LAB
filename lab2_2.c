/*
Divide Linked List 2

You are given a singly linked list. Write a C program to find the midpoint of the linked list and then split the list into two separate lists at that midpoint. Finally, print the elements of both lists, one line after the other.

You need to implement the following tasks:
Find the midpoint of the linked list. (hint: use fast pointers)
Split the linked list into two parts at the midpoint.
Print the elements of both lists.
Input Format

First line has one number ‘n’ which is the number of nodes in the linked list
The next line has the node values(space separated)
Constraints

None

Output Format

First line has the first half of the linked list,
Second line has second half of the linked list
Sample Input 0

5
1 2 3 4 5
Sample Output 0

1 2 3
4 5
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}NODE;

NODE* create(int ele)
{
    NODE* head=malloc(sizeof(struct node));
    head->data=ele;
    head->next=NULL;
    return head;
}

NODE* insertend(NODE* head, int ele)
{
    NODE* node = create(ele);
    if (head == NULL)
        head = node;
    else
    {
        NODE* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
    return head;
}

int pointer(NODE* head)
{
    int ptr=0;
    while((head->next!=NULL)&&(head->next->next!=NULL))
    {
        ptr++;
        head=head->next->next;
    }
    return ptr;
}

int main()
{
    NODE* head=NULL;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int ele;
        scanf("%d",&ele);
        head=insertend(head,ele);
    }
    int num = pointer(head);
    int counter=0;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        if(counter==num)
            printf("\n");
        counter++;
        head=head->next;
    }
    return 0;
}

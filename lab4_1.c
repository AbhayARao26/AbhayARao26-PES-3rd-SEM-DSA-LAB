/*
 STACKS USING QUEUE
 
 Write a Program in C to implement Stack functionality using Queues.
 You will be given the no of operations the user will perform and the operations itself.
 Operation 1 is the push operation and Operation 2 is the pop operation. Perform all the operations on the stack and while popping print the popped value. Refer to Sample Test case for better understanding
 Input Format
    Line1: No of operations Push/Pop Value(Ignore value for pop operations)

 Constraints: None

 Output Format:
    Popped values without any separation

 Sample Input:

 4
 1 2
 1 3
 2 5
 2 3
 
 Sample Output:

 32
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct QueueNode
{
    int data;
    struct QueueNode* link;
}QN;


void QueuePush(QN **head, int info)
{

    QN* newNode = (QN*) malloc (sizeof(QN));
    
    newNode->data = info;
    newNode->link = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        newNode->data = info;
    }
    
    else
    {
        newNode->link = *head;
        newNode->data = info;
        *head = newNode;
    }
}


void QueuePop(QN **head, int *info)
{
    if(*head == NULL)
    {
        printf("Empty");
    }
    
    QN* curr = *head;
    QN* prev = NULL;
    while(curr->link != NULL)
    {
        prev = curr;
        curr = curr->link;
    }

    *info = curr->data;
    if(prev != NULL)
    {
        prev->link = NULL;
    }
    
    else
    {
        *head = NULL;
    }

    free(curr);
    curr = NULL;
}


int main()
{
    QN* q1=NULL;
    QN* q2=NULL;
    int n;
    scanf("%d", &n);
    int oprtn;
    int val;
    
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &oprtn, &val);
        
        switch (oprtn)
        {
            case 1:
                QueuePush(&q1, val);
                break;

            case 2:
                if(q1 != NULL)
                {
                    while (q1->link != NULL)
                    {
                        int info;
                        QueuePop(&q1, &info);
                        QueuePush(&q2, info);
                    }
                    
                    int info;
                    QueuePop(&q1, &info);
                    printf("%d", info);

                    
                    QN* temp = q1;
                    q1 = q2;
                    q2 = temp;
                }
                
                break;
        }
    }
    return 0;
}

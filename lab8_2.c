/*
QUADRATIC PROBING

Complete the codes given in the main.c file, create a custom hash function of choice, 
use quadratic probing to resolve ties solve q queries

Input Format:
    first line has integer q , the next q lines are of the format 1 x or 2 y or 3 z if 1, then 
    insert x into the hash if 2 , search for y, print true if found , else false if 3, delete z from the hash

Constraints: None

Output Format: According to input

Sample Input:
    6
    1 2
    1 3
    2 3
    1 7
    3 3
    2 3

Sample Output:
    true
    false
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the hash table. You can change this to a suitable value.
#define HASH_TABLE_SIZE 100

// Define the structure for a node in the linked list used for separate chaining.
typedef struct node 
{
    int value;
    struct node* next;
} NODE;

// Function to create a new node with the given value.
NODE* createNode(int data) 
{
    NODE* newNode = (NODE*) malloc (sizeof(NODE));
    newNode->value = data;
    newNode->next = NULL;
    return newNode;
}

// Custom hash function that can be changed according to the problem.
int customHash(int val) 
{
    return val % HASH_TABLE_SIZE;
}

// Function to insert a value into the hash table.
void insertValue(int hashTable[], int ele) 
{
    int index = customHash(ele);
    int i = 0;
    while (hashTable[(index + i * i) % HASH_TABLE_SIZE] != -1) 
    {
        i++;
    }
    hashTable[(index + i * i) % HASH_TABLE_SIZE] = ele;
}

// Function to search for a value in the hash table.
bool searchValue(int hashTable[], int ele) 
{
    int index = customHash(ele);
    int i = 0;
    while (hashTable[(index + i * i) % HASH_TABLE_SIZE] != ele) 
    {
        if (hashTable[(index + i * i) % HASH_TABLE_SIZE] == -1) 
        {
            return false;
        }
        i++;
    }
    return true;
}

// Function to delete a value from the hash table.
void deleteValue(int hashTable[], int ele) 
{
    int index = customHash(ele);
    int i = 0;
    while (hashTable[(index + i * i) % HASH_TABLE_SIZE] != ele) 
    {
        if (hashTable[(index + i * i) % HASH_TABLE_SIZE] == -1) 
        {
            return;
        }
        i++;
    }
    hashTable[(index + i * i) % HASH_TABLE_SIZE] = -1;
}

int main() 
{
    int q;
    scanf("%d", &q);

    // Initialize the hash table with -1 to indicate empty index.
    int hashTable[HASH_TABLE_SIZE];
    for (int i = 0; i < HASH_TABLE_SIZE; i++) 
    {
        hashTable[i] = -1;
    }

    while (q--) 
    {
        int type, ele;
        scanf("%d %d", &type, &ele);

        if (type == 1) 
        {
            insertValue(hashTable, ele);
        } 
        else if (type == 2) 
        {
            if (searchValue(hashTable, ele)) 
            {
                printf("true\n");
            } 
            else 
            {
                printf("false\n");
            }
        } 
        else if (type == 3) 
        {
            deleteValue(hashTable, ele);
        }
    }

    return 0;
}

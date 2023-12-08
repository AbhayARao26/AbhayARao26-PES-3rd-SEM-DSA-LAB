/*
SEPARATE CHAINING

Complete the code, create a custom hash function of choice, use separate chaining to resolve ties solve q queries

Input Format:
    first line has integer q , the next q lines are of the format 1 x or 2 y or 3 z if 1, then insert x into the hash 
    if 2 , search for y, print true if found , else false if 3, delete z from the hash

Constraints: None

Output Format:
    according to input

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

    // Create a new node with the value.
    NODE* newNode = createNode(ele);

    // Check if the index is empty.
    if (hashTable[index] == NULL) 
    {
        hashTable[index] = newNode;
    } 
    else 
    {
        // Handle collision by adding to the end of the linked list.
        NODE* current = hashTable[index];
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to search for a value in the hash table.
bool searchValue(int hashTable[], int ele) 
{
    int index = customHash(ele);

    NODE* current = hashTable[index];
    while (current != NULL) 
    {
        if (current->value == ele) 
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

// Function to delete a value from the hash table.
void deleteValue(int hashTable[], int ele) 
{
    int index = customHash(ele);

    NODE* current = hashTable[index];
    NODE* prev = NULL;

    while (current != NULL) 
    {
        if (current->value == ele) 
        {
            if (prev == NULL) 
            {
                // The value is in the first node of the list.
                hashTable[index] = current->next;
            } 
            else 
            {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() 
{
    int q, operation, value;
    scanf("%d", &q);

    // Initialize the hash table with NULL.
    int hashTable[HASH_TABLE_SIZE] = {0};

    while (q--) 
    {
        scanf("%d %d", &operation, &value);

        if (operation == 1) 
        {
            // Insert
            insertValue(hashTable, value);
        } 
        else if (operation == 2) 
        {
            // Search
            if (searchValue(hashTable, value)) 
            {
                printf("true\n");
            } 
            else {
                printf("false\n");
            }
        } 
        else if (operation == 3) 
        {
            // Delete
            deleteValue(hashTable, value);
        }
    }
    return 0;
}
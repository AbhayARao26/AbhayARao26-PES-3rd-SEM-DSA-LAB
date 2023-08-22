/*
 
 Create a C program that uses dynamic memory allocation to make an array on integers. Your program should take in the number of elements from user, allocate memory using malloc or calloc, and find the or of all the elements in the array , display the result of all or operation as output

 Input Format

 C program using dynamic memory allocation to create an integer array, then finding the bitwise OR of its elements and displaying the result.

 Constraints

 -1000<=n<=1000

 Output Format

 Output one integer which is the or of all the elements in the array

 Sample Input 0

 5
 1 2 3 2 1
 Sample Output 0

 3
 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int num;
    scanf("%d" , &num);
    int* ptr = (int*) calloc (num,sizeof(int));
    for(int i=0; i<num; i++)
    {
        scanf("%d",&ptr[i]);
    }
    int result = ptr[0];
    for(int i=1; i<num; i++)
    {
        result = result|ptr[i];
    }
    printf("%d\n",result);
    return 0;
}

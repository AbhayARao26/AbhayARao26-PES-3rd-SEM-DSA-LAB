/*
 
 Write a function that takes an array of integers and its size as arguments. The function should use pointers to find the maximum element in the array and update its value. Here is the function signature int findMax(int* arr, int size) { // todo }

 Input Format

 Size Array elements

 Constraints

 -1000<=n<=1000

 Output Format

 Maximum value

 Sample Input 0

 3
 1 2 3
 Sample Output 0

 3
 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findMax(int* arr, int size);

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sizeOfArray;
    scanf("%d", &sizeOfArray);
    
    int arr[sizeOfArray];
    for(int i=0; i<sizeOfArray; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int max = findMax(arr,sizeOfArray);
    printf("%d", max);
    
    return 0;
}

int findMax(int arr[], int sizeOfArray)
{
    if (sizeOfArray <= 0)
    {
        return -1;
    }

    int max = arr[0];

    for (int i=1; i<sizeOfArray; i++)
    {
        if (*(arr+i) > max)
        {
            max = *(arr+i);
        }
    }
    
    return max;
}

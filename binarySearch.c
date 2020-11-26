/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int arr[], int target, int startIndex, int endIndex);

int main()
{
    int arr[6] = {4, 8, 15, 16, 23, 42};
	int target = binarySearch(arr, 16, 0, 5);
    printf(" target = %d", target);
    return 0;
}


int binarySearch(int arr[], int target, int startIndex, int endIndex)
{
    if (endIndex >= startIndex)
    {
       int midPoint = startIndex + (endIndex - startIndex)/2;
       
       if (target == arr[midPoint])
       {
           return arr[midPoint];
       }
       
       if (target > arr[midPoint])
       {
           return binarySearch(arr, target, midPoint + 1, endIndex);
       }
           
           return binarySearch(arr, target, startIndex, midPoint - 1);
    }
	
    return -1;
}

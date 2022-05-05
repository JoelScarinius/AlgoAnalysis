#include "input_gen.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

// static void swap(int a[], int i, int  i2);

void orderedArray(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
}

void revOrderedArray(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
}

void randomOrderedInput(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        int change = rand() % n + 1;
        a[i] = i + change;
    }
}

void random4OrderedInput(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {    
        a[i] = i + 1; 
        if (1 + rand() % 100 <= 4)
        {
            int j = (i*2 > n-1) ? i-2 : i*2;
            swap(a,i,j);
        }
    }
}

void printArray(int *arr, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// static void swap(int a[], int i,int  i2)
// {
//     int temp = a[i];
//     a[i] = a[i2];
//     a[i2] = temp;
// }
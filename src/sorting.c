#include "sorting.h"
#include <stdio.h>

static int hoarePartition(int a[], int l, int r, size_t *op);

// static void swap(int a[], int i, int j);


void selectionSort(int n, int a[], size_t *op) {
    int min;
    for (size_t i = 0; i <= n - 2; i++) {
        min = i;
        for (size_t j = i + 1; j <= n-1; j++) {
            if(a[j] < a[min]) min = j;
            *op += 1;
        }
        swap(a,i,min); // Critical Operation
    }
}

void insertionSort(int n, int a[], size_t *op)
{
    for (size_t i = 1; i <= n-1; i++)
    {
        int val = a[i], j = i-1;
        *op += 1; // Counts the number of operations preformed.
        while (j >= 0 && a[j] > val) // Critical operation is the comparison a[j] > val.
        {
            a[j+1] = a[j]; 
            j -= 1;
            *op += 1; // Counts the number of operations preformed.
        }
        a[j+1] = val;
    }
}

void quickSort(int a[], int l, int r, size_t *op)
{
    if(l < r)
    {
        // *op += 1;
        int s = hoarePartition(a, l, r, op);
        quickSort(a, l, s-1, op); 
        quickSort(a, s+1, r, op);
    }
}

void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

static int hoarePartition(int a[], int l, int r, size_t *op)
{
    // *op += 1;
    // printf("Partion called\n");
    int p = a[l];
    int i = l, j = r+1;
    while(i < j) 
    {
        do
        {
            *op += 1;
            i++;
        } while(a[i] < p && i < r); 
        do
        {
            *op += 1;
            j--; 
            // printf("%d\t%d\n",i, j);
        } while(a[j] > p);
        swap(a, i, j);
    }
    swap(a, i, j); // undo last swap when i >= j
    swap(a, l, j);
    return j;
}

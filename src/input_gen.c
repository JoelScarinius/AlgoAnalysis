#include "input_gen.h"
#include <stdio.h>
#include <stdlib.h>

// static void swap(char *a, int i, int  j);

// void orderedArray(int n, char *a)
// {
//     for (int i = 0; i < n; i++)
//     {
//         a[i] = alphabet[i];
//     }
// }

// void revOrderedArray(int n, char *a)
// {
//     for (int i = 0; i < n; i++)
//     {
//         a[i] = n - i;
//     }
// }

// void randomOrderedInput(int n, char *a, char *alphabet)
// {
//     for (int i = 0; i < n; i++)
//     {
//         a[i] = alphabet[rand() % 30];
//     }
// }

// void random4OrderedInput(int n, char *a)
// {
//     for (int i = 0; i < n; i++)
//     {    
//         a[i] = i + 1; 
//         if (1 + rand() % 100 <= 4)
//         {
//             int j = (i*2 > n-1) ? i-2 : i*2;
//             swap(a,i,j);
//         }
//     }
// }

// void printArray(int *arr, int n)
// {
//     int i;
//     for (i = 0; i < n; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }

// static void swap(char *a, int i,int  j)
// {
//     int temp = a[i];
//     a[i] = a[j];
//     a[j] = temp;
// }
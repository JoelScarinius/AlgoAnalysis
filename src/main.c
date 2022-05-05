#include <stdio.h>
#include "sorting.h"
#include "input_gen.h"
#include "fileHandling.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 256
#define ARRAY_SIZE 32768

static void displayMainMenu();
static void simSortAlgo(char algorithm[]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    unsigned int option = 0;
    
    while (option != 4)
    {
        displayMainMenu();
        fflush(stdin);
        scanf("%d", &option);
        switch (option)
        {
        case 1: simSortAlgo("Selection sort"); break;
        case 2: simSortAlgo("Insertion sort"); break;
        case 3: simSortAlgo("Qucik sort"); break;
        case 4: exit(-1); break;
        default: puts("Invalid input, please try again!"); break;
        }
    }
    return 0;
}

static void displayMainMenu()
{
    puts("\nPlease choose an algorithm\n"
         "1. SelectionSort\n"
         "2. InsertionSort\n"
         "3. QuickSort\n"
         "4. Quit");
    printf("Your choice? : ");
}

static void simSortAlgo(char algorithm[])
{
    unsigned int n = INPUT_SIZE, l = 0, r = n-1, count = 30, a[ARRAY_SIZE];
    size_t totOp = 0, avrOp = 0, op = 0;

    // printHeaderToFile(algorithm, "Ordered");
    // while (n <= ARRAY_SIZE)
    // {
    //     orderedArray(n, a); // Ordnad input
    //     // if (n == ARRAY_SIZE)
    //     // {
    //     //     printf("\n");
    //     //     printArray(a, n);
    //     // }
    //     if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, a, &op);// selectionSort
    //     else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, a, &op);// insertionSort
    //     else quickSort(a, l, r, &op);// quickSort
    //     if (n == ARRAY_SIZE)
    //     // {
    //     //     printf("\n");
    //     //     printArray(a, n);
    //     // }
    //     printResultsToFile(n, &op);
    //     n *= 2;
    //     r = n-1;
    //     op = 0;
    // }
    printHeaderToFile(algorithm, "Reversed Ordered");
    // n = r = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        revOrderedArray(n, a); // Omvänd ordnad input 
        if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, a, &op);// selectionSort
        else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, a, &op);// insertionSort
        else quickSort(a, l, r, &op);// quickSort
        printResultsToFile(n, &op);
        n *= 2;
        r = n-1;
        op = 0;
    }
    printHeaderToFile(algorithm, "Random Ordered");
    n = r = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            randomOrderedInput(n, a);
            if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, a, &op);// selectionSort
            else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, a, &op);// insertionSort
            else quickSort(a, l, r, &op);// quickSort
            totOp += op;
            op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
        r = n-1;
        op = 0;
    }
    printHeaderToFile(algorithm, "Almost Ordered");
    n = r = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            random4OrderedInput(n, a);
            if (strcmp(algorithm, "Selection sort") == 0) selectionSort(n, a, &op);// selectionSort
            else if (strcmp(algorithm, "Insertion sort") == 0) insertionSort(n, a, &op);// insertionSort
            else quickSort(a, l, r, &op);// quickSort
            totOp += op;
            op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
        r = n-1;
        op = 0;
    }
}

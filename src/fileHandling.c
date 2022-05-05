#include <stdio.h>
#include <stdlib.h>
#include "fileHandling.h"

void printHeaderToFile(char algorithm[], char inputType[])
{
    FILE *fPtr = fopen("Results.txt", "a");

    fprintf(fPtr, "\n");
    fprintf(fPtr, "%s %s\n", "Algorithm:", algorithm);
    fprintf(fPtr, "%s %s\n", "Input:", inputType);
    fprintf(fPtr, "%s\n%s\n", "n number of op", "----------------");

    fclose(fPtr); // When done reading the file the connection to the file is closed.
}

void printResultsToFile(int n, size_t *op)
{
    FILE *fPtr = fopen("Results.txt", "a");

    fprintf(fPtr, "%u %u\n", n, *op);

    fclose(fPtr); // When done reading the file the connection to the file is closed.
}


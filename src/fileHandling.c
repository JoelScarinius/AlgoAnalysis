#include <stdio.h>
#include <stdlib.h>
#include "fileHandling.h"

void printHeaderToFile(char *algo)
{
    FILE *fPtr = fopen("Results.txt", "a");

    fprintf(fPtr, "\n");
    fprintf(fPtr, "%s %s\n", "Algorithm:", algo);
    fprintf(fPtr, "%s\n%s\n", "pattern number of op", "----------------");

    fclose(fPtr); // When done reading the file the connection to the file is closed.
}

void printResultsToFile(char *pattern, size_t *op)
{
    FILE *fPtr = fopen("Results.txt", "a");

    fprintf(fPtr, "%s %u\n", pattern, *op);

    fclose(fPtr); // When done reading the file the connection to the file is closed.
}


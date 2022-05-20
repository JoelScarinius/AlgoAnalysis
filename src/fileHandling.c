#include <stdio.h>
#include <stdlib.h>
#include "fileHandling.h"

void printHeaderToFile(char *algorithm)
{
    FILE *fPtr = fopen("Results.txt", "a"); // Opens the file in append mode.

    fprintf(fPtr, "\n");
    fprintf(fPtr, "%s %s\n", "Algorithm:", algorithm);
    fprintf(fPtr, "%s %d\n", "Input size:", TEXTLEN-6);
    fprintf(fPtr, "%s\n%s\n", "pattern, number of op, found index", "--------------------");

    fclose(fPtr); // When done printing to the file the connection to the file is closed.
}

void printResultsToFile(char *pattern, size_t op, int lMatchingIdx)
{
    FILE *fPtr = fopen("Results.txt", "a"); // Opens the file in append mode.

    fprintf(fPtr, "%s %u\n", pattern, op, lMatchingIdx);

    fclose(fPtr); // When done printing to the file the connection to the file is closed.
}


#ifndef fileHandling_H_
#define fileHandling_H_

#include <stdlib.h>

#define TEXTLEN 4100
#define PATLEN 20

// Prints a header to a text file.
// Input: Algorithm name
// Output: void
void printHeaderToFile(char *algorithm);

// Prints results to a text file.
// Input: Pattern to search for and a variable that the determines number of operations.
// Output: void 
void printResultsToFile(char *pattern, size_t op, int lMatchingIdx);

#endif
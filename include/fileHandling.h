#ifndef fileHandling_H_
#define fileHandling_H_

#include <stdlib.h>

#define TEXTLEN 5000

// Input: Algorithm name
// Output: Prints a header to a text file. 
void printHeaderToFile(char *algorithm);

// Input: Pattern to search for and a variable that the determines number of operations.
// Output: Prints results to a text file.
void printResultsToFile(char *pattern, size_t *op);

#endif
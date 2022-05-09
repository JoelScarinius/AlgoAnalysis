#ifndef stringMatching_H_
#define stringMatching_H_

#include <stdlib.h>
#define ASCII 128

int bruteForceMatching(char *pattern, char *text);

//Implements Horspool’s algorithm for string matching
//Input: Pattern P[0..m − 1] and text T [0..n − 1]
//Output: The index of the left end of the first matching substring
// or −1 if there are no matches
int horspoolsMatching(char *pattern, char *text, char *ascii);

//Fills the shift table used by Horspool’s and Boyer-Moore algorithms
//Input: Pattern P[0..m − 1] and an alphabet of possible characters
//Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
char *shiftTable(char *pattern, char *alphabet, int m, int n);

#endif
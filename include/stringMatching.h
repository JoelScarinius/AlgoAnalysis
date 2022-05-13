#ifndef stringMatching_H_
#define stringMatching_H_

#include <stdlib.h>
#define ASCII 128

// Implements brute-force string matching
// Input: An array T [0..n − 1] of n characters representing a text,
// an array P[0..m − 1] of m characters representing a pattern and
// a variable (op) that counts number of critical operations preformed.
// Output: The index of the first character in the text that starts a
// matching substring or −1 if the search is unsuccessful
int bruteForceMatching(char *pattern, char *text, size_t *op);

// Implements Horspool’s algorithm for string matching
// Input: Pattern P[0..m − 1], text T [0..n − 1],
// an alphabet (ascii) of possible characters and
// a variable (op) that counts number of critical operations preformed.
// Output: The index of the left end of the first matching substring
// or −1 if there are no matches
// int horspoolsMatching(char *pattern, char *text, char *ascii, size_t *op);

// Implements Horspool’s algorithm for string matching
// Input: Pattern P[0..m − 1], text T [0..n − 1]
// an alphabet (ascii) of possible characters and
// a variable (op) that counts number of critical operations preformed.
// Output: The index of the left end of the first matching substring
// or −1 if there are no matches
int bMHorspoolMatching(char *pattern, char *text, char *ascii, unsigned int option, size_t *op);

#endif
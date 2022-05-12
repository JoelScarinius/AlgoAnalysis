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
int horspoolsMatching(char *pattern, char *text, char *ascii, size_t *op);

// Implements Horspool’s algorithm for string matching
// Input: Pattern P[0..m − 1], text T [0..n − 1]
// an alphabet (ascii) of possible characters and
// a variable (op) that counts number of critical operations preformed.
// Output: The index of the left end of the first matching substring
// or −1 if there are no matches
int boyerMooreMatching(char *pattern, char *text, char *ascii, size_t *op);

// Fills the shift table used by Horspool’s and Boyer-Moore algorithms
// Input: Pattern P[0..m − 1] and an alphabet of possible characters
// Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
char *shiftTable(char *pattern, char *alphabet, int m, int n);

char *suffix(char *pattern, char *ascii, int m, int n);


#endif
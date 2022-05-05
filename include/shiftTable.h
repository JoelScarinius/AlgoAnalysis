#ifndef shiftTable_H_
#define shiftTable_H_

#include <stdlib.h>

//Fills the shift table used by Horspool’s and Boyer-Moore algorithms
//Input: Pattern P[0..m − 1] and an alphabet of possible characters
//Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
char *shiftTable(char *pattern, int inputLen);

#endif
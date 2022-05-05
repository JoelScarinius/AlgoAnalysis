#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shiftTable.h"

// ALGORITHM ShiftTable(P[0..m − 1])
// //Fills the shift table used by Horspool’s and Boyer-Moore algorithms
// //Input: Pattern P[0..m − 1] and an alphabet of possible characters
// //Output: Table[0..size − 1] indexed by the alphabet’s characters and
// // filled with shift sizes computed by formula (7.1)
// for i ← 0 to size − 1 do Table[i]← m
// for j ← 0 to m − 2 do Table[P[j ]]← m − 1 − j
// return Table

char *shiftTable(char *pattern, char *alphabet, int inputLen)
{
    int m = strlen(pattern), table[28];
    for (unsigned int i = 0; i < 28; i++) table[i] = m;
    for (unsigned int j = 0; j < m-2; j++) table[(int)pattern[j]] = m-1-j;
    return table;
}

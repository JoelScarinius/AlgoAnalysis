#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringMatching.h"

// static void printTextandPattern(char *text, char *pattern, int i, int n, int m);
// Fills the shift table used by Horspool’s and Boyer-Moore algorithms
// Input: Pattern P[0..m − 1] and an alphabet of possible characters
// Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
static char *shiftTable(char *pattern, char *alphabet, int m, int n);
static int *suffix(char *pattern, unsigned int m);
static char *getSubstring(char *pattern, unsigned int i, unsigned int j);
static int getMatchingIdx(char *suffix, char *pattern, unsigned int k, unsigned int m);

int bruteForceMatching(char *pattern, char *text, size_t *op)
{
    unsigned int m = strlen(pattern), n = strlen(text);
    for (int i = 0; i <= n-m; i++)
    {
        unsigned int j = 0;
        while (j < m && pattern[j] == text[i+j]) 
            j++;
            (*op)++;
        if (j == m) return i;
    }
    return -1;
}

int bMHorspoolMatching(char *pattern, char *text, char *ascii, unsigned int option, size_t *op)
{   
    int m = strlen(pattern), i = m-1;
    unsigned int n = strlen(text), *goodTable;
    char *badTable = shiftTable(pattern, ascii, m, n);
    if (option == 3) goodTable = suffix(pattern, m);

    while (i <= n-1)
    {
        unsigned int k = 0;
        (*op)++;
        while (k <= m-1 && pattern[m-1-k] == text[i-k]) 
        {
            k++;
            (*op)++;
        }    
        if (k == m) return i-m+1;
        else 
        {
            printf("\nd1: %d", (option == 3) ? badTable[(int)text[i-k]]-k : badTable[(int)text[i]]);
            // printTextandPattern(text, pattern, i, n, m);
            int x = badTable[(int)text[i-k]]-k;
            int y = goodTable[k];
            if (option == 3)
            {
                printf("\td2: %d", goodTable[k]);
                if (badTable[(int)text[i-k]]-k > 0 || goodTable[k] > 0)
                {
                    if (goodTable[k] > (badTable[(int)text[i-k]]-k))
                    {
                        i += goodTable[k];
                    }
                    else
                    {
                        i += (badTable[(int)text[i-k]]-k);
                    }
                    // i += ((badTable[(int)text[i-k]]-k) > (goodTable[k])) ? (badTable[(int)text[i-k]]-k) : goodTable[k];
                }
                else i += 1;
            }
            else i += badTable[(int)text[i]];
        }
    }
    free(goodTable);
    return -1;
}

static char *shiftTable(char *pattern, char *ascii, int m, int n)
{
    for (unsigned int i = 0; i <= ASCII; i++) 
        ascii[i] = m;
    for (unsigned int j = 0; j <= m-2 && m-1 > 0; j++) 
        ascii[(int)pattern[j]] = m-1-j;
    return ascii;
}

static char *getSubstring(char* pattern, unsigned int i, unsigned int m)
{
    char* substring = calloc((m-i)+1, sizeof(char));
    for(unsigned int k = i; k < m; k++)
        substring[k-i] = pattern[k]; 
    return substring;
}

static int *suffix(char* pattern, unsigned int m)
{
    int *goodSuffixTable = (int *)calloc(m,sizeof(int));
    unsigned int k = 1;

    while(k < m)
    {
        //create the suffix
        char* suffix = getSubstring(pattern, (m-k), m);
        //get its rightmost ocurrence to its left in pattern
        int idx = getMatchingIdx(suffix, pattern, k, m);
        free(suffix);
        //if you found the rightmost ocurrence of the suffix
        if(idx != -1)
            goodSuffixTable[k] = (m-k) - idx;
        //if you did not find the rightmost occurrence of the suffix
        else goodSuffixTable[k] = m-1;
        k++;
    }
    return goodSuffixTable;
}

static int getMatchingIdx(char* suffix, char* pattern, unsigned int k, unsigned int m)
{
    //idx of rightmost occurrence
    int idx = -1;
    //set temp = pattern
    for(char* temp = pattern; temp < pattern + (m-k); temp++)
        //if temp contains suffix then
        if(strncmp(temp, suffix, k)==0) idx = temp-pattern;
    return idx;
}

// static void printTextandPattern(char *text, char *pattern, int i, int n, int m)
// {
//     printf("\n%s\n", text);
//     if (i == m-1) 
//     {
//         printf("%s\n", pattern);
//         printf("\n%s\n", text);
//         printf(" ");
//     }
//     if (i+m >= n)
//     {
//         for (unsigned k = 0; k < n-m; k++)
//         {
//             printf(" ");
//         }
//     }
//     else
//     {
//         for (unsigned int j = 0; j < i; j++)
//         {
//             printf(" ");
//         }
//     }
//     printf("%s\n", pattern);
// }

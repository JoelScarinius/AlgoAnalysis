#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringMatching.h"

// Fills the shift table used by Horspool’s and Boyer-Moore algorithms
// Input: Pattern P[0..m − 1] and an alphabet of possible characters
// Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
static char *shiftTable(char *pattern, char *alphabet, int m, int n);
// Fills the suffix used by Boyer-Moore algorithm
// Input: Pattern P[0..m − 1] and the length of the pattern
// Output: goodTable[0..m − 1] filled with m number of shifts depended on number of matches.
static int *suffix(char *pattern, unsigned int m);
// This is a helper function to the suffix function that collects the substring that is
// needed for searching for dublicates of this substring in the pattern.
// Input: Pattern P[0..m − 1] and two index variables represented as unsigned ints.
// One is the length of the pattern and the other is the length of the pattern minus the number of matches.
// Output: A substring represented as a char pointer.
static char *getSubstring(char *pattern, unsigned int i, unsigned int m);
// This is a helper function to the suffix function that finds out at which index
// from the right you can find a duplicate of the matched substring. 
// Input: Pattern [0..m − 1],  substring [0..m − 2] and two index variables represented as unsigned ints.
// One is the length of the pattern and the other is the number of matches. 
// Output: An index of the right most occurence of a matching substring.
static int getMatchingIdx(char *subString, char *pattern, unsigned int k, unsigned int m, int *duplicateIdx);
// This function prints text and pattern to show the user the shifts between each iteration of the algorithm used.
// Input: Pattern P[0..m − 1], text T [0..n − 1],
// i determines the position in the text, n is the length of the text, m is the length of the pattern
// and option is to determine BoyerMoore/Horspool or Brute-Force algorithm
// Output: Prints text and pattern to the screen. 
static void printTextandPattern(char *text, char *pattern, unsigned int i, unsigned int n, unsigned int m, unsigned int option);

int bruteForceMatching(char *pattern, char *text, size_t *op)
{
    unsigned int m = strlen(pattern), n = strlen(text);
    for (int i = 0; i <= n-m; i++)
    {
        printTextandPattern(text, pattern, i, n, m, 1); // Prints text and pattern to screen.
        unsigned int j = 0;
        (*op)++;
        while (j < m && pattern[j] == text[i+j]) // Critical operation that I want to count.
        {
            j++;
            (*op)++;
        }
        if (j == m) return i;
    }
    return -1;
}

int bMHorspoolMatching(char *pattern, char *text, char *ascii, unsigned int option, size_t *op)
{   
    int m = strlen(pattern), i = m-1; // i keeps track of which characters that are supposed to be compared.
    unsigned int n = strlen(text), *goodTable;
    char *badTable = shiftTable(pattern, ascii, m, n); // Used in both Horspool and Boyer-Moore
    if (option == 3) 
    {
        goodTable = suffix(pattern, m); // Used only in Boyer-Moore
        printf("\n");
        for (size_t u = 0; u < m-1; u++) printf("%d ", goodTable[u]); // This for prints the goodTable.
    }
    while (i <= n-1)
    {
        printTextandPattern(text, pattern, i, n, m, option); // Prints text and pattern to screen.
        int k = 0; // Variable that counts number of matches.
        (*op)++;
        // Loops until a mismatch occur or every character in the pattern is matched.
        while (k <= m-1 && pattern[m-1-k] == text[i-k]) // Critical operation that I want to count.
        {
            k++;
            (*op)++;
        }    
        if (k == m) return i-m+1; // If a matching substring is found, return index where substring is found. 
        else 
        {
            // printf("\nd1: %d", (option == 3) ? badTable[(int)text[i-k]]-k : badTable[(int)text[i]]); // This is for printing d1
            if (option == 3) // Only Boyer-Moore uses this part.
            {
                // printf("\td2: %d", (k > 0) ? goodTable[k-1] : goodTable[k]); // This is for printing d2
                if (k == 0) i += (int)(badTable[(int)text[i-k]]-k);
                // The maximum value generated from the 2 tables decides how many steps can be shifted.
                else
                {
                    i += ((int)(badTable[(int)text[i-k]]-k) > ((int)goodTable[k-1])) 
                    ? (int)(badTable[(int)text[i-k]]-k) : (int)goodTable[k-1];
                }
            }
            else i += badTable[(int)text[i]]; // Only Horspool uses this part.
        }
    }
    free(goodTable);
    return -1;
}

static char *shiftTable(char *pattern, char *ascii, int m, int n)
{
    for (unsigned int i = 0; i <= ASCII; i++) // Fills the shiftTable with max steps possible to shift.
        ascii[i] = m;
    for (unsigned int j = 0; j <= m-2 && m-1 > 0; j++) // Gives certain shift steps to the characters in the pattern.
        ascii[(int)pattern[j]] = m-1-j;
    return ascii;
}

static int *suffix(char *pattern, unsigned int m)
{
    int *goodTable = (int *)calloc(m-1,sizeof(int)); // Allocates memory for the good suffix table.
    unsigned int k = 1; // Variable that controls number of matches.

    while (k < m) // Loops until all different number of substrings is handled correctly
    {
        int duplicateIdx = -1;
        char* subString = getSubstring(pattern, (m-k), m); // Returns Substring used to find duplicates in pattern.
        int idx = getMatchingIdx(subString, pattern, k, m, &duplicateIdx); // Idx of the rightmost first occurence of substring.
        free(subString); // Free memory allocated for substring because it is no longer used.
        // If a rightmost ocurrence of the substring is found or we have duplictes of the substring that makes it possible to preform a longer shift.
        if (idx != -1) goodTable[k-1] = (duplicateIdx >= idx || k == 1) ? (m-k) - idx : m-1-duplicateIdx; 
        // If a rightmost occurrence of the substring wasn't found but a substring was found in an earlier iteration.
        else if (idx == -1 && duplicateIdx == 0) goodTable[k-1] = m-1; 
        else goodTable[k-1] = m; // If no occurence of the substring was found in first iteration.
        k++;
    }
    return goodTable;
}

static char *getSubstring(char *pattern, unsigned int i, unsigned int m)
{
    char* substring = calloc((m-i)+1, sizeof(char)); // Allocates memory for the substring and initializes it.
    for (unsigned int k = i; k < m; k++) substring[k-i] = pattern[k]; // Creates the substring depended on number of matches.
    return substring;
}

static int getMatchingIdx(char *subString, char *pattern, unsigned int k, unsigned int m, int *duplicateIdx)
{
    int idx = -1;
    char *temp = pattern;
    // Compares pattern with substring and if match is found assign idx with index of rightmost occurence.
    while (temp < pattern + (m-k))
    {
        if (strncmp(temp, subString, k)==0) idx = temp-pattern;
        temp++;
    }
    temp = pattern; // Resets temp to pattern.
    unsigned int i = k, j = 0;

    while (temp <= pattern + (m-1) && i > 0)
    {
        // Compares pattern with all substrings of the substring to look for duplicates of the different substrings.
        if (strncmp(temp, subString + j, i)==0 && temp-pattern <= m-1)
        {
            // Assign leftmost index of found duplicate substring if a longer shift is possible, determined by restraints.
            if (temp-pattern < *duplicateIdx || *duplicateIdx == -1) 
            {    
                if (*duplicateIdx - (k-1) != 0) 
                {
                    *duplicateIdx = temp-pattern; 
                    // Secures that the correct index is assigned depended on number of matches at this certain iteration.
                    if (k > 1) *duplicateIdx += i-1; 
                    temp += (m-i-1); // Makes the loop to jump to next iteration. 
                }
            }
        }
        temp++;
        if (temp >= pattern + (m-1)) // Changes vaules to be correct for next iteration.
        {
            i--;
            j++;
            temp = pattern; // Resets temp to pattern.
        }
    }
    return idx;
}

static void printTextandPattern(char *text, char *pattern, unsigned int i, unsigned int n, unsigned int m, unsigned int option)
{
    if (i == 0 && option == 1) printf("\n%s\n", text);
    else if (i == m-1 && option != 1) printf("\n%s\n", text);
    else
    {
        if (option != 1)
            for (unsigned int j = 0; j < i-(m-1); j++)
            {
                printf(" ");
            }
        else
            for (unsigned int j = 0; j < i; j++)
            {
                printf(" ");
            }
    }
    printf("%s\n", pattern);
}

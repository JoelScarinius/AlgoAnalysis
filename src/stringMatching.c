#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringMatching.h"

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

int horspoolsMatching(char *pattern, char *text, char *ascii, size_t *op)
{
    int m = strlen(pattern), i = m-1;
    unsigned int n = strlen(text);
    char *table = shiftTable(pattern, ascii, m, n);
    while (i <= n-1)
    {
        unsigned int k = 0;
        while (k <= m-1 && pattern[m-1-k] == text[i-k]) 
            k++;
            (*op)++;
        if (k == m) return i-m+1;
        else i += table[(int)text[i]];
    }
    return -1;
}

int boyerMooreMatching(char *pattern, char *text, char *ascii, size_t *op)
{
    int m = strlen(pattern), i = m-1;
    unsigned int n = strlen(text);
    char *table = shiftTable(pattern, ascii, m, n);
    while (i <= n-1)
    {
        unsigned int k = 0;
        while (k <= m-1 && pattern[m-1-k] == text[i-k]) k++;
        if (k == m) return i-m+1;
        else i += table[(int)text[i]];
    }
    return -1;
}

char *shiftTable(char *pattern, char *ascii, int m, int n)
{
    for (unsigned int i = 0; i <= ASCII; i++) 
        ascii[i] = m;
    for (unsigned int j = 0; j <= m-2 && m-1 > 0; j++) 
        ascii[(int)pattern[j]] = m-1-j;
    return ascii;
}

char *suffix(char *pattern, char *ascii, int m, int n)
{
    for (unsigned int i = 0; i <= ASCII; i++) 
        ascii[i] = m;
    for (unsigned int j = 0; j <= m-2; j++) 
    {    
        ascii[(int)pattern[j]] = m-1-j;
        printf("%d\n", ascii[(int)pattern[j]]);
    }
    return ascii;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringMatching.h"

int bruteForceMatching(char *pattern, char *text)
{
    unsigned int m = strlen(pattern), n = strlen(text);
    for (int i = 0; i < n; i++)
    {
        if (pattern[i] == text[i])
        {
            unsigned int j = i;
            while (j < m && pattern[j] == text[j])
            {
                if (j == m) return i;
                j++;
            }
        }
    }
    return -1;
}

int horspoolsMatching(char *pattern, char *text, char *ascii)
{
    unsigned int m = strlen(pattern), n = strlen(text);
    int i = m-1; 
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
    for (unsigned int j = 0; j <= m-2; j++) 
    {    
        ascii[(int)pattern[j]] = m-1-j;
        printf("%d\n", ascii[(int)pattern[j]]);
    }
    return ascii;
}

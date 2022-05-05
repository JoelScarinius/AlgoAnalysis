#include <stdio.h>
#include "input_gen.h"
#include "fileHandling.h"
#include "shiftTable.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 256
#define ARRAY_SIZE 32768

static void displayMainMenu();
//Implements Horspool’s algorithm for string matching
//Input: Pattern P[0..m − 1] and text T [0..n − 1]
//Output: The index of the left end of the first matching substring
// or −1 if there are no matches
static void horsepools(char algorithm[]);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    unsigned int option = 0;
    
    while (option != 4)
    {
        displayMainMenu();
        fflush(stdin);
        scanf("%d", &option);
        switch (option)
        {
        case 1: horsepools("Ordered(A-Z)"); break;
        case 2: horsepools("Reveresed Ordered(Z-A)"); break;
        case 3: horsepools("Random Ordered"); break;
        case 4: horsepools("Almost Ordered"); break;
        case 5: exit(-1); break;
        default: puts("Invalid input, please try again!"); break;
        }
    }
    return 0;
}

static void displayMainMenu()
{
    puts("\nPlease choose input type\n"
         "1. Ordered(A-Z)\n"
         "2. Reveresed Ordered(Z-A)\n"
         "3. Random Ordered\n"
         "4. Almost Ordered\n"
         "5. Quit");
    printf("Your choice? : ");
}

static void horsepools(char algorithm[])
{
    unsigned int n = INPUT_SIZE, l = 0, r = n-1, count = 30;
    size_t totOp = 0, avrOp = 0, op = 0;

    char a[ARRAY_SIZE], alphabet[] = {'A', 'B', 'C', 'D', 
                                      'E', 'F', 'G', 'H',
                                      'I', 'J', 'K', 'L', 
                                      'M', 'N', 'O', 'P', 
                                      'Q', 'R', 'S', 'T', 
                                      'U', 'V', 'X', 'Y', 
                                      'Z', '_', '\0'};
    char *patterns[] = ("JIM_SAW_ME_IN_A_BARBERSHOP_", "BESS_KNEW_ABOUT_BAOBABS", 
                       "TTATAGATCTCGTATTCTTTTATAGATCTCCTATTCTT", "TCCTATTCTT",
                       "SORTING ALGORITHM CAN USE BRUTE FORCE METHOD");
    char *words[] = ("HELLO_", "DOG_", "CAT_", "RANDOM_",
                    "WEIRD_", "ENGLISH_", "POLICE_", "BIKE_",
                    "XENON_LIGHTS_", "JIM_", "SAW_", "ME_",
                    "IN_", "BARBERSHOP_", "A_", "YELLOW_",
                    "SUBMARINE_", "FEAR_", "FIERCENESS_", "KICK_",
                    "QUICKLY_", "RUN_", "SPORT_", "WITH_", "EVER_", "ZOO_");

    printHeaderToFile(algorithm, "Ordered");
    while (n <= ARRAY_SIZE)
    {
        
        printResultsToFile(n, &op);
        n *= 2;
        r = n-1;
        op = 0;
    }
    printHeaderToFile(algorithm, "Reversed Ordered");
    n = r = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        
        printResultsToFile(n, &op);
        n *= 2;
        r = n-1;
        op = 0;
    }
    printHeaderToFile(algorithm, "Random Ordered");
    n = r = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            // randomOrderedInput(n, a);
            
            totOp += op;
            op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
        r = n-1;
        op = 0;
    }
    printHeaderToFile(algorithm, "Almost Ordered");
    n = r = INPUT_SIZE;
    while (n <= ARRAY_SIZE)
    {
        for (size_t i = 1; i <= count; i++)
        {
            // random4OrderedInput(n, a);
            
            totOp += op;
            op = 0;
        }
        avrOp = totOp/30;
        printResultsToFile(n, &avrOp);
        avrOp = totOp = 0;
        n *= 2;
        r = n-1;
        op = 0;
    }
}

int horsepoolsMatching(char *pattern, char *text)
{
    int inputLen;
    int table = shiftTable(pattern, inputLen);
    int m = inputLen, i = m-1, n = 0;
    while (i <= n-1)
    {
        int k = 0;
        while (k <= m-1 && pattern[m-1-k] == text[i-k]) k++;
        if (k == m) return i-m+1;
        else i += table[(int)text[i]];
    }
    
    
    

}
// ALGORITHM HorspoolMatching(P[0..m − 1], T [0..n − 1])

// ShiftTable(P[0..m − 1]) //generate Table of shifts
// i ← m − 1 //position of the pattern’s right end
// while i ≤ n − 1 do
// k ← 0 //number of matched characters
// while k ≤ m − 1 and P[m − 1 − k] = T [i − k] do
// k ← k + 1
// if k = m
// return i − m + 1
// else i ← i + Table[T [i]]
// return −1
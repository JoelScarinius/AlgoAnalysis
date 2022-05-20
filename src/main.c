#include "fileHandling.h"
#include "stringMatching.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUMOFRUNS 30

// Displays the main menu in the terminal
// Input: void
// Output: static void
static void displayMainMenu();
// Prompts the user to input a text and a pattern to search for in the text.
// Input: Two char pointers one representing the text the other the pattern.
// Output: static void
static void getTextAndPattern(char *text, char *pattern);

int main(int argc, char const *argv[])
{
    size_t op = 0, totOp = 0, avrOp = 0;;
    unsigned int option = 0, numOfRuns = 0;
    int lMatchingIdx = 0;

    while (option != 4)
    {
        char ascii[ASCII];
        char *text = (char *)malloc(sizeof(char)*TEXTLEN);
        char *pattern = (char *)malloc(sizeof(char)*PATLEN);

        displayMainMenu(); // Prints main menu.
        fflush(stdin);
        scanf("%u", &option);
        if (option == 1 || option == 2 || option == 3) getTextAndPattern(text, pattern);
        
        switch (option)
        {
        case 1: 
                if (numOfRuns == 0) printHeaderToFile("Brute-Force matching"); 
                lMatchingIdx = bruteForceMatching(pattern, text, &op); 
                printf("\n%d\n", lMatchingIdx); 
                break;
        case 2: 
                if (numOfRuns == 0) printHeaderToFile("Horspool matching"); 
                lMatchingIdx = bMHorspoolMatching(pattern, text, ascii, option, &op); 
                printf("\n%d\n", lMatchingIdx); 
                break;
        case 3: 
                if (numOfRuns == 0) printHeaderToFile("Boyer-Moore matching"); 
                lMatchingIdx = bMHorspoolMatching(pattern, text, ascii, option, &op); 
                printf("\n%d\n", lMatchingIdx); 
                break;
        case 4: exit(-1); break;
        default: puts("Invalid input, please try again!"); break;
        }
        if (option == 1 || option == 2 || option == 3) printResultsToFile(pattern, op, lMatchingIdx);
        totOp += op;
        op = 0;

        numOfRuns++;
        if (numOfRuns == MAXNUMOFRUNS)
        {
            if (option == 1) printHeaderToFile("Brute-Force matching (AVERAGE)");
            else if (option == 2) printHeaderToFile("Horspool matching (AVERAGE)"); 
            else printHeaderToFile("Boyer-Moore matching (AVERAGE)"); 
            avrOp = (totOp/MAXNUMOFRUNS); 
            printResultsToFile("AVERAGE", avrOp, lMatchingIdx);
            totOp = 0;
            numOfRuns = 0;
        }
        free(text);
        free(pattern);
    }
    fflush(stdin);
    getchar();
    return 0;
}

static void displayMainMenu()
{
    puts("\nPlease choose an algorithm\n"
         "1. Brute-force matching\n"
         "2. Horspool matching\n"
         "3. Boyer-Moore matching\n"
         "4. Quit");
    printf("Your choice? : ");
}

static void getTextAndPattern(char *text, char *pattern)
{   
    fflush(stdin);
    puts("Please enter a text here:");
    fgets(text, TEXTLEN, stdin);
    text[strlen(text)-1] = '\0';
    fflush(stdin);
    puts("Please enter a pattern in the text to search for here:");
    fgets(pattern, TEXTLEN, stdin);
    pattern[strlen(pattern)-1] = '\0';
}
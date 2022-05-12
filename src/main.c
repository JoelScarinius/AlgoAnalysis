#include "fileHandling.h"
#include "stringMatching.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEXTLEN 5000
#define ALGOLEN 20

static void displayMainMenu();
static void userInput(unsigned int *option, char *text, char *pattern);

int main(int argc, char const *argv[])
{
    size_t op = 0;
    unsigned int option = 0;
    int lMatchingIdx;

    while (option != 4)
    {
        char ascii[ASCII];
        char *text = (char *)malloc(sizeof(char)*TEXTLEN);
        char *pattern = (char *)malloc(sizeof(char)*TEXTLEN);

        displayMainMenu(); // Prints main menu.
        userInput(&option, text, pattern);
        
        switch (option)
        {
        case 1: 
                lMatchingIdx = bruteForceMatching(pattern, text, &op); 
                printf("%d\n", lMatchingIdx); 
                printHeaderToFile("Brute-Force matching"); 
                break;
        case 2: 
                lMatchingIdx = horspoolsMatching(pattern, text, ascii, &op); 
                printf("%d\n", lMatchingIdx); 
                printHeaderToFile("Horspool matching"); 
                break;
        case 3: 
                lMatchingIdx = boyerMooreMatching(pattern, text, ascii, &op); 
                printf("%d\n", lMatchingIdx); 
                printHeaderToFile("Boyer-Moore matching"); 
                break;
        case 4: exit(-1); break;
        default: puts("Invalid input, please try again!"); break;
        }
        if (option == 1 || option == 2 || option == 3) printResultsToFile(pattern, &op);
        op = 0;
        free(text);
        free(pattern);
    }
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

static void userInput(unsigned int *option, char *text, char *pattern)
{   
    fflush(stdin);
    scanf("%d", option);
    if (*option == 4) return;
    fflush(stdin);
    puts("Please enter a text here:");
    fgets(text, TEXTLEN, stdin);
    text[strlen(text)-1] = '\0';
    fflush(stdin);
    puts("Please enter a pattern in the text to search for here:");
    fgets(pattern, TEXTLEN, stdin);
    pattern[strlen(pattern)-1] = '\0';
    // if (*option == 1) return "Brute-force matching";
    // else if (*option == 2) return "Horspool matching";
    // else if (*option == 3) return "Boyer-Moore matching";
}
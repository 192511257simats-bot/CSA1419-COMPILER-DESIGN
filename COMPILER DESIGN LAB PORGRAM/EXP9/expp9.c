#include <stdio.h>

int main()
{
    printf("Given Grammar:\n");
    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n");

    printf("\nGrammar after Eliminating Left Recursion:\n");
    printf("S  -> (L) | a\n");
    printf("L  -> SL'\n");
    printf("L' -> ,SL' | E\n");

    return 0;
}

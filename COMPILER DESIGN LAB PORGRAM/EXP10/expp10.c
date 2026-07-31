#include <stdio.h>

int main()
{
    printf("Given Grammar:\n");
    printf("S -> iEtS | iEtSeS | a\n");
    printf("E -> b\n");

    printf("\nGrammar after Left Factoring:\n");
    printf("S  -> iEtSS' | a\n");
    printf("S' -> eS | E\n");
    printf("E  -> b\n");

    return 0;
}

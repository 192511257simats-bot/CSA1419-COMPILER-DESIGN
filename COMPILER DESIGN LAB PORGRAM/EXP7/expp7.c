#include <stdio.h>

int main()
{
    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> E\n");
    printf("B -> E\n\n");

    printf("FIRST(A) = { E }\n");
    printf("FIRST(B) = { E }\n");
    printf("FIRST(S) = { a, b }\n");

    return 0;
}

#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;
int error = 0;

void E();
void EP();
void T();
void TP();
void F();

void E()
{
    T();
    EP();
}

void EP()
{
    if(input[pos] == '+')
    {
        pos++;
        T();
        EP();
    }
}

void T()
{
    F();
    TP();
}

void TP()
{
    if(input[pos] == '*')
    {
        pos++;
        F();
        TP();
    }
}

void F()
{
    if(input[pos] == 'i')
    {
        pos++;
    }
    else if(input[pos] == '(')
    {
        pos++;
        E();

        if(input[pos] == ')')
            pos++;
        else
            error = 1;
    }
    else
    {
        error = 1;
    }
}

int main()
{
    printf("Grammar:\n");
    printf("E  -> TE'\n");
    printf("E' -> +TE' | ε\n");
    printf("T  -> FT'\n");
    printf("T' -> *FT' | ε\n");
    printf("F  -> (E) | i\n\n");

    printf("Enter the input string: ");
    scanf("%s", input);

    E();

    if(error == 0 && input[pos] == '\0')
        printf("\nThe given string satisfies the grammar (Accepted).\n");
    else
        printf("\nThe given string does NOT satisfy the grammar (Rejected).\n");

    return 0;
}

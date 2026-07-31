#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

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
    if(input[pos] == 'i')      // id
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
            printf("Error: Missing )\n");
    }
    else
    {
        printf("Error: Invalid Input\n");
    }
}

int main()
{
    printf("Grammar:\n");
    printf("E  -> TE'\n");
    printf("E' -> +TE' | Epsilon\n");
    printf("T  -> FT'\n");
    printf("T' -> *FT' | Epsilon\n");
    printf("F  -> (E) | id\n\n");

    printf("Enter the expression (use i for id): ");
    scanf("%s", input);

    E();

    if(input[pos] == '\0')
        printf("\nString Accepted.\n");
    else
        printf("\nString Rejected.\n");

    return 0;
}

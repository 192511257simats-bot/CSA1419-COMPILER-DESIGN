#include <stdio.h>

int main()
{
    char str[100];
    int i = 0;

    printf("Enter an expression: ");
    fgets(str, sizeof(str), stdin);

    printf("\nArithmetic Operators Found:\n");

    while (str[i] != '\0')
    {
        switch (str[i])
        {
            case '+':
                printf("+ : Addition Operator\n");
                break;

            case '-':
                printf("- : Subtraction Operator\n");
                break;

            case '*':
                printf("* : Multiplication Operator\n");
                break;

            case '/':
                printf("/ : Division Operator\n");
                break;
        }
        i++;
    }

    return 0;
}

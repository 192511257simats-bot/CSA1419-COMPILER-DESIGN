#include <stdio.h>
#include <string.h>

int main()
{
    char expr[50];
    char op1, op2;
    char operator1, operator2;

    printf("Enter Expression (Example: a+b*c): ");
    scanf("%s", expr);

    // Assuming expression is of the form a+b*c
    op1 = expr[0];
    operator1 = expr[1];
    op2 = expr[2];
    operator2 = expr[3];

    printf("\nThree Address Code:\n");

    if(operator2 == '*' || operator2 == '/')
    {
        printf("t1 = %c %c %c\n", expr[2], operator2, expr[4]);
        printf("t2 = %c %c t1\n", expr[0], operator1);
    }
    else
    {
        printf("t1 = %c %c %c\n", expr[0], operator1, expr[2]);
        printf("t2 = t1 %c %c\n", operator2, expr[4]);
    }

    return 0;
}

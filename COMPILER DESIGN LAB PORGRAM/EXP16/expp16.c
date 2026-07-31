#include <stdio.h>
#include <string.h>

int main()
{
    char op, arg1, arg2;

    printf("Enter an expression (Example: a+b): ");
    scanf("%c%c%c", &arg1, &op, &arg2);

    printf("\nGenerated Target Code:\n");

    printf("MOV R0, %c\n", arg1);

    switch(op)
    {
        case '+':
            printf("ADD R0, %c\n", arg2);
            break;

        case '-':
            printf("SUB R0, %c\n", arg2);
            break;

        case '*':
            printf("MUL R0, %c\n", arg2);
            break;

        case '/':
            printf("DIV R0, %c\n", arg2);
            break;

        default:
            printf("Invalid Operator!\n");
            return 0;
    }

    printf("MOV RESULT, R0\n");

    return 0;
}

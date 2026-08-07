#include <stdio.h>
#include <string.h>

int isNumeric(char type[])
{
    if (strcmp(type, "int") == 0 ||
        strcmp(type, "float") == 0 ||
        strcmp(type, "char") == 0)
        return 1;

    return 0;
}

int isPointer(char type[])
{
    int len = strlen(type);

    if (len > 1 && type[len - 1] == '*')
        return 1;

    return 0;
}

int main()
{
    char operand1[20], operand2[20];
    char type1[20], type2[20];
    char op;

    printf("TYPE CHECKING FOR ARITHMETIC EXPRESSION\n");
    printf("----------------------------------------\n");

    printf("Enter first operand: ");
    scanf("%s", operand1);

    printf("Enter type of first operand: ");
    scanf("%s", type1);

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter second operand: ");
    scanf("%s", operand2);

    printf("Enter type of second operand: ");
    scanf("%s", type2);

    printf("\nExpression: %s %c %s\n",
           operand1, op, operand2);

    /* Check operator */
    if (op != '+' && op != '-' &&
        op != '*' && op != '/')
    {
        printf("Result: Invalid operator.\n");
        return 0;
    }

    /* Check pointer types */
    if (isPointer(type1) || isPointer(type2))
    {
        printf("Result: TYPE ERROR\n");
        printf("Arithmetic operation cannot be performed "
               "with pointer type.\n");
    }
    /* Check numeric types */
    else if (isNumeric(type1) && isNumeric(type2))
    {
        printf("Result: Expression is VALID.\n");
        printf("Both operands have compatible arithmetic types.\n");
    }
    else
    {
        printf("Result: TYPE ERROR\n");
        printf("Incompatible operand types.\n");
    }

    return 0;
}

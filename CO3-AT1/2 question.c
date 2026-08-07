#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[MAX];
    int i, a, b, result;

    printf("POSTFIX EXPRESSION EVALUATION\n");
    printf("-----------------------------\n");

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
                case '+':
                    result = a + b;
                    printf("%d + %d = %d\n", a, b, result);
                    break;

                case '-':
                    result = a - b;
                    printf("%d - %d = %d\n", a, b, result);
                    break;

                case '*':
                    result = a * b;
                    printf("%d * %d = %d\n", a, b, result);
                    break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero is not allowed.\n");
                        return 1;
                    }

                    result = a / b;
                    printf("%d / %d = %d\n", a, b, result);
                    break;

                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            push(result);
        }
    }

    result = pop();

    printf("-----------------------------\n");
    printf("Final Result = %d\n", result);

    return 0;
}

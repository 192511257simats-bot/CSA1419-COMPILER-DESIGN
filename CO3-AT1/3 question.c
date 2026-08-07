#include <stdio.h>
#include <ctype.h>

char expr[100];
int pos = 0;

/* Function prototypes */
int E();
int Eprime(int inherited);
int T();
int Tprime(int inherited);
int F();

/* E -> T E' */
int E()
{
    int value;

    value = T();

    /* Pass T's value as inherited attribute to E' */
    return Eprime(value);
}

/* E' -> + T E' | epsilon */
int Eprime(int inherited)
{
    int value;

    if (expr[pos] == '+')
    {
        pos++;

        value = T();

        /* Pass updated value as inherited attribute */
        return Eprime(inherited + value);
    }

    return inherited;
}

/* T -> F T' */
int T()
{
    int value;

    value = F();

    /* Pass F's value as inherited attribute to T' */
    return Tprime(value);
}

/* T' -> * F T' | epsilon */
int Tprime(int inherited)
{
    int value;

    if (expr[pos] == '*')
    {
        pos++;

        value = F();

        /* Pass updated value as inherited attribute */
        return Tprime(inherited * value);
    }

    return inherited;
}

/* F -> number */
int F()
{
    int value = 0;

    while (isdigit(expr[pos]))
    {
        value = value * 10 + (expr[pos] - '0');
        pos++;
    }

    return value;
}

int main()
{
    int result;

    printf("L-ATTRIBUTED EXPRESSION EVALUATION\n");
    printf("----------------------------------\n");

    printf("Enter expression: ");
    scanf("%s", expr);

    result = E();

    printf("----------------------------------\n");
    printf("Expression = %s\n", expr);
    printf("Result = %d\n", result);

    return 0;
}

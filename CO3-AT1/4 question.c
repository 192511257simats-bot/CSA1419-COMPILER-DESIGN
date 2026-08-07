#include <stdio.h>
#include <string.h>

int isBasicType(char type[])
{
    if (strcmp(type, "int") == 0 ||
        strcmp(type, "float") == 0 ||
        strcmp(type, "char") == 0)
        return 1;

    return 0;
}

int isPointerType(char type[])
{
    int len = strlen(type);

    if (len > 1 && type[len - 1] == '*')
        return 1;

    return 0;
}

int equivalent(char type1[], char type2[])
{
    /* Basic type comparison */
    if (isBasicType(type1) && isBasicType(type2))
    {
        return strcmp(type1, type2) == 0;
    }

    /* Pointer type comparison */
    if (isPointerType(type1) && isPointerType(type2))
    {
        char base1[20], base2[20];

        strcpy(base1, type1);
        strcpy(base2, type2);

        base1[strlen(base1) - 1] = '\0';
        base2[strlen(base2) - 1] = '\0';

        return strcmp(base1, base2) == 0;
    }

    return 0;
}

int main()
{
    char type1[20], type2[20];

    printf("TYPE EQUIVALENCE CHECKER\n");
    printf("------------------------\n");

    printf("Enter first type  : ");
    scanf("%s", type1);

    printf("Enter second type : ");
    scanf("%s", type2);

    if (equivalent(type1, type2))
        printf("\nResult: Types are EQUIVALENT.\n");
    else
        printf("\nResult: Types are NOT EQUIVALENT.\n");

    return 0;
}

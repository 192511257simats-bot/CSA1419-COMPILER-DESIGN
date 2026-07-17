#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[200];
    int i = 0;

    printf("Enter expression:\n");
    fgets(s, sizeof(s), stdin);

    while (s[i] != '\0')
    {
        if (isalpha(s[i]) || s[i] == '_')
        {
            printf("Identifier : ");
            while (isalnum(s[i]) || s[i] == '_')
            {
                printf("%c", s[i]);
                i++;
            }
            printf("\n");
        }
        else if (isdigit(s[i]))
        {
            printf("Constant : ");
            while (isdigit(s[i]))
            {
                printf("%c", s[i]);
                i++;
            }
            printf("\n");
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
                 s[i] == '/' || s[i] == '=' || s[i] == '%' ||
                 s[i] == '<' || s[i] == '>')
        {
            printf("Operator : %c\n", s[i]);
            i++;
        }
        else
        {
            i++;
        }
    }

    return 0;
}

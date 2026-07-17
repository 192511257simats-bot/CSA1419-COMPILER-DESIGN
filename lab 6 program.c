#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[50];
    int i, valid = 1;

    printf("Enter an identifier: ");
    scanf("%s", s);

    if(!(isalpha(s[0]) || s[0]=='_'))
        valid = 0;

    for(i=1; s[i]!='\0'; i++)
    {
        if(!(isalnum(s[i]) || s[i]=='_'))
        {
            valid = 0;
            break;
        }
    }

    if(valid)
        printf("Valid Identifier");
    else
        printf("Invalid Identifier");

    return 0;
}

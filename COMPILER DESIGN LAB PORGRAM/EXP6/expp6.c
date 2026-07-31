#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char str[])
{
    char keywords[][10] = {
        "int","float","char","double","if","else",
        "while","for","return","void","break","continue"
    };

    int n = sizeof(keywords) / sizeof(keywords[0]);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main()
{
    char id[50];
    int i, valid = 1;

    printf("Enter an Identifier: ");
    scanf("%s", id);

    // Check keyword
    if(isKeyword(id))
    {
        printf("%s is an Invalid Identifier (Keyword).\n", id);
        return 0;
    }

    // First character
    if(!(isalpha(id[0]) || id[0] == '_'))
        valid = 0;

    // Remaining characters
    for(i = 1; id[i] != '\0'; i++)
    {
        if(!(isalnum(id[i]) || id[i] == '_'))
        {
            valid = 0;
            break;
        }
    }

    if(valid)
        printf("%s is a Valid Identifier.\n", id);
    else
        printf("%s is an Invalid Identifier.\n", id);

    return 0;
}

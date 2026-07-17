#include <stdio.h>
#include <string.h>

int main()
{
    char s[200];
    int n;

    printf("Enter a line:\n");
    fgets(s, sizeof(s), stdin);

    n = strlen(s);

    /* Remove newline character if present */
    if (s[n - 1] == '\n')
    {
        s[n - 1] = '\0';
        n--;
    }

    if (s[0] == '/' && s[1] == '/')
    {
        printf("Single-line Comment\n");
    }
    else if (s[0] == '/' && s[1] == '*' &&
             s[n - 2] == '*' && s[n - 1] == '/')
    {
        printf("Multi-line Comment\n");
    }
    else
    {
        printf("Not a Comment\n");
    }

    return 0;
}

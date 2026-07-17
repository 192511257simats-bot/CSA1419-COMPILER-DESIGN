#include <stdio.h>
#include <string.h>

int main()
{
    char s[200];
    int i;

    printf("Enter source code (Type END to stop):\n");

    while (fgets(s, sizeof(s), stdin) != NULL)
    {
        if (strncmp(s, "END", 3) == 0)
            break;

        for (i = 0; s[i] != '\0'; i++)
        {
            /* Skip spaces, tabs, and newlines */
            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
                continue;

            /* Stop printing if single-line comment starts */
            if (s[i] == '/' && s[i + 1] == '/')
                break;

            printf("%c", s[i]);
        }

        printf("\n");
    }

    return 0;
}

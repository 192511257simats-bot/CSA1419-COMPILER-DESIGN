#include <stdio.h>
#include <string.h>

int main()
{
    char line[500];

    printf("Enter a line:\n");
    fgets(line, sizeof(line), stdin);

    if (strncmp(line, "//", 2) == 0)
    {
        printf("It is a Single-Line Comment.\n");
    }
    else if (strncmp(line, "/*", 2) == 0)
    {
        if (strstr(line, "*/") != NULL)
            printf("It is a Multi-Line Comment.\n");
        else
            printf("Starting of a Multi-Line Comment.\n");
    }
    else
    {
        printf("It is NOT a Comment.\n");
    }

    return 0;
}

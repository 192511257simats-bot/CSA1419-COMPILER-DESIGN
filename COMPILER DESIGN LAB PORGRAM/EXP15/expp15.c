#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
    {
        printf("Error: Cannot open file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Count characters
        characters++;

        // Count lines
        if (ch == '\n')
            lines++;

        // Count words
        if (isspace(ch))
        {
            inWord = 0;
        }
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    // If file is not empty, total lines = newline count + 1
    if (characters > 0)
        lines++;

    fclose(fp);

    printf("\nFile Analysis:\n");
    printf("Number of Characters : %d\n", characters);
    printf("Number of Words      : %d\n", words);
    printf("Number of Lines      : %d\n", lines);

    return 0;
}

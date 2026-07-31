#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isOperator(char ch)
{
    char operators[] = "+-*/%=<>!&|^";
    for (int i = 0; operators[i] != '\0'; i++)
    {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;
    char ch, token[50];
    int i;

    fp = fopen("input.c", "r");

    if (fp == NULL)
    {
        printf("Cannot open file.\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Ignore spaces, tabs, and new lines
        if (isspace(ch))
            continue;

        // Ignore single-line comments
        if (ch == '/')
        {
            char next = fgetc(fp);

            if (next == '/')
            {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }

            // Ignore multi-line comments
            else if (next == '*')
            {
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == '*')
                    {
                        if ((ch = fgetc(fp)) == '/')
                            break;
                    }
                }
                continue;
            }
            else
            {
                printf("Operator : /\n");
                fseek(fp, -1, SEEK_CUR);
                continue;
            }
        }

        // Identify Identifier
        if (isalpha(ch) || ch == '_')
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';
            printf("Identifier : %s\n", token);

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }

        // Identify Constant
        else if (isdigit(ch))
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isdigit(ch) || ch == '.'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';
            printf("Constant   : %s\n", token);

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }

        // Identify Operators
        else if (isOperator(ch))
        {
            printf("Operator   : %c\n", ch);
        }
    }

    fclose(fp);

    return 0;
}

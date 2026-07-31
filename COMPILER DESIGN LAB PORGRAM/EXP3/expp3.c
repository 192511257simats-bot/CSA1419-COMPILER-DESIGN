#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char str[])
{
    char keywords[][10] = {
        "int", "float", "char", "if", "else",
        "while", "for", "return", "void", "main"
    };

    int n = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < n; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch)
{
    char op[] = "+-*/=%<>!";

    for (int i = 0; op[i] != '\0'; i++)
    {
        if (ch == op[i])
            return 1;
    }
    return 0;
}

int main()
{
    FILE *fp;
    char ch, token[100];
    int i;

    fp = fopen("input.c", "r");

    if (fp == NULL)
    {
        printf("File not found!\n");
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        // Ignore spaces, tabs and new lines
        if (isspace(ch))
            continue;

        // Ignore comments
        if (ch == '/')
        {
            char next = fgetc(fp);

            // Single-line comment
            if (next == '/')
            {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
                continue;
            }

            // Multi-line comment
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
                printf("Operator   : /\n");
                fseek(fp, -1, SEEK_CUR);
                continue;
            }
        }

        // Identifier or Keyword
        if (isalpha(ch) || ch == '_')
        {
            i = 0;

            while (isalnum(ch) || ch == '_')
            {
                token[i++] = ch;
                ch = fgetc(fp);
            }

            token[i] = '\0';

            if (isKeyword(token))
                printf("Keyword    : %s\n", token);
            else
                printf("Identifier : %s\n", token);

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }

        // Constant
        else if (isdigit(ch))
        {
            i = 0;

            while (isdigit(ch))
            {
                token[i++] = ch;
                ch = fgetc(fp);
            }

            token[i] = '\0';

            printf("Constant   : %s\n", token);

            if (ch != EOF)
                fseek(fp, -1, SEEK_CUR);
        }

        // Operator
        else if (isOperator(ch))
        {
            printf("Operator   : %c\n", ch);
        }
    }

    fclose(fp);

    return 0;
}

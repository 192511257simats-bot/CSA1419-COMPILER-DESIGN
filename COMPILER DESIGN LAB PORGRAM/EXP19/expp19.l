%{
#include <stdio.h>

int characters = 0;
int words = 0;
int lines = 0;
%}

%%
"//".*                  ;                       /* Ignore single-line comments */

"/*"([^*]|\*+[^*/])*\*+"/"     ;               /* Ignore multi-line comments */

\n                      { lines++; }

[ \t]+                  ;                       /* Ignore spaces and tabs */

[A-Za-z_][A-Za-z0-9_]*  { words++; characters += yyleng; }

[0-9]+                  { words++; characters += yyleng; }

.                       { characters++; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    FILE *fp;

    fp = fopen("sample.c", "r");

    if(fp == NULL)
    {
        printf("Cannot open file!\n");
        return 0;
    }

    yyin = fp;
    yylex();

    printf("\nNumber of Characters : %d\n", characters);
    printf("Number of Words      : %d\n", words);
    printf("Number of Lines      : %d\n", lines + 1);

    fclose(fp);

    return 0;
}
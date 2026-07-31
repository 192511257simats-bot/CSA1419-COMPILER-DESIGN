%{
#include<stdio.h>
%}

DIGIT   [0-9]+(\.[0-9]+)?

%%

{DIGIT}      { printf("Constant : %s\n", yytext); }

.|\n         ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    FILE *fp;

    fp = fopen("sample1.c","r");

    if(fp==NULL)
    {
        printf("Cannot open file!\n");
        return 0;
    }

    yyin=fp;

    printf("Constants in the Program:\n\n");

    yylex();

    fclose(fp);

    return 0;
}
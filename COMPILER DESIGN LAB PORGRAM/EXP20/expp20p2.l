%{
#include<stdio.h>

int macro=0;
int header=0;
%}

%%

^#define            { macro++; }

^#include[ ]*<[^>]+>    { header++; }

.|\n                ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    FILE *fp;

    fp=fopen("sample2.c","r");

    if(fp==NULL)
    {
        printf("Cannot open file!\n");
        return 0;
    }

    yyin=fp;

    yylex();

    printf("\nNumber of Macros       : %d\n",macro);
    printf("Number of Header Files : %d\n",header);

    fclose(fp);

    return 0;
}
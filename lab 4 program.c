#include <stdio.h>

int main()
{
    char s[100];
    int i;

    printf("Enter an expression:\n");
    fgets(s, sizeof(s), stdin);

    printf("Operators Found:\n");

    for(i=0; s[i]!='\0'; i++)
    {
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            printf("%c\n", s[i]);
    }

    return 0;
}

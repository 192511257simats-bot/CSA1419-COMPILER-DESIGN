#include <stdio.h>
#include <string.h>

int main()
{
    char s[200];
    int space=0, newline=0, i;

    printf("Enter text (Type END to stop):\n");

    while(fgets(s, sizeof(s), stdin))
    {
        if(strncmp(s, "END", 3) == 0)
            break;

        newline++;

        for(i=0; s[i]!='\0'; i++)
        {
            if(s[i]==' ')
                space++;
        }
    }

    printf("\nWhite Spaces = %d", space);
    printf("\nNew Lines = %d", newline);

    return 0;
}

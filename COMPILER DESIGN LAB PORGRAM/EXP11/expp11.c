#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[20];
    char type[20];
    int address;
};

struct Symbol table[50];
int count = 0;

void insert()
{
    printf("Enter Symbol Name: ");
    scanf("%s", table[count].name);

    printf("Enter Data Type: ");
    scanf("%s", table[count].type);

    table[count].address = 1000 + count;
    count++;

    printf("Symbol Inserted Successfully!\n");
}

void display()
{
    int i;

    if(count == 0)
    {
        printf("Symbol Table is Empty!\n");
        return;
    }

    printf("\n----------------------------------------\n");
    printf("Name\t\tType\t\tAddress\n");
    printf("----------------------------------------\n");

    for(i = 0; i < count; i++)
    {
        printf("%s\t\t%s\t\t%d\n",
               table[i].name,
               table[i].type,
               table[i].address);
    }
}

void search()
{
    char key[20];
    int i, found = 0;

    printf("Enter Symbol to Search: ");
    scanf("%s", key);

    for(i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, key) == 0)
        {
            printf("\nSymbol Found!\n");
            printf("Name    : %s\n", table[i].name);
            printf("Type    : %s\n", table[i].type);
            printf("Address : %d\n", table[i].address);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Symbol Not Found!\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n===== SYMBOL TABLE =====\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                display();
                break;

            case 3:
                search();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

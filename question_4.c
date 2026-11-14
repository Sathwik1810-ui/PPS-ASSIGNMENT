#include <stdio.h>
#include <string.h>

#define SIZE 32

int readLine(char str[SIZE])
{
    int ch;
    size_t len;

    if (fgets(str, SIZE, stdin) == NULL)
        return 0;

    len = strlen(str);

    if (len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        return 1;
    }

    ch = getchar();

    if (ch == '\n' || ch == EOF)
        return 1;

    while (ch != '\n' && ch != EOF)
        ch = getchar();

    return 0;
}

int main()
{
    char title[SIZE];
    char citation[SIZE];

    printf("Enter book title: ");

    if (!readLine(title))
    {
        printf("Title too long.\n");
        return 1;
    }

    printf("Enter citation: ");

    if (!readLine(citation))
    {
        printf("Citation too long.\n");
        return 1;
    }

    if (strcmp(title, citation) == 0)
        printf("Exact match found.\n");
    else
        printf("Strings are different.\n");

    return 0;
}
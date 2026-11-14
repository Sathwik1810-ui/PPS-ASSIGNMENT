#include <stdio.h>

#define SENTINEL -9999
#define MAX_RECORDS 100

int main()
{
    int id, issueDate, returnDate;
    int count = 0;
    int totalFine = 0;
    int i;

    for (i = 0; i < MAX_RECORDS; i++)
    {
        printf("Enter book ID: ");

        if (scanf("%d", &id) != 1)
        {
            printf("Invalid input.\n");
            break;
        }

        if (id == SENTINEL)
            break;

        printf("Enter issue date and return date: ");

        if (scanf("%d %d", &issueDate, &returnDate) != 2)
        {
            printf("Invalid record.\n");
            continue;
        }

        if (returnDate < issueDate)
        {
            printf("Record rejected: Invalid dates.\n");
            continue;
        }

        /* Update totals only after validation */
        count++;

        printf("Record accepted.\n");
    }

    printf("Valid records: %d\n", count);
    printf("Total fine: %d\n", totalFine);

    return 0;
}
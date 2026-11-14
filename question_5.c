#include <stdio.h>

#define SUCCESS 0
#define ERR_NEGATIVE_DAYS 1
#define ERR_NULL_POINTER 2

#define NOT_DUE 0
#define DUE 1
#define UNKNOWN -1

int calculateFine(int days, double *amount)
{
    if (amount == NULL)
        return ERR_NULL_POINTER;

    *amount = 0.0;

    if (days < 0)
        return ERR_NEGATIVE_DAYS;

    if (days <= 3)
        *amount = days * 2;
    else
        *amount = 10;

    return SUCCESS;
}

int loanCheck(int days, double *amount, int *dueState)
{
    int error;

    if (amount == NULL || dueState == NULL)
        return ERR_NULL_POINTER;

    *amount = 0.0;
    *dueState = UNKNOWN;

    if (days < 0)
        return ERR_NEGATIVE_DAYS;

    *dueState = (days > 0) ? DUE : NOT_DUE;

    error = calculateFine(days, amount);

    return error;
}

int main()
{
    double amount;
    int dueState;
    int error;

    error = loanCheck(4, &amount, &dueState);

    if (error == SUCCESS)
    {
        printf("Fine amount: %.2f\n", amount);
        printf("Due state: %d\n", dueState);
    }
    else
    {
        printf("Error code: %d\n", error);
    }

    return 0;
}
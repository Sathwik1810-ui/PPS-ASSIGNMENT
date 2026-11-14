#include <stdio.h>

#define SIZE 8
#define MISSING -1

int main()
{
    int a[SIZE][SIZE] = {
        {2, 0, 3, -1, 4, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, -1, -1, -1, -1, -1, -1}
    };

    int i, j, count;

    for (i = 0; i < SIZE; i++)
    {
        count = 0;

        for (j = 0; j < SIZE; j++)
        {
            if (a[i][j] != MISSING)
            {
                count++;
            }
        }

        printf("Row %d: Valid cells = %d\n", i, count);
    }

    return 0;
}
#include "process.h"

int process(FILE *f, int *count)
{
    int rc = 0, num;
    int x1, x2, x3;

    if (fscanf(stdin, "%d", &x1) != 1)
    {
        rc = INCORRECT_INPUT;
        return rc;
    }

    if (fscanf(stdin, "%d", &x2) != 1)
    {
        rc = INCORRECT_INPUT;
        return rc;
    }

    if (fscanf(stdin, "%d", &x3) != 1)
    {
        rc = INCORRECT_INPUT;
        return rc;
    }

    if (x2 > x1 && x2 > x3)
        (*count)++;

    while (fscanf(stdin, "%d", &num) == 1)
    {
        x1 = x2;
        x2 = x3;
        x3 = num;
        if (x2 > x1 && x2 > x3)
            (*count)++;
    }
    return rc;
}

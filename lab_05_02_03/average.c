#include "average.h"

int process1(FILE *f, float *sr, int *k)
{
    float num, sum = 0;
    while (fscanf(f, "%f", &num) == 1)
    {
        sum += num;
        (*k)++;
    }
    if ((*k) > 0)
    {
        *sr = sum / (*k);
        fseek(f, 0, 0);
        return OK;
    }
    else
        return INCORRECT_DATA;
}

#include "rule_check.h"

int process2(FILE *f, float sr, int *k)
{
    if (*k == 1)
        return YES;
    float sum = 0, num, d;
    while (fscanf(f, "%f", &num) == 1)
        sum += (num - sr) * (num - sr);
    d = sqrt(sum / ((*k) - 1));
    float a = sr - 3 * d;
    float b = sr + 3 * d;
    fseek(f, 0, 0);
    while (fscanf(f, "%f", &num) == 1)
        if (num >= b || num <= a)
            return NO;
    return YES;
}

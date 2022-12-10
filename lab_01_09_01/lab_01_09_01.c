#include <stdio.h>
#include <math.h>

double new_member(double x, int n)
{
    return sqrt(x / n);
}

int main(void)
{
    double g, sum = 0, x, nm;
    int rc, n = 0;
    rc = scanf("%lf", &x);
    if (rc != 1)
    {
        printf("Input error\n");
        return 1;
    }
    if (x < 0)
    {
        printf("Input one negative number\n");
        return 2;
    }
    while (x >= 0)
    {
        n = n + 1;
        nm = new_member(x, n);
        sum = sum + nm;
        rc = scanf("%lf", &x);
        if (rc != 1)
        {
            printf("Input error\n");
            return 1;
        }
    }
    g = sin(sum);
    printf("g = %.6lf", g);
    return 0;
}

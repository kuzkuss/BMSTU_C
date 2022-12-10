#include <stdio.h>
#include <math.h>
double approximation(double x, double eps)
{
    int n = 1, k = 2;
    double q, s = 0.0;
    q = x;
    while (fabs(q) >= eps)
    {
        s = s + q * n;
        q = q * x * x / k / (k + 1);
        k = k + 2;
        n = n * (-1);
    }
    return s;
}
int main(void)
{
    double x, e, s, f, d, b;
    int rcx, rce;
    rcx = scanf("%lf", &x);
    if (rcx != 1)
    {
        printf("Input error\n");
        return 1;
    }
    rce = scanf("%lf", &e);
    if (rce != 1)
    {
        printf("Input error\n");
        return 1;
    }
    if (e <= 0 || e > 1)
    {
        printf("Incorrect precision entered\n");
        return 2;
    }
    f = sin(x);
    s = approximation(x, e);
    d = fabs(f - s);
    b = d / fabs(f);
    printf("Approximate function value: %.6lf\n", s);
    printf("Exact function value: %.6lf\n", f);
    printf("Absolute error: %.6lf\n", d);
    printf("Relative error: %.6lf\n", b);
    return 0;
}

#include <stdio.h>
#include <math.h>
double line_length(double x1, double y1, double x2, double y2)
{
    double len;
    len = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return len;
}

int main(void)
{
    double x1, x2, x3, y1, y2, y3, a, b, c, p, s;
    int rc1, rc2, rc3;
    rc1 = scanf("%lf%lf", &x1, &y1);
    if (rc1 != 2)
    {
        printf("Input error");
        return 1;
    }
    rc2 = scanf("%lf%lf", &x2, &y2);
    if (rc2 != 2)
    {
        printf("Input error");
        return 1;
    }
    rc3 = scanf("%lf%lf", &x3, &y3);
    if (rc3 != 2)
    {
        printf("Input error");
        return 1;
    }
    a = line_length(x1, y1, x2, y2);
    b = line_length(x2, y2, x3, y3);
    c = line_length(x1, y1, x3, y3);
    if (a + b <= c || c + b <= a || a + c <= b)
    {
        printf("Triangle doesn't exist");
        return 2;
    }
    p = (a + b + c) / 2;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("The area of the triangle is %.6lf\n", s);
    return 0;
}

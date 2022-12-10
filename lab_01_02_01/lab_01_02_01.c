#include <stdio.h>
#include <math.h>
#define PI 3.14159
int main(void)
{
    float a, b, s, f;
    scanf("%f%f", &a, &b);
    scanf("%f", &f);
    s = fabs((b * b - a * a) / 4 * tan(f / 180 * PI));
    printf("The area of the trapezoid is %.6f", s);
    return 0;
}

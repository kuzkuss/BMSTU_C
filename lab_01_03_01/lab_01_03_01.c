#include <stdio.h>
int main(void)
{
    float t1, v1, t2, v2, t, v;
    scanf("%f%f", &v1, &t1);
    scanf("%f%f", &v2, &t2);
    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;
    printf("Volume of the resulting mixture: %.6f\n", v);
    printf("Temperature of the resulting mixture: %.6f\n", t);
    return 0;
}

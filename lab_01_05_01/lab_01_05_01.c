#include <stdio.h>
int delete_function(int x, int y)
{
    int z = 0;
    while (x >= 0)
    {
        x = x - y;
        z = z + 1;
    }
    return z - 1;
}

int main(void)
{
    int a, d, q, r, rc;
    rc = scanf("%d%d", &a, &d);
    if (rc != 2)
    {
        printf("Input error\n");
        return 1;
    }
    if (a <= 0 || d <= 0)
    {
        printf("Incorrect input\n");
        return 2;
    }
    q = delete_function(a, d);
    r = a - d * q;
    printf("Quotient: %d\n", q);
    printf("Remainder: %d\n", r);
    return 0;
}
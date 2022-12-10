#include <stdio.h>
#define INPUT_ERROR 1
#define ODD_ELEMENTS_ERROR 2
#define NUMBER_OF_ELEMENTS_ERROR 3

int scan_array(int *array, int n)
{
    char tmp;
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &array[i]) != 1)
        {
            printf("Input error.\n");
            return INPUT_ERROR;
        }
    }
    if (scanf("%c", &tmp) != EOF)
    {
        printf("Number of array elements exceeded.\n");
        return INPUT_ERROR;
    }
    return 0;
}

int product_of_odd(int *array, int n)
{
    int p = 1, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] % 2 != 0)
        {
            p *= array[i];
            count += 1;
        }
    }
    if (count == 0)
    {
        printf("No odd elements.\n");
        return ODD_ELEMENTS_ERROR;
    }
    return p;
}

int main(void)
{
    int n, array[10], p;

    if (scanf("%d", &n) != 1)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }

    if (n > 10 || n <= 0)
    {
        printf("Incorrect entry of the number of elements.\n");
        return NUMBER_OF_ELEMENTS_ERROR;
    }

    if (scan_array(array, n) == INPUT_ERROR)
        return INPUT_ERROR;

    p = product_of_odd(array, n);

    if (p == ODD_ELEMENTS_ERROR)
        return ODD_ELEMENTS_ERROR;

    printf("Product of odd elements = %d\n", p);
    return 0;
}

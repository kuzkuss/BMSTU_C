#include <stdio.h>
#define INPUT_ERROR 1
#define NUMBER_OF_ELEMENTS_ERROR 2

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

int fib(int *fib1, int *fib2)
{
    int res;
    res = *fib1 + *fib2;
    *fib1 = *fib2;
    *fib2 = res;
    return res;
}

int processing_array(int *array, int *n)
{
    int fib1 = 0, fib2 = 1, count = 0;
    for (int i = 0; i < *n; i++)
    {
        if (array[i] % 3 == 0)
        {
            *n += 1;

            for (int j = *n; j > i + 1; j--)
                array[j] = array[j - 1];
            if (count != 0 && count != 1)
                array[i + 1] = fib(&fib1, &fib2);
            else if (count == 0)
                array[i + 1] = 0;
            else
                array[i + 1] = 1;
            count += 1;
            i += 1;
        }
    }
    return 0;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
}

int main(void)
{
    int array[20], n;

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

    if (scan_array(array, n) != 0)
        return INPUT_ERROR;

    processing_array(array, &n);
    print_array(array, n);
    return 0;
}

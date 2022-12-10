#include <stdio.h>
#define ARRAY_OVERFLOW_ERROR 100
#define EMPTY_ARRAY_ERROR 1

int scan_array(int *array)
{
    int i = 0;

    while (scanf("%d", &array[i]) == 1)
    {
        i += 1;
        if (i == 11)
            return i;
    }

    return i;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
}

void insertion_sort(int *array, int n)
{
    for (int i = 1; i < n; i++)
    {
        int cur = array[i];
        int j = i - 1;

        while (j >= 0 && cur < array[j])
        {
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = cur;
    }
}

int main(void)
{
    int array[11], n;

    n = scan_array(array);

    if (n == 11)
    {
        insertion_sort(array, n - 1);
        print_array(array, n - 1);
        return ARRAY_OVERFLOW_ERROR;
    }

    if (n == 0)
    {
        printf("Empty array.\n");
        return EMPTY_ARRAY_ERROR;
    }

    insertion_sort(array, n);

    print_array(array, n);

    return 0;
}

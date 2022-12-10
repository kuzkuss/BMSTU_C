#include <stdio.h>
#define INPUT_ERROR 1

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
    int n;

    if (scanf("%d", &n) != 1)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }

    int array[n];

    if (scan_array(array, n) == INPUT_ERROR)
            return INPUT_ERROR;

    insertion_sort(array, n);

    print_array(array, n);

    return 0;
}

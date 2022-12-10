#include <stdio.h>
#define INPUT_ERROR 1
#define NUMBER_OF_ELEMENTS_ERROR 2
#define PRIME_ELEMENTS_ERROR 3

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

int is_prime(int x)
{
    if (x > 1)
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return 1;
        }
        return 0;
    }

    return 1;
}

int new_array(int *array1, int n, int *array2)
{
    int j = 0;
    for (int i = 0; i < n; i ++)
    {
        if (is_prime(array1[i]) == 0)
        {
            array2[j] = array1[i];
            j += 1;
        }
    }
    return j;
}

void print_array(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}

int main(void)
{
    int array1[10], n;

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

    if (scan_array(array1, n) != 0)
        return INPUT_ERROR;

    int array2[10], j;

    j = new_array(array1, n, array2);

    if (j == 0)
    {
        printf("There are no prime numbers in the original array.\n");
        return PRIME_ELEMENTS_ERROR;
    }

    print_array(array2, j);

    return 0;
}

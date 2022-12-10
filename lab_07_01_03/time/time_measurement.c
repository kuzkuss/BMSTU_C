#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define INPUT_ERROR 1
#define MALLOC_ERR 2
#define N 1000

int comp_int(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    int last_odd = num - 1;
    int last_even = 0;
    for (int i = 0; i < num - 1; ++i)
    {
        if (i % 2)
        {
            int cur_last = num - 1;
            for (int j = last_even; j < last_odd; ++j)
                if (compare((char *) base + size * j, (char *) base + size * (j + 1)) > 0)
                {
                    char tmp;
                    for (int byte = 0; byte < size; ++byte)
                    {
                        tmp = *((char *) base + size * j + byte);
                        *((char *) base + size * j + byte) = *((char *) base + size * (j + 1) + byte);
                        *((char *) base + size * (j + 1) + byte) = tmp;
                    }
                    cur_last = j;
                }
            last_odd = cur_last;
            if (last_odd == num - 1)
                break;
        }
        else
        {
            int cur_last = 0;
            for (int j = last_odd; j > last_even; --j)
            {
                if (compare((char *) base + size * (j - 1), (char *) base + size * j) > 0)
                {
                    char tmp;
                    for (int byte = 0; byte < size; ++byte)
                    {
                        tmp = *((char *) base + size * (j - 1) + byte);
                        *((char *) base + size * (j - 1) + byte) = *((char *) base + size * j + byte);
                        *((char *) base + size * j + byte) = tmp;
                    }
                    cur_last = j;
                }
            }
            last_even = cur_last;
            if (last_even == 0)
                break;
        }
    }
}

void forming_array(int *pb, int *pe)
{
    srand(time(NULL));
    for (int *pa = pb; pa < pe; pa++)
        *pa = rand() % 100;
}

void time_func(int *arr, int *arr_copy, double *time, int size, void (*ptr_func)(void *base, size_t num, size_t size, int (*compare)(const void *, const void *)))
{
    double sum = 0.0;
    for (int i = 1; i < N; i++)
    {
        for (int i = 0; i < size; i++)
            arr_copy[i] = arr[i];
        clock_t start = clock();
        ptr_func(arr_copy, size, sizeof(int), comp_int);
        clock_t finish = clock();
        sum += finish - start;
    }
    *time = sum / N;
}

int main(void)
{
    setbuf(stdout, NULL);
    int size;

    srand(time(0));
    printf("Enter size of array: \n");
    if (scanf("%d", &size) != 1)
    {
        printf("Input error.\n");
        return INPUT_ERROR;
    }

    int *arr = malloc(size * sizeof(int));
    int *arr_copy = malloc(size * sizeof(int));

    if (!arr || !arr_copy)
    {
        printf("Malloc error.\n");
        return MALLOC_ERR;
    }

    forming_array(arr, arr + size);

    double time_mysort = 0.0;
    double time_qsort = 0.0;

    time_func(arr, arr_copy, &time_mysort, size, mysort);
    time_func(arr, arr_copy, &time_qsort, size, qsort);

    printf("time of mysort: %lf us\n", time_mysort / CLOCKS_PER_SEC * 1000000);
    printf("time of qsort: %lf us\n", time_qsort / CLOCKS_PER_SEC * 1000000);

    return 0;
}


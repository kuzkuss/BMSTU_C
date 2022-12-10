#include <stdlib.h>
#include "check_prime.h"
#include "errors.h"

static int is_prime(int n);
static int *find_prime(Matrix *matrix, int *amount_prime);
static void sort(int *arr, int n);

static int is_prime(int n)
{
    int res = TRUE;

    if (n < 2)
        return FALSE;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0) {
            res = FALSE;
            break;
        }
    }

    return res;
}

static int *find_prime(Matrix *matrix, int *amount_prime)
{
    int *arr_prime = malloc(matrix->rows * matrix->columns * sizeof(int));
    if (!arr_prime)
        return NULL;

    for (int i = 0; i < matrix->rows; ++i)
        for (int j = 0; j < matrix->columns; ++j)
            if (is_prime(matrix->prows[i][j]))
            {
                arr_prime[*amount_prime] = matrix->prows[i][j];
                (*amount_prime)++;
            }

    if (*amount_prime == 0)
    {
        free(arr_prime);
        return NULL;
    }

    return arr_prime;
}

static void sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int min = arr[i];
        int min_ind = i;
        for (int j = i + 1; j < n; ++j)
        {
            int cur_min = arr[j];
            if (cur_min < min)
            {
                min_ind = j;
                min = cur_min;
            }
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }
}

int change_primers(Matrix *matrix)
{
    int amount = 0;
    int *arr_prime = find_prime(matrix, &amount);
    if (!arr_prime)
        return NO_PRIME;

    sort(arr_prime, amount);

    int index_arr = 0;

    for (int i = 0; i < matrix->rows; ++i)
        for (int j = 0; j < matrix->columns; ++j)
            if (is_prime(matrix->prows[i][j]))
            {
                matrix->prows[i][j] = arr_prime[index_arr];
                index_arr++;
            }

    free(arr_prime);

    return OK;
}

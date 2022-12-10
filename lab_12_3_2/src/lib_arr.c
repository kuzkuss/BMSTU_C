#include "lib_arr.h"

static int is_prime(int n);

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

ARR_DLL void ARR_DECL fill_primes(int *arr, int n)
{
    int prime = 2;
    for (int i = 0; i < n; i++)
    {
        arr[i] = prime;
        prime++;
        while(!is_prime(prime))
            prime++;
    }
}

ARR_DLL int ARR_DECL filter(int *src, int src_len, int *dst, int *dst_len, int value)
{
    int n = src_len;

    for (int i = 0; i < src_len; i++)
        if (src[i] % 2 == 0)
            n++;

    if (n > *dst_len)
    {
        *dst_len = n;
        return OVERFLOW_ARRAY;
    }

    n = 0;
    for (int i = 0; i < src_len; i++)
    {
        dst[n] = src[i];
        if (src[i] % 2 == 0)
        {
            n++;
            dst[n] = value;
        }
        n++;
    }

    *dst_len = n;

    return 0;
}

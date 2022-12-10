#include "errors.h"
#include "process_array_stat.h"

int key(const int *pb_src, const int *pe_src, int *pb_dst, int *pe_dst, int *dst_len)
{
    if (!pb_src || !pe_src)
        return INCORRECT_DATA;
    int n = 0;
    const int *p_cur = pe_src - 1;
    while (p_cur >= pb_src && *p_cur >= 0)
        --p_cur;
    if (p_cur == pb_src)
        return EMPTY_ARRAY;
    n = p_cur - pb_src;
    if (n == -1)
        n = pe_src - pb_src;
    if (n > *dst_len)
    {
        *dst_len = n;
        return OVERFLOW_ARRAY;
    }
    *dst_len = n;
    for (int *pc_dst = pb_dst; pc_dst < pe_dst; ++pc_dst, ++pb_src)
        *pc_dst = *pb_src;
    return OK;
}


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

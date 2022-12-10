#include "mysort.h"

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

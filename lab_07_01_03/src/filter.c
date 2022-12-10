#include "filter.h"
#include "cdio.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
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
    if (create_array(pb_dst, pe_dst, n) != OK)
        return MALLOC_FAIL;
    for (int *pc_dst = *pb_dst; pc_dst < *pe_dst; ++pc_dst, ++pb_src)
        *pc_dst = *pb_src;
    return OK;
}

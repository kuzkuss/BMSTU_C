#include <stdlib.h>

#include "create_delete.h"
#include "errors.h"

void delete_array(int **arr_b, int **arr_e)
{
    free(*arr_b);
    *arr_b = NULL;
    *arr_e = NULL;
}

int create_array(int **arr_b, int **arr_e, int n)
{
    if (!(*arr_b = malloc(sizeof(int) * n)))
    {
        delete_array(arr_b, arr_e);
        return MALLOC_FAIL;
    }
    *arr_e = (*arr_b) + n;
    return OK;
}

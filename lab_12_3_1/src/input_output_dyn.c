#include "input_output_dyn.h"
#include "errors.h"

ARR_DLL int ARR_DECL input_array(FILE *f_in, int **arr_beg, int **arr_end)
{
    fseek(f_in, 0L, SEEK_SET);
    for (int *arr_cur = *arr_beg; arr_cur < *arr_end; ++arr_cur)
        if (fscanf(f_in, "%d", arr_cur) != 1)
            return INPUT_ERROR;
    return OK;
}

ARR_DLL int ARR_DECL output_array(const char *filename, int *arr_beg, const int *arr_end)
{
    FILE *f_out;
    if (!(f_out = fopen(filename, "w")))
        return FILE_ERR;
    for (int *arr_cur = arr_beg; arr_cur < arr_end; ++arr_cur)
        fprintf(f_out, "%d ", *arr_cur);
    fclose(f_out);
    return OK;
}

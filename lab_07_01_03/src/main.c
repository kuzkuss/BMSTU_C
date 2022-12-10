#include <stdio.h>
#include <string.h>
#include "mysort.h"
#include "cdio.h"
#include "filter.h"

#define KEY_ERROR 2
#define EMPTY_FILE 6

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    if ((argc != 3 && argc != 4) || (argc == 4 && (strcmp(argv[3], "f") != 0)))
        return KEY_ERROR;
    FILE *f_in;
    if (!(f_in = fopen(argv[1], "r")))
        return FILE_ERR;
    int amount = 0;
    int cur_el;
    while (fscanf(f_in, "%d", &cur_el) == 1)
        ++amount;
    if (!feof(f_in))
        return INPUT_ERROR;
    if (amount == 0)
        return EMPTY_FILE;
    int *arr_beg = NULL;
    int *arr_end = NULL;
    if (create_array(&arr_beg, &arr_end, amount) != OK)
    {
        delete_array(&arr_beg, &arr_end);
        return MALLOC_FAIL;
    }
    if (input_array(f_in, &arr_beg, &arr_end) != OK)
    {
        delete_array(&arr_beg, &arr_end);
        return INPUT_ERROR;
    }
    fclose(f_in);
    int *new_arr_beg = NULL;
    int *new_arr_end = NULL;
    if (argc == 4)
    {
        int rc = key(arr_beg, arr_end, &new_arr_beg, &new_arr_end);
        delete_array(&arr_beg, &arr_end);
        if (rc != OK)
            return rc;
        amount = new_arr_end - new_arr_beg;
    }
    else
    {
        new_arr_beg = arr_beg;
        new_arr_end = arr_end;
    }
    mysort(new_arr_beg, amount, sizeof(int), comp_int);
    if (output_array(argv[2], new_arr_beg, new_arr_end) != OK)
    {
        delete_array(&new_arr_beg, &new_arr_end);
        return FILE_ERR;
    }
    delete_array(&new_arr_beg, &new_arr_end);
    return OK;
}

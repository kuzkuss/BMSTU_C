#include <string.h>
#include <windows.h>

#include "create_delete.h"
#include "errors.h"
#include "input_output_dyn.h"
#include "process_array_dyn.h"

#define ERR_LOAD_LIB 9
#define ERR_LOAD_FUNC 10

typedef int (__cdecl *fn_key_t)(const int *, const int *, int *, int *, int *);
typedef void (__cdecl *fn_mysort_t)(void *, size_t, size_t, int (*)(const void *, const void *));
typedef int (__cdecl *fn_compare_int_t)(const void *, const void *);

typedef int (__cdecl *fn_input_t)(FILE *, int **, int **);
typedef int (__cdecl *fn_output_t)(const char *, int *, const int *);

int main(int argc, char **argv)
{
    if ((argc != 3 && argc != 4) || (argc == 4 && (strcmp(argv[3], "f") != 0)))
        return KEY_ERROR;

    HMODULE lib_arr;
    fn_key_t key;
    fn_mysort_t mysort;
    fn_compare_int_t compare_int;

    fn_input_t input;
    fn_output_t output;

    lib_arr = LoadLibrary("libarr.dll");
    if (!lib_arr)
    {
        printf("Cannot open library.\n");
        return ERR_LOAD_LIB;
    }

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

    input = (fn_input_t) GetProcAddress(lib_arr, "input_array");
    if (!input)
    {
        printf("Can not load function.\n");
        return ERR_LOAD_FUNC;
    }

    if (input(f_in, &arr_beg, &arr_end) != OK)
    {
        delete_array(&arr_beg, &arr_end);
        return INPUT_ERROR;
    }
    fclose(f_in);

    int *new_arr_beg = NULL;
    int *new_arr_end = NULL;
    int new_len = 0;

    if (argc == 4)
    {
        key = (fn_key_t) GetProcAddress(lib_arr, "key");
        if (!key)
        {
            printf("Can not load function.\n");
            return ERR_LOAD_FUNC;
        }
        int rc = key(arr_beg, arr_end, new_arr_beg, new_arr_end, &new_len);

        if (rc == OVERFLOW_ARRAY)
        {
            rc = create_array(&new_arr_beg, &new_arr_end, new_len);
            if (rc == OK)
                rc = key(arr_beg, arr_end, new_arr_beg, new_arr_end, &new_len);
        }

        delete_array(&arr_beg, &arr_end);

        if (rc != OK)
        {
            delete_array(&new_arr_beg, &new_arr_end);
            return rc;
        }

        amount = new_arr_end - new_arr_beg;
    }
    else
    {
        new_arr_beg = arr_beg;
        new_arr_end = arr_end;
    }

    mysort = (fn_mysort_t) GetProcAddress(lib_arr, "mysort");
    compare_int = (fn_compare_int_t) GetProcAddress(lib_arr, "comp_int");
    if (!mysort || !compare_int)
    {
        printf("Can not load function.\n");
        return ERR_LOAD_FUNC;
    }
    mysort(new_arr_beg, amount, sizeof(int), compare_int);

    output = (fn_output_t) GetProcAddress(lib_arr, "output_array");
    if (!output)
    {
        printf("Can not load function.\n");
        return ERR_LOAD_FUNC;
    }
    if (output(argv[2], new_arr_beg, new_arr_end) != OK)
    {
        delete_array(&new_arr_beg, &new_arr_end);
        return FILE_ERR;
    }

    delete_array(&new_arr_beg, &new_arr_end);
    FreeLibrary(lib_arr);
    return OK;
}

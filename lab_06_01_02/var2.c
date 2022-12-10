#include <stdio.h>
#include <string.h>
#include "var2.h"

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return KEY_ERROR;
    FILE *f_in;
    if (!(f_in = fopen(argv[1], "r")))
        return FILE_ERROR;
    struct subjects subjects_array[SIZE_ARRAY];
    int i = 0;
    int rc = read_array(f_in, &i, subjects_array);
    if (i == 0)
    {
        fclose(f_in);
        return EMPTY_FILE;
    }
    if (rc == INPUT_ERROR)
    {
        fclose(f_in);
        return INPUT_ERROR;
    }
    else if (rc == EMPTY_STRING)
    {
        fclose(f_in);
        return EMPTY_STRING;
    }
    else if (rc == ARRAY_OVERFLOW)
    {
        fclose(f_in);
        return ARRAY_OVERFLOW;
    }
    if (argc == 2)
    {
        sort(subjects_array, &i);
        print_array(subjects_array, &i, "ALL");
    }
    else
        print_array(subjects_array, &i, argv[2]);
    fclose(f_in);
    return STABLE_WORK;
}


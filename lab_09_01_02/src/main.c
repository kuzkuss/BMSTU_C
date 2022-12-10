#include <stdio.h>
#include "errors.h"
#include "subject.h"
#include "subjects_array.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3)
        return KEY_ERROR;
    FILE *f_in;
    if (!(f_in = fopen(argv[1], "r")))
        return FILE_ERROR;
    int amount = 0;
    int rc = OK;
    struct subject_t **subjects_array = create_array(f_in, &amount);
    if (!subjects_array)
        rc = ALLOCATE_ERROR;

    if (rc == OK)
    {
        rc = read_array(f_in, subjects_array);
        if (rc == OK)
        {
            if (argc == 2)
            {
                if (sort(subjects_array, amount, cmp_by_density) == OK)
                    print_array(subjects_array, &amount, "ALL");
                else
                    rc = ALLOCATE_ERROR;
            }
            else
                print_array(subjects_array, &amount, argv[2]);
        }
        free_array(subjects_array, amount);
    }
    fclose(f_in);
    return rc;
}


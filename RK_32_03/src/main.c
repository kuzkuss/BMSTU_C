#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "list.h"
#include "student.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    if (argc < 3 || argc > 5)
    {
        print_errors(KEY_ERROR);
        return KEY_ERROR;
    }

    if (strcmp(argv[2], "list") != 0 && argc == 3)
    {
        print_errors(INCORRECT_ARG);
        return INCORRECT_ARG;
    }

    if (argc == 5 && strcmp(argv[3], "form") != 0)
    {
        print_errors(INCORRECT_ARG);
        return INCORRECT_ARG;
    }

    FILE *f_in = fopen(argv[1], "r");
    if (!f_in)
    {
        print_errors(FILE_ERROR);
        return FILE_ERROR;
    }

    int rc = OK;

    node_t *list = read_list(f_in, &rc);

    fclose(f_in);

    if (list)
    {
        if (strcmp(argv[2], "list") == 0 && argc == 3)
        {
            print_list(list);
            free_list(list);
        }
        else if (strcmp(argv[3], "form") == 0)
        {
            node_t *new_list = form(list, argv[4]);
            if (!new_list)
                rc = EMPTY_LIST;

            if (new_list)
            {
                FILE *f_out = fopen(argv[2], "w");
                if (f_out)
                {
                    print_list_to_file(f_out, new_list);
                    fclose(f_out);
                }
                else
                    rc = FILE_ERROR;
                free_list(new_list);
            }
            free_list(list);
        }
    }

    else if (!list && rc == OK)
    {
        print_errors(EMPTY_FILE);
        rc = EMPTY_FILE;
    }

    if (rc)
    {
        print_errors(rc);
    }

    return rc;
}

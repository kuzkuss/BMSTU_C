#include <stdio.h>
#include "matrix.h"
#include "errors.h"
#include "check_prime.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        puts("Incorrect arguments.\n");
        return INCORRECT_ARGS;
    }

    Matrix *matrix = NULL;
    int rc = create_matrix_from_file(argv[1], &matrix);
    if (rc == FILE_ERROR)
    {
        puts("File error.\n");
        return rc;
    }

    if (rc == DIM_ERROR)
    {
        puts("Dimension error.\n");
        return rc;
    }

    if (rc == ALLOCATE_ERROR)
    {
        puts("Allocate error.\n");
        return rc;
    }

    if (rc == INPUT_ERROR)
    {
        puts("Input error.\n");
        return rc;
    }

    rc = change_primers(matrix);

    if(rc == NO_PRIME)
    {
        printf("No primes.\n");
        return NO_PRIME;
    }

    print_matrix(matrix);

    free_matrix(matrix);
    return OK;
}


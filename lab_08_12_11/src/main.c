#include <stdio.h>
#include <string.h>
#include "errors.h"
#include "cdio.h"
#include "addition.h"
#include "multiplication.h"
#include "calc_determinant.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    if (argc < 4 || argc > 5)
        return KEY_ERROR;

    int rc = 0;

    double **matrix_1 = NULL;
    double **matrix_2 = NULL;

    int n1 = 0;
    int m1 = 0;

    matrix_1 = input_matrix(argv[2], &n1, &m1, &rc);
    if (!matrix_1)
        return rc;

    int n2 = 0;
    int m2 = 0;
    if (argc == 5)
    {
        matrix_2 = input_matrix(argv[3], &n2, &m2, &rc);
        if (!matrix_2)
        {
            delete_matrix(matrix_1, n1);
            return rc;
        }
    }

    if (strcmp(argv[1], "a") == 0)
    {
        if (n1 != n2 || m1 != m2)
        {
            delete_matrix(matrix_1, n1);
            delete_matrix(matrix_2, n2);
            return DIM_ERROR;
        }
        double **result = addition(matrix_1, matrix_2, n1, m1);
        if (!result)
        {
            delete_matrix(matrix_1, n1);
            delete_matrix(matrix_2, n2);
            return ALLOCATE_ERROR;
        }
        if (output_matrix(argv[4], result, n1, m1) != OK)
        {
            delete_matrix(matrix_1, n1);
            delete_matrix(matrix_2, n2);
            delete_matrix(result, n1);
            return FILE_OPEN_ERROR;
        }
        delete_matrix(matrix_1, n1);
        delete_matrix(matrix_2, n2);
        delete_matrix(result, n1);
    }
    else if (strcmp(argv[1], "m") == 0)
    {
        if (m1 != n2)
        {
            delete_matrix(matrix_1, n1);
            delete_matrix(matrix_2, n2);
            return DIM_ERROR;
        }
        double **result = multiplication(matrix_1, matrix_2, n1, m1, m2);
        if (!result)
        {
            delete_matrix(matrix_1, n1);
            delete_matrix(matrix_2, n2);
            return ALLOCATE_ERROR;
        }
        if (output_matrix(argv[4], result, n1, m2) != OK)
        {
            delete_matrix(matrix_1, n1);
            delete_matrix(matrix_2, n2);
            delete_matrix(result, n1);
            return FILE_OPEN_ERROR;
        }
        delete_matrix(matrix_1, n1);
        delete_matrix(matrix_2, n2);
        delete_matrix(result, n1);
    }
    else if (strcmp(argv[1], "o") == 0)
    {
        double result;
        if (n1 != m1)
        {
            delete_matrix(matrix_1, n1);
            return DIM_ERROR;
        }

        rc = 0;

        result = calc_determinant(matrix_1, n1, &rc);

        if (rc)
        {
            delete_matrix(matrix_1, n1);
            return ALLOCATE_ERROR;
        }

        FILE *f_out = fopen(argv[3], "w");
        if (!f_out)
        {
            delete_matrix(matrix_1, n1);
            return FILE_OPEN_ERROR;
        }
        fprintf(f_out, "%lf", result);
        fclose(f_out);
        delete_matrix(matrix_1, n1);
    }
    else
    {
        delete_matrix(matrix_1, n1);
        if (matrix_2)
            delete_matrix(matrix_2, n2);
        return INCORRECT_KEY;
    }
    return OK;
}

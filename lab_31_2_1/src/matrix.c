#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"
#include "errors.h"

int create_matrix_from_file(const char* path_file, Matrix **matrix)
{
    FILE *f_in = fopen(path_file, "r");
    if (!f_in)
        return FILE_ERROR;

    int rows = 0;
    int columns = 0;
    int rc = OK;
    if (fscanf(f_in, "%d", &rows) != 1 || rows <= 0)
        rc = DIM_ERROR;

    if (feof(f_in))
    {
        fclose(f_in);
        return FILE_ERROR;
    }
    else if (rc != OK)
    {
        fclose(f_in);
        return rc;
    }

    if (fscanf(f_in, "%d", &columns) != 1 || columns <= 0)
    {
        fclose(f_in);
        return DIM_ERROR;
    }

    *matrix = calloc(1, sizeof(Matrix));
    if (!(*matrix))
    {
        fclose(f_in);
        return ALLOCATE_ERROR;
    }

    (*matrix)->prows = malloc(rows * sizeof(double *));
    if (!(*matrix)->prows) {
        free((*matrix));
        fclose(f_in);
        return ALLOCATE_ERROR;
    }

    (*matrix)->elements = calloc(rows * columns, sizeof(double));
    if (!(*matrix)->elements)
    {
        free((*matrix)->prows);
        free(*matrix);
        fclose(f_in);
        return ALLOCATE_ERROR;
    }

    for (int i = 0; i < rows; ++i)
        (*matrix)->prows[i] = (*matrix)->elements + i * columns;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            if (fscanf(f_in, "%d", &(*matrix)->prows[i][j]) != 1)
            {
                free_matrix(*matrix);
                fclose(f_in);
                return INPUT_ERROR;
            }

    (*matrix)->rows = rows;
    (*matrix)->columns = columns;

    fclose(f_in);
    return OK;
}

void free_matrix(Matrix* matrix)
{
    free(matrix->elements);
    matrix->elements = NULL;
    free(matrix->prows);
    matrix->prows = NULL;
    free(matrix);
}

void print_matrix(const Matrix *matrix)
{
    for (int i = 0; i < matrix->rows; ++i)
        for (int j = 0; j < matrix->columns; ++j)
        {
            if (j < matrix->columns - 1)
                printf("%d ", matrix->prows[i][j]);
            else
                printf("%d\n", matrix->prows[i][j]);
        }
}

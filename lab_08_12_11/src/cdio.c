#include <stdio.h>
#include "errors.h"
#include "cdio.h"
#include <stdlib.h>

double **create_matrix(int rows, int columns)
{
    double **matrix = calloc(rows, sizeof(double *));
    if (!matrix)
        return NULL;
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = calloc(columns, sizeof(double));
        if (!matrix[i])
        {
            delete_matrix(matrix, rows);
            return NULL;
        }
    }
    return matrix;
}

void delete_matrix(double **matrix, int n)
{
    for (int i = 0; i < n; ++i)
        free(matrix[i]);
    free(matrix);
}

int read_dimension(FILE *f, int *n, int *m)
{
    if (fscanf(f, "%d%d", n, m) != 2 || *n < 1 || *m < 1)
        return INPUT_ERROR;
    return OK;
}

double **input_matrix(char *filename, int *n, int *m, int *rc)
{
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        *rc = FILE_OPEN_ERROR;
        return NULL;
    }
    if (read_dimension(f, n, m) != OK)
    {
        fclose(f);
        *rc = INPUT_ERROR;
        return NULL;
    }
    double **matrix = create_matrix(*n, *m);
    if (!matrix)
    {
        fclose(f);
        *rc = ALLOCATE_ERROR;
        return NULL;
    }
    for (int i = 0; i < *n; ++i)
        for (int j = 0; j < *m; ++j)
            if (fscanf(f, "%lf", &matrix[i][j]) != 1)
            {
                fclose(f);
                *rc = INPUT_ERROR;
                delete_matrix(matrix, *n);
                return NULL;
            }
    fclose(f);
    return matrix;
}

int output_matrix(char *filename, double **matrix, int n, int m)
{
    FILE *f = fopen(filename, "w");
    if (!f)
        return FILE_OPEN_ERROR;
    fprintf(f, "%d %d\n", n, m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (j < m - 1)
                fprintf(f, "%lf ", matrix[i][j]);
            else
                fprintf(f, "%lf\n", matrix[i][j]);
        }
    fclose(f);
    return OK;
}


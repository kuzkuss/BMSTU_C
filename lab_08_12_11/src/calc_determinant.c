#include "calc_determinant.h"
#include "cdio.h"
#include <math.h>
#include "errors.h"

double calc_determinant(double **matrix, int n, int *rc)
{
    if (n == 1)
        return matrix[0][0];

    double res = 0.0;
    double **new_matrix = create_matrix(n - 1, n - 1);
    if (!new_matrix)
    {
        *rc = ALLOCATE_ERROR;
        return res;
    }

    for (int j = 0; j < n; ++j)
    {
        fill_new_matrix(matrix, new_matrix, n, j);
        double cur_res = calc_determinant(new_matrix, n - 1, rc);
        if (*rc)
        {
            delete_matrix(new_matrix, n - 1);
            return res;
        }
        res += matrix[0][j] * pow((-1), j + 2) * cur_res;
    }
    delete_matrix(new_matrix, n - 1);
    return res;
}

void fill_new_matrix(double **matrix, double **new_matrix, int n, int del_col)
{
    int new_i = 0;
    int new_j = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            if (j != del_col)
            {
                new_matrix[new_i][new_j] = matrix[i][j];
                if (++new_j == n - 1)
                {
                    new_j = 0;
                    ++new_i;
                }
            }
        }
}

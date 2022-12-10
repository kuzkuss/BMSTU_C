#include <stdio.h>
#include "addition.h"
#include "cdio.h"

double **addition(double **mtr1, double **mtr2, int n, int m)
{
    double **result = create_matrix(n, m);
    if (!result)
        return NULL;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result[i][j] = mtr1[i][j] + mtr2[i][j];
    return result;
}


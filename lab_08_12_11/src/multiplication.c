#include "multiplication.h"
#include "cdio.h"
#include <stdio.h>

double **multiplication(double **mtr1, double **mtr2, int n1, int m1, int m2)
{
    double **result = create_matrix(n1, m2);
    if (!result)
        return NULL;

    for (int i = 0; i < n1; ++i)
        for (int j = 0; j < m1; ++j)
            for (int row = 0; row < m2; ++row)
                result[i][row] += mtr1[i][j] * mtr2[j][row];

    return result;
}

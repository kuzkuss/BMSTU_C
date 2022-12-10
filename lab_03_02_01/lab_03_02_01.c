#include <stdio.h>
#include <stdlib.h>

#define INPUT_ERROR 1
#define MATRIX_INPUT_ERROR 2
#define INCORRECT_INPUT 3
#define EMPTY_MATRIX 4

int sum_digits(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void processing_matrix(int (*matrix)[10], int row, int col, int *imin, int *jmin)
{
    int i2 = 0, j2 = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            if (i != *imin && j != *jmin)
            {
                matrix[i2][j2] = matrix[i][j];
                j2 = (j2 + 1) % (col - 1);
            }
        if (i != *imin)
            i2 = (i2 + 1) % (row - 1);
    }
}



int search_min(int (*matrix)[10], int row, int col)
{
    int imin = 0, jmin = 0, min, current_sum;
    min = sum_digits(abs(matrix[0][0]));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            current_sum = sum_digits(abs(matrix[i][j]));
            if (current_sum < min)
            {
                min = current_sum;
                imin = i;
                jmin = j;
            }
        }
    }
    processing_matrix(matrix, row, col, &imin, &jmin);
    return 0;
}
int scan_matrix(int (*matrix)[10], int *col, int *row)
{
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *col; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
                return INPUT_ERROR;
        }
    return 0;
}

void print_matrix(int (*matrix)[10], int row, int col)
{
    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col - 1; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int row, col;
    if (scanf("%d%d", &row, &col) != 2)
        return INPUT_ERROR;

    if ((row <= 0) || (row > 10) || (col <= 0) || (col > 10))
        return INCORRECT_INPUT;
	
    if (row == 1 || col == 1)
        return EMPTY_MATRIX;

    int matrix[10][10];

    if (scan_matrix(matrix, &col, &row))
        return INPUT_ERROR;

    search_min(matrix, row, col);
    print_matrix(matrix, row, col);
    return 0;
}

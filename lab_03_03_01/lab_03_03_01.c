#include <stdio.h>
#define INPUT_ERROR 1

void sorting(int *additional_array, int row, int (*matrix)[10], int col)
{
    int av;
    int a[10];
    for (int k = 0; k < row - 1; k++)
        for (int i = 0; i < row - 1 - k; i++)
            if (additional_array[i] < additional_array[i + 1])
            {
                av = additional_array[i];
                additional_array[i] = additional_array[i + 1];
                additional_array[i + 1] = av;
                for (int j = 0; j < col; j++)
                {
                    a[j] = matrix[i][j];
                    matrix[i][j] = matrix[i + 1][j];
                    matrix[i + 1][j] = a[j];
                }
            }
}

void search_max_el(int (*matrix)[10], int row, int col, int *additional_array)
{
    int cur_max;
    for (int i = 0; i < row; i++)
    {
        cur_max = matrix[i][0];
        for (int j = 1; j < col; j++)
            if (matrix[i][j] > cur_max)
                cur_max = matrix[i][j];
        additional_array[i] = cur_max;
    }
}

int scan_array(int (*matrix)[10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
                return INPUT_ERROR;
        }
    }
    return 0;
}

void print_matrix(int (*matrix)[10], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int main(void)
{
    int row, col;
    if (scanf("%d %d", &row, &col) != 2)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    if (row <= 0 || row > 10 || col <= 0 || col > 10)
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int matrix[10][10];
    if (scan_array(matrix, row, col))
    {
        printf("Input error.");
        return INPUT_ERROR;
    }
    int additional_array[10];
    search_max_el(matrix, row, col, additional_array);
    sorting(additional_array, row, matrix, col);
    print_matrix(matrix, row, col);
    return 0;
}
